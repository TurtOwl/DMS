
#ifndef TABLET_H
#define TABLET_H

#include "Device.h"
#include <string>

class Tablet : public Device {
private:
    double screenSize;
    bool hasPen;

public:
    Tablet(int id, const std::string& name, double screenSize, bool hasPen);

    void PrintInfo() const override;
};

#endif