#include <iostream>
#include <cassert>
#include <memory>
#include "TransportClasses.h"
#include "Queue.h"

void testCarTurbo() {
    Car myCar("Tesla", 777, "Electric", 100, 2000, 5, 500);
    myCar.turboBoost();
    // перевіряємо, чи швидкість зросла на 20%
    std::cout << "Test Car Turbo: Manual check needed (speed should be 120)\n";
}

void testLinkedListQueue() {
    LinkedListQueue queue;
    auto car = std::make_shared<Car>("TestCar", 1, "Gas", 50, 1000, 4, 100);
    queue.insert(car);
    assert(!queue.empty());
    auto popped = queue.pop();
    assert(popped->getPriority() == car->getPriority());
    assert(queue.empty());
    std::cout << "Test LinkedListQueue: PASSED\n";
}

void testPriority() {
    // перевірка логіки пріоритетів
    Bicycle bike("Cube", 12, 20, 15);
    assert(bike.getPriority() == 20);
    std::cout << "Test Priority: PASSED\n";
}

int main() {
    std::cout << "--- Running Unit Tests ---\n";
    testLinkedListQueue();
    testPriority();
    testCarTurbo();
    std::cout << "--- All tests completed ---\n";
    return 0;
}
