
#ifndef PHONE_H
#define PHONE_H

#include "Device.h"
#include <string>

class Phone : public Device {
private:
    std::string model;
    std::string serialNumber;
    std::string phoneType;

    static int countCreated;

public:
    Phone(int id, const std::string& name, const std::string& model, const std::string& serialNumber, const std::string& phoneType);

    void PrintInfo() const override;

    static int GetCreatedCount();

    bool operator==(const Phone& other) const;
};

#endif