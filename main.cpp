#include <iostream>
#include <vector>
#include <memory>
#include "TransportClasses.h"
#include "TransportFactory.h"

int main() {
    std::vector<std::shared_ptr<Transport>> fleet;

    fleet.push_back(TransportFactory::createTransport("Car", "Tesla", 777, 200, 2000));
    fleet.push_back(TransportFactory::createTransport("Plane", "Boeing", 101, 800, 50000));
    fleet.push_back(TransportFactory::createTransport("Bicycle", "Pride", 12, 25, 15));

    std::cout << "--- Our Refactored Fleet ---\n";
    for (const auto& vehicle : fleet) {
        vehicle->printInfo();
        vehicle->performSpecialAction1(); 
        std::cout << "--------------------------\n";
    }

    return 0;
}
