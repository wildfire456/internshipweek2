#include <iostream>
#include <string>
using namespace std;

// parent class
class Vehicle
 {
public:
    string make;
    string model;

    Vehicle(string make, string model)
     {
        this->make = make;
        this->model = model;
    }

    virtual void displayInfo() 
    {
        cout << "Make: " << make << ", Model: " << model;
    }
};


//derived class
class Car : public Vehicle 
{
public:
    int numDoors;
    string vehicle_type;

    Car(string make, string model, int numDoors, string v_t) : Vehicle(make, model)
     {
        this->numDoors = numDoors;
        this->vehicle_type = v_t;
    }

    void displayInfo() override  // polymorphism
     {
        cout << "Make: " << make << endl<<"Model: " << model << endl <<"Number of doors: " << numDoors << endl <<"Vehicle Type: "<<vehicle_type<<endl;
    }
};

int main() {
    Car myCar("Toyota", "Altis", 4 , "Sedan");
    Vehicle* vehiclePtr = &myCar;

    vehiclePtr->displayInfo();

    return 0;
}

