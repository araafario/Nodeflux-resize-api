#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <crow.h>
#include <crow/json.h>
#include <base64.h>

using namespace cv;
using namespace std;


class CrowApp{
    public:
        void mainRoute();
        void test();
        void runServer(int port);

    private:
        crow::SimpleApp app; 
        std::string base64_resize_image(const std::string& base64img, int image_width, int image_height);
};

string CrowApp::base64_resize_image(const std::string& base64img, int image_width, int image_height){
    string decoded_data = base64_decode(base64img);
            
    vector<uchar> data(decoded_data.begin(), decoded_data.end());
    Mat img = imdecode(data, IMREAD_UNCHANGED);

    cv::resize(img, img, cv::Size(image_width, image_height));

    // Encode the resized image to JPEG and then to base64
    std::vector<uchar> encoded_data;
    imencode(".jpg", img, encoded_data);
    
    return base64_encode(encoded_data.data(), encoded_data.size());
}

void CrowApp::runServer(int port){
    app.port(port).multithreaded().run();
}

void CrowApp::mainRoute(){
    CROW_ROUTE(app, "/resize_image").methods(crow::HTTPMethod::POST)([this](const crow::request& req){
        try {
            auto json = crow::json::load(req.body);
            if (!json) {
                throw std::runtime_error("Request is not a JSON !");
            }

            string input_jpeg = json["input_jpeg"].s();

            if (input_jpeg.empty()) {
                throw std::runtime_error("Image is empty");
            }

            string output_jpeg = this->base64_resize_image(input_jpeg, json["desired_width"].i(), json["desired_height"].i());

            // // Create success response JSON
            crow::json::wvalue success_response;
            success_response["code"] = 200;
            success_response["message"] = "success";
            success_response["output_jpeg"] = output_jpeg; 

            return crow::response(200, success_response);
        } catch (const std::exception& e) {
            // Create error response JSON
            crow::json::wvalue error_response;
            error_response["code"] = 400;
            error_response["Message"] = e.what();

            return crow::response(400, error_response);
        }   
    });
}

void CrowApp::test(){
    //Not implemented yet
}


int main(int argc, char *argv[])
{
    CrowApp crowApp;
    crowApp.mainRoute();

    if (argc > 1 && (string(argv[1]) == "--test" || string(argv[1]) == "-test") ) {
        cout << "Running tests..." << endl;
        crowApp.test();
    } else {
        // Run normal program
        crowApp.runServer(8080);
    }

    return 0;
}

