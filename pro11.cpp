#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Reservation
{
private:
    int reservationId;
    string passengerName;
    string trainName;
    string ticketType;
    double fare;
    int passengers;

    static int totalReservations;

public:
    // Default constructor
    Reservation();

    // Parameterized constructor
    Reservation(int id, string passenger, string train,
                string type, double f, int p);

    // Destructor
    ~Reservation();

    // Display reservation
    void displayReservation();

    // Function overloading
    double calculateFare();
    double calculateFare(int p);
    double calculateFare(int p, double discount);

    // Reference parameter
    void updatePassengers(int &p);

    // Static member function
    static int getTotalReservations();

    // Friend function
    friend double calculateTotalRevenue(
        Reservation r[], int n);
};


// Static member
int Reservation::totalReservations = 0;


// Default constructor
Reservation::Reservation()
{
    reservationId = 0;
    passengerName = "";
    trainName = "";
    ticketType = "";
    fare = 0.0;
    passengers = 0;
}


// Parameterized constructor
Reservation::Reservation(int id, string passenger,
                         string train, string type,
                         double f, int p)
{
    reservationId = id;
    passengerName = passenger;
    trainName = train;
    ticketType = type;
    fare = f;
    passengers = p;

    totalReservations++;
}


// Destructor
Reservation::~Reservation()
{
}


// Display reservation
void Reservation::displayReservation()
{
    cout << fixed << setprecision(2);

    cout << "Reservation ID: " << reservationId << endl;
    cout << "Passenger Name: " << passengerName << endl;
    cout << "Train Name: " << trainName << endl;
    cout << "Ticket Type: " << ticketType << endl;
    cout << "Fare: " << fare << endl;
    cout << "Passengers: " << passengers << endl;
    cout << "Total Fare: " << calculateFare() << endl;
}


// Function overloading
double Reservation::calculateFare()
{
    return fare * passengers;
}


double Reservation::calculateFare(int p)
{
    return fare * p;
}


double Reservation::calculateFare(int p, double discount)
{
    double basicFare = fare * p;
    double discountAmount = basicFare * discount / 100.0;

    return basicFare - discountAmount;
}


// Reference parameter
void Reservation::updatePassengers(int &p)
{
    passengers = p;
}


// Static member function
int Reservation::getTotalReservations()
{
    return totalReservations;
}


// Friend function
double calculateTotalRevenue(Reservation r[], int n)
{
    double revenue = 0.0;

    for (int i = 0; i < n; i++)
    {
        revenue += r[i].fare * r[i].passengers;
    }

    return revenue;
}


int main()
{
    int n;
    cin >> n;

    if (n < 1 || n > 10)
        return 0;

    cout << fixed << setprecision(2);

    // Array of objects
    Reservation reservations[10];

    for (int i = 0; i < n; i++)
    {
        int id;
        string passenger;
        string train;
        string type;
        double fare;
        int passengers;

        cin >> id;
        cin >> passenger;
        cin >> train;
        cin >> type;
        cin >> fare;
        cin >> passengers;

        // Create reservation using parameterized constructor
        reservations[i] = Reservation(
            id, passenger, train, type, fare, passengers
        );
    }

    // Display all reservations
    for (int i = 0; i < n; i++)
    {
        reservations[i].displayReservation();

        if (i < n - 1)
        {
            cout << endl;
        }
    }

    // Calculate and display total railway revenue
    cout << "Total Railway Revenue: "
         << calculateTotalRevenue(reservations, n) << endl;

    // Display total number of reservations
    cout << "Total Reservations: "
         << Reservation::getTotalReservations() << endl;

    // Pointer to object
    if (n > 0)
    {
        Reservation *ptr = &reservations[0];

        // Access reservation using pointer without extra output
        double total = ptr->calculateFare();
        (void)total;
    }

    return 0;
}
