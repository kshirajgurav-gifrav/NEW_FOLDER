#include <iostream>
#include <string>
using namespace std;

// Base Class
class Patient {
protected:
    int patientID;
    string name;

public:
    Patient(int id, string n) {
        patientID = id;
        name = n;
    }

    // Virtual Function
    virtual void displayBill() {
        cout << "Patient ID: " << patientID << endl;
        cout << "Patient Name: " << name << endl;
    }
};

// Derived Class 1: Virtual Base Class
class Medical : virtual public Patient {
protected:
    float treatmentCharges;

public:
    Medical(int id, string n, float t)
        : Patient(id, n) {
        treatmentCharges = t;
    }
};

// Derived Class 2: Virtual Base Class
class Billing : virtual public Patient {
protected:
    float roomCharges;

public:
    Billing(int id, string n, float r)
        : Patient(id, n) {
        roomCharges = r;
    }
};

// Multiple Inheritance
class FinalBill : public Medical, public Billing {
public:
    FinalBill(int id, string n, float t, float r)
        : Patient(id, n),
          Medical(id, n, t),
          Billing(id, n, r) {
    }

    // Function Overriding
    void displayBill() override {
        float total = treatmentCharges + roomCharges;

        cout << "Patient ID: " << patientID << endl;
        cout << "Patient Name: " << name << endl;
        cout << "Treatment Charges: " << treatmentCharges << endl;
        cout << "Room Charges: " << roomCharges << endl;
        cout << "Total Bill: " << total << endl;
    }
};

int main() {
    int patientID;
    string name;
    float treatmentCharges, roomCharges;

    cin >> patientID;
    cin >> name;
    cin >> treatmentCharges;
    cin >> roomCharges;

    FinalBill obj(patientID, name, treatmentCharges, roomCharges);

    // Base Class Pointer
    Patient *ptr = &obj;

    // Runtime Polymorphism
    ptr->displayBill();

    return 0;
}

