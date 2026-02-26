#include <iostream>
#include <cassert>
#include <memory>
#include "TransportClasses.h"
#include "Queue.h"

void testCarTurbo() {
    Car myCar("Tesla", 777, "Electric", 100.0, 2000.0, 5, 500.0);
    
    myCar.performSpecialAction1();

    assert(myCar.getSpeed() == 120.0);
    std::cout << "Test Car Turbo: PASSED (Speed is 120)\n";
}

void testLinkedListQueue() {
    LinkedListQueue queue;
    auto car = std::make_shared<Car>("TestCar", 1, "Gas", 50.0, 1000.0, 4, 100.0);
    queue.insert(car);
    assert(!queue.empty());
    
    auto popped = queue.pop();
    assert(popped->getPriority() == car->getPriority());
    assert(queue.empty());
    std::cout << "Test LinkedListQueue: PASSED\n";
}

void testPriority() {
    Bicycle bike("Cube", 12, 20.0, 15.0);
    assert(bike.getPriority() == 20);

    Car car("Tesla", 777, "Electric", 100.0, 2000.0, 5, 500.0);
    assert(car.getPriority() == 150);
    
    std::cout << "Test Priority: PASSED\n";
}

int main() {
    std::cout << "\n--- Running Refactored Unit Tests ---\n";
    testCarTurbo();
    testLinkedListQueue();
    testPriority();
    std::cout << "--- All tests completed successfully! ---\n";
    return 0;
}
