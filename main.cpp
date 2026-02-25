#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "TransportClasses.h"

void showMenu() {
    cout << "\n--- Transport Manager 2026 ---\n";
    cout << "1 - Show all transports\n";
    cout << "2 - Perform Special Action (Honk/Turbo/etc)\n";
    cout << "0 - Exit\nChoice: ";
}

int main() {
    vector<shared_ptr<Transport>> transports;

    transports.push_back(make_shared<Car>("Tesla Model S", 101, "Electric", 250, 2100, 5, 1020));
    transports.push_back(make_shared<Bicycle>("Giant", 202, 30, 12));

    int choice;
    while(true){
        showMenu();
        cin >> choice;
        if(choice == 0) break;

        if(choice == 1) {
            for(const auto& t : transports) t->printInfo();
        } 
        else if(choice == 2) {
            int idx;
            cout << "Enter index (0-" << transports.size()-1 << "): ";
            cin >> idx;
            if(idx >= 0 && idx < transports.size()) {
                transports[idx]->performSpecialAction1();
            }
        }
    }
    return 0;
}
