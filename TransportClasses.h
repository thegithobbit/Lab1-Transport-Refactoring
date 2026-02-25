#ifndef TRANSPORTCLASSES_H
#define TRANSPORTCLASSES_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Transport {
protected:
    string type;
    string name;
    int number;
    string fuel;
    double speed;
    double weight;

public:
    Transport(string t, string n, int num, string f, double s, double w)
        : type(t), name(n), number(num), fuel(f), speed(s), weight(w) {}

    virtual ~Transport() {}

    double getSpeed() const { return speed; }
    string getName() const { return name; }
    virtual int getPriority() const { return static_cast<int>(speed); }

    virtual void printInfo() const {
        cout << "Type: " << type << ", Name: " << name << ", Num: " << number
             << ", Fuel: " << fuel << ", Speed: " << speed << ", Weight: " << weight << endl;
    }

    // застосуємо поліморфні методи замість dynamic_cast
    virtual void performSpecialAction1() { honk(); } // Основна дія
    virtual void performSpecialAction2() { cout << name << " performs default action.\n"; }

    virtual void honk() const { cout << name << " honks!\n"; }
};

class Car : public Transport {
    double enginePower;
public:
    Car(string n, int num, string f, double s, double w, int p, double ep)
        : Transport("Car", n, num, f, s, w), enginePower(ep) {}

    void printInfo() const override {
        Transport::printInfo();
        cout << "Engine Power: " << enginePower << " HP\n";
    }

    void performSpecialAction1() override { turboBoost(); }
    void performSpecialAction2() override { drift(); }

    void turboBoost() { speed *= 1.2; cout << name << " activated turbo! Speed: " << speed << endl; }
    void drift() { cout << name << " is drifting!\n"; }
    
    int getPriority() const override { return static_cast<int>(speed + enginePower/10); }
};

#endif
