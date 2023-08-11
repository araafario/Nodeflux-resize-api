# Nodeflux - Resize Image API

C++ Image resizing API using Crow and OpenCV

## Dependencies

Required : 

* OpenCV

Included : 

* Crow
* Asio
* Base64 (modified)

## Usage

Specify port 
```javascript
crowApp.runServer(8080);
```


JSON Post Request
```javascript
{
    "input_jpeg": "/9j/4AAQSkZJRgABAQAAAQABAAD/2wBDAAIBAQEBAQIBAQECAgICAgQDAgICAgUEBAMEBgUGBgYFBgYGBwkIBgcJBwYGCAsICQoKCgoKBggLDAsKDAkKCgr/2wBDAQICAgICAgUDAwUKBwYHCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgr/wAARCAAgACADASIAAhEBAxEB/8QAHwAAAQUBAQEBAQEAAAAAAAAAAAECAwQFBgcICQoL/8QAtRAAAgEDAwIEAwUFBAQAAAF9AQIDAAQRBRIhMUEGE1FhByJxFDKBkaEII0KxwRVS0fAkM2JyggkKFhcYGRolJicoKSo0NTY3ODk6Q0RFRkdISUpTVFVWV1hZWmNkZWZnaGlqc3R1dnd4eXqDhIWGh4iJipKTlJWWl5iZmqKjpKWmp6ipqrKztLW2t7i5usLDxMXGx8jJytLT1NXW19jZ2uHi4+Tl5ufo6erx8vP09fb3+Pn6/8QAHwEAAwEBAQEBAQEBAQAAAAAAAAECAwQFBgcICQoL/8QAtREAAgECBAQDBAcFBAQAAQJ3AAECAxEEBSExBhJBUQdhcRMiMoEIFEKRobHBCSMzUvAVYnLRChYkNOEl8RcYGRomJygpKjU2Nzg5OkNERUZHSElKU1RVVldYWVpjZGVmZ2hpanN0dXZ3eHl6goOEhYaHiImKkpOUlZaXmJmaoqOkpaanqKmqsrO0tba3uLm6wsPExcbHyMnK0tPU1dbX2Nna4uPk5ebn6Onq8vP09fb3+Pn6/9oADAMBAAIRAxEAPwD+f+v1j/4JQ/8ABtrP+3V+zZoX7R/7S/xFvvhroWrX082hppdsLjUNe09lTypnSY+XZLuSVo2Idp43D7FQRyS/Iv8AwTK/Y5+CX7WY+IzfGa68Rx/8I1oEE2iDw/qcFti5lMo3y+bBL5iL5Y+QbM7vvcV+5H7EWhftLfE34SeCPA3wK1qwngsfBWlw29gPCcjJZwx2cajfP9vjjRflwuQvYDJ6/lnHvFWZYRxy7J21iOZJuze8eZKKs7366adNdVy1q8oSUYK7PzT/AOCq/wDwb7WP7BvwP1/44fADxvqvxE0SwvrZNRk1W2EFxoNtiRpJB5H7u7ZsJkkJ5UaStsfJki/Lo8Gv6NP+Cj3gz9pz4d/DHxf4L+NWo6Zai58M33mWknhaULdRNA4JjmF88brzgkBscg4Oa/H/AP4Ku/snfAf9lXxL8PdM+BmkapZRaz4REusLqeqm6a4uYyitPkquxnLElVwgwNqrzl8B8TZnWgsuziTliHKSTas/dim1JWjay2stevdrD1py92e5T/4Jj/tUfCX9me88fj4ra9Pp8ev6HBHpzxWUs4lliaTMf7tSVJEnBOBweRxn93v+CT37S/7PHgn9mi28KfFjU5IZNb8J6dceGfE1luKWVwtmYgUuYG861kbzhiVMKFV97oOv8vI619U/s+fth+DvhF+xprngPTviN4l0bxzBe3J0ODTJJlhmWZV2MGU+Wuxt7Hdg/wB3dnFe3nmQ1Y5nTzTBa1XJKSa5o25XC9lZpJPV3ZdSm1NTjuft7/wWL/aT/Z0+IHwKbwh8Fbqe4Xw74S1ifxP4muo32ahctZpHlrm4Yz3cii3IMz7lZWTZI46fiD/wVK/at+Ef7Uvi/wAD6j8ItXur220XwuIb97mxeDyp3ZSYsOAWZduCVynI2s3Wof2sv2v9C+NP7M/hHwZZ/FrxPrfiOW5iuPE9nqTzLDbmKJ0KMWISTdIwddm4YXLbWwK+Xa3ybJJ1Mc8zxmlZOSSS5UlZQ2d27qN0x06bcueW5//Z",
    "desired_width": 16,
    "desired_height": 16
}
```

JSON Response
```javascript
{
    "message": "success",
    "code": 200,
    "output_jpeg": "/9j/4AAQSkZJRgABAQAAAQABAAD/2wBDAAIBAQEBAQIBAQECAgICAgQDAgICAgUEBAMEBgUGBgYFBgYGBwkIBgcJBwYGCAsICQoKCgoKBggLDAsKDAkKCgr/2wBDAQICAgICAgUDAwUKBwYHCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgoKCgr/wAARCAAIAAgDASIAAhEBAxEB/8QAHwAAAQUBAQEBAQEAAAAAAAAAAAECAwQFBgcICQoL/8QAtRAAAgEDAwIEAwUFBAQAAAF9AQIDAAQRBRIhMUEGE1FhByJxFDKBkaEII0KxwRVS0fAkM2JyggkKFhcYGRolJicoKSo0NTY3ODk6Q0RFRkdISUpTVFVWV1hZWmNkZWZnaGlqc3R1dnd4eXqDhIWGh4iJipKTlJWWl5iZmqKjpKWmp6ipqrKztLW2t7i5usLDxMXGx8jJytLT1NXW19jZ2uHi4+Tl5ufo6erx8vP09fb3+Pn6/8QAHwEAAwEBAQEBAQEBAQAAAAAAAAECAwQFBgcICQoL/8QAtREAAgECBAQDBAcFBAQAAQJ3AAECAxEEBSExBhJBUQdhcRMiMoEIFEKRobHBCSMzUvAVYnLRChYkNOEl8RcYGRomJygpKjU2Nzg5OkNERUZHSElKU1RVVldYWVpjZGVmZ2hpanN0dXZ3eHl6goOEhYaHiImKkpOUlZaXmJmaoqOkpaanqKmqsrO0tba3uLm6wsPExcbHyMnK0tPU1dbX2Nna4uPk5ebn6Onq8vP09fb3+Pn6/9oADAMBAAIRAxEAPwD4Nbxp/wAEoI/+COlt4JNpaP8AFgXEpmuR4SX+2G1VrN5E3akqB/souQFFuT5PkruOZsklFFeVleDhhFV5ZSfNOTd23r5diIK1z//Z"
}
```

Adding Test Case
```bash
request = "POST /resize_image HTTP/1.1\r\n"
            "Host: localhost\r\n"
            "Connection: close\r\n"
            "Content-Type: application/json\r\n"
            "Content-Length: " + std::to_string(strlen("{\"input_jpeg\": \"\", \"desired_width\": 32, \"desired_height\": 32}")) + "\r\n"
            "\r\n"
            "{\"input_jpeg\": \"\", \"desired_width\": 32, \"desired_height\": 32}";
testCase(request,"400");
```

Running Test Case
```bash
./opencvapi --test
```


## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.
