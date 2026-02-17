// Device.h
#ifndef DEVICE_H
#define DEVICE_H

#include <string>

class Device {
protected:
    int id;
    std::string name;

public:
    Device(int id, const std::string& name);
    virtual ~Device() = default;

    int getId() const;
    std::string getName() const;

    virtual void PrintInfo() const = 0;
};

#endif // DEVICE_H