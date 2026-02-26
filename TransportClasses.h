#ifndef TRANSPORTCLASSES_H
#define TRANSPORTCLASSES_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
    string getType() const { return type; }
    
    virtual int getPriority() const { return static_cast<int>(speed); }

    virtual void printInfo() const {
        cout << "Type: " << type << ", Name: " << name << ", Num: " << number
             << ", Fuel: " << fuel << ", Speed: " << speed << ", Weight: " << weight << endl;
    }

    virtual void performSpecialAction1() { honk(); }
    virtual void performSpecialAction2() { cout << name << " is maintaining its route.\n"; }

    virtual void honk() const { cout << name << " honks!\n"; }
};

class LandTransport : public Transport {
protected:
    int wheels;
    int passengers;

public:
    LandTransport(string t, string n, int num, string f, double s, double w, int wh, int p)
        : Transport(t, n, num, f, s, w), wheels(wh), passengers(p) {}

    void printInfo() const override {
        Transport::printInfo();
        cout << "Wheels: " << wheels << ", Passengers: " << passengers << endl;
    }
};

class Car : public LandTransport {
    double enginePower;
public:
    Car(string n, int num, string f, double s, double w, int p, double ep)
        : LandTransport("Car", n, num, f, s, w, 4, p), enginePower(ep) {}

    void performSpecialAction1() override { 
        speed *= 1.2; 
        cout << name << " activated Turbo! New speed: " << speed << endl; 
    }
    void performSpecialAction2() override { cout << name << " is drifting!\n"; }
    int getPriority() const override { return static_cast<int>(speed + enginePower/10); }
};

class Bus : public LandTransport {
    double routeLength;
public:
    Bus(string n, int num, string f, double s, double w, int p, double rl)
        : LandTransport("Bus", n, num, f, s, w, 6, p), routeLength(rl) {}

    void performSpecialAction1() override { cout << name << " doors opened for passengers.\n"; }
    void performSpecialAction2() override { cout << name << " announces: Next stop is University.\n"; }
    int getPriority() const override { return passengers; }
};

class Plane : public Transport {
    double wingspan;
    double maxAltitude;
public:
    Plane(string n, int num, string f, double s, double w, double ws, double ma)
        : Transport("Plane", n, num, f, s, w), wingspan(ws), maxAltitude(ma) {}

    void performSpecialAction1() override { cout << name << " is taking off into the clouds!\n"; }
    void performSpecialAction2() override { cout << name << " reached altitude: " << maxAltitude << "m\n"; }
    int getPriority() const override { return static_cast<int>(speed + maxAltitude/1000); }
};

class Boat : public Transport {
    double length;
    double draft;
public:
    Boat(string n, int num, string f, double s, double w, double l, double d)
        : Transport("Boat", n, num, f, s, w), length(l), draft(d) {}

    void performSpecialAction1() override { cout << name << " is docking at the pier.\n"; }
    void performSpecialAction2() override { cout << name << " is sailing across the lake.\n"; }
};

class Truck : public LandTransport {
    double cargoCapacity;
public:
    Truck(string n, int num, string f, double s, double w, int p, double cc)
        : LandTransport("Truck", n, num, f, s, w, 6, p), cargoCapacity(cc) {}

    void performSpecialAction1() override { cout << name << " is loading " << cargoCapacity << " tons of cargo.\n"; }
    int getPriority() const override { return static_cast<int>(cargoCapacity + speed/2); }
};

class Bicycle : public LandTransport {
public:
    Bicycle(string n, int num, double s, double w)
        : LandTransport("Bicycle", n, num, "None", s, w, 2, 1) {}

    void performSpecialAction1() override { cout << name << " is pedaling hard!\n"; }
    void performSpecialAction2() override { cout << name << " rings the bell: Ring-ring!\n"; }
};

class Train : public LandTransport {
    int carriages;
public:
    Train(string n, int num, string f, double s, double w, int p, int c)
        : LandTransport("Train", n, num, f, s, w, 12, p), carriages(c) {}

    void performSpecialAction1() override { cout << name << " is departing from the station.\n"; }
    int getPriority() const override { return passengers + carriages; }
};

#endif
