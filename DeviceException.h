#ifndef DEVICEEXCEPTION_H
#define DEVICEEXCEPTION_H

#include <exception>
#include <string>

class DeviceException : public std::exception {
private:
    std::string message;
public:
    explicit DeviceException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif