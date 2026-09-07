/*
Abstraction means:
- showing only the essential behavior
- hiding the internal implementation details

For example, a user of a car only cares about:
- start the car
- stop the car
- get the speed
They do not need to know how the engine works.
*/

#include <iostream>
#include <string>
using namespace std;

// Abstract class
// It defines a common interface for all cars.
class Car {
public:
    // Pure virtual functions:
    // Any derived class must implement these methods.
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual int getSpeed() = 0;

    // Function overloading example:
    // Same function name, different parameter list.
    virtual int accelerate(int increment) = 0;
    virtual int accelerate() = 0;

    // Virtual destructor:
    // Important when deleting a derived object through a base pointer.
    virtual ~Car() {}
};

// Derived class
// Tesla inherits from Car and provides the actual implementation.
class Tesla : public Car {
private:
    // Encapsulation:
    // Private data can only be accessed through public methods.
    string carNumber;

public:
    string model;
    string color;

    // Constructor with default values.
    Tesla(string m = "Model S", string c = "Red") : model(m), color(c) {}

    // Alternative constructor style:
    // Tesla(string m, string c) {
    //     model = m;
    //     color = c;
    // }

    // Getter and setter for the private field.
    void setCarNumber(string num) {
        carNumber = num;
    }

    string getCarNumber() {
        return carNumber;
    }

    // Overriding the abstract functions from Car.
    void start() override {
        cout << "Tesla started." << endl;
    }

    void stop() override {
        cout << "Tesla stopped." << endl;
    }

    int getSpeed() override {
        return 120; // Example speed
    }

    // Overloaded functions:
    // Same name, different parameter list.
    int accelerate(int increment) override {
        return 120 + increment;
    }

    int accelerate() override {
        return 120;
    }
};

int main() {
    // Polymorphism example:
    // Base class pointer points to a derived object.
    Car* mycar = new Tesla();
    mycar->start();
    cout << "Current speed: " << mycar->getSpeed() << " km/h" << endl;
    cout << "Accelerate default: " << mycar->accelerate() << " km/h" << endl;
    cout << "Accelerate +10: " << mycar->accelerate(10) << " km/h" << endl;
    mycar->stop();
    delete mycar;

    // Another Tesla object with different values.
    Car* mycar2 = new Tesla("Model 3", "Blue");
    mycar2->start();
    cout << "Current speed: " << mycar2->getSpeed() << " km/h" << endl;
    mycar2->stop();
    delete mycar2;

    // Encapsulation example:
    Tesla myTesla("Model Y", "White");
    myTesla.setCarNumber("DL-01-2025");
    myTesla.model = "Model X";
    myTesla.color = "Black";

    cout << "Model: " << myTesla.model << ", Color: " << myTesla.color << endl;
    cout << "Car Number: " << myTesla.getCarNumber() << endl;

    return 0;
}