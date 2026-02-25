#ifndef TRANSPORTFACTORY_H
#define TRANSPORTFACTORY_H

#include <memory>
#include <string>
#include "TransportClasses.h"

class TransportFactory {
public:
    static std::shared_ptr<Transport> createTransport(
        const std::string& type, 
        const std::string& name, 
        int number, 
        double speed, 
        double weight) 
    {
        if (type == "Car") 
            return std::make_shared<Car>(name, number, "Petrol", speed, weight, 5, 150.0);
        if (type == "Bus") 
            return std::make_shared<Bus>(name, number, "Diesel", speed, weight, 40, 50.5);
        if (type == "Plane") 
            return std::make_shared<Plane>(name, number, "Kerosene", speed, weight, 35.0, 10000.0);
        if (type == "Boat") 
            return std::make_shared<Boat>(name, number, "Diesel", speed, weight, 20.0, 5.0);
        if (type == "Truck") 
            return std::make_shared<Truck>(name, number, "Diesel", speed, weight, 2, 20.0);
        if (type == "Bicycle") 
            return std::make_shared<Bicycle>(name, number, speed, weight);
        if (type == "Train") 
            return std::make_shared<Train>(name, number, "Electric", speed, weight, 500, 10);

        return nullptr;
    }
};

#endif
