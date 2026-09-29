#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
private:
    int vehicleId;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    Vehicle()
    {
        vehicleId = 0;
        manufacturer = "";
        model = "";
        year = 0;

        totalVehicles++;
    }

    Vehicle(int id, string mu, string mod, int y)
    {
        vehicleId = id;
        manufacturer = mu;
        model = mod;
        year = y;

        totalVehicles++;
    }
    ~Vehicle()
    {
        totalVehicles--;
    }

    void set_VehicleId(int id)
    {
        vehicleId = id;
    }
    void set_Manufacturer(string mu)
    {
        manufacturer = mu;
    }
    void set_Model(string mod)
    {
        model = mod;
    }
    void set_Year(int y)
    {
        year = y;
    }
    int get_VehicleId()
    {
        return vehicleId;
    }
    string get_Manufacturer()
    {
        return manufacturer;
    }
    string get_Model()
    {
        return model;
    }
    int get_Year()
    {
        return year;
    }
    int get_TotalVehicles()
    {
        return totalVehicles;
    }

    void display()
    {
        cout << "\n======= The vehicle datails ======= \n"
             << endl;
        cout << " The Vehicle ID is: " << vehicleId << endl;
        cout << " The vehicle Manufacturer is: " << manufacturer << endl;
        cout << " The vehicle Model is: " << model << endl;
        cout << "The vehicle Year is: " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle

{
private:
    string fueltype;

public:
    Car() : Vehicle()
    {
        fueltype = "";
    }

    Car(int id, string mu, string mod, int y, string fule) : Vehicle(id, mu, mod, y)
    {
        fueltype = fule;
    }
    void set_fule(string fule)
    {
        fueltype = fule;
    }

    string get_fuletype()
    {
        return fueltype;
    }
    void displayCar()
    {
        Vehicle::display();
        cout << "The fule type is" << fueltype << endl;
    }
};

class ElectricCar : public Car
{
private:
    int batteryCapacity;

public:
    ElectricCar() : Car()
    {
        batteryCapacity = 0;
    }
    ElectricCar(int id, string mu, string mod, int y, string fule, int bc) : Car(id, mu, mod, y, fule)
    {
        batteryCapacity = bc;
    }
    void set_bc(int bc)
    {
        batteryCapacity = bc;
    }
    int get_bc()
    {
        return batteryCapacity;
    }
    void displayElectricCar()
    {
        Car::displayCar();
        cout << "The battery capacity is: " << batteryCapacity << endl;
    }
};
class Aircraft
{
private:
    int flightRange;

public:
    Aircraft()
    {
        flightRange = 0;
    }
    Aircraft(int range)
    {
        flightRange = range;
    }
    void set_range(int range)
    {

        flightRange = range;
    }
    int get_range()
    {
        return flightRange;
    }
    void dispalayAircraft()
    {
        cout << "The flightRange is " << flightRange << endl;
    }
};

class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar(int id, string mu, string mod, int y, string fule, int bc, int range) : Car(id, mu, mod, y, fule), Aircraft(range)
    {
    }

    void displayFlyingCar()
    {
        Car::displayCar();
        Aircraft::dispalayAircraft();
    }
};

class SportsCar : public ElectricCar
{
private:
    int topSpeed;

public:
    SportsCar() : ElectricCar()
    {
        topSpeed = 0;
    }
    SportsCar(int id, string mu, string mod, int y, string fule, int bc, int tp) : ElectricCar(id, mu, mod, y, fule, bc)
    {
        topSpeed = tp;
    }
    void set_tp(int tp)
    {
        topSpeed = tp;
    }
    int get_tp()
    {
        return topSpeed;
    }
    void displaySportsCar()
    {
        ElectricCar::displayElectricCar();
        cout << "The topspeed is" << topSpeed << endl;
    }
};

class Sedan : public Car
{
public:
    Sedan(int id, string mu, string mod, int y, string fuel) : Car(id, mu, mod, y, fuel) {}
    void displaySedan()
    {
        Car::displayCar();
        cout << "Vehicle Type : Sedan" << endl;
    }
};
class SUV : public Car
{
public:
    SUV(int id, string mu, string mod, int y, string fuel) : Car(id, mu, mod, y, fuel) {}
    void displaySUV()
    {
        Car::displayCar();
        cout << "Vehicle Type : SUV" << endl;
    }
};

class VehicleRegistry
{
public:
    Vehicle v[100];
    int count = 0;

    void add_new_Vehicle(Vehicle vehicle)
    {
        v[count] = vehicle;
        count++;
    }
    void dispaly_vehicle()
    {
        for (int i = 0; i < count; i++)
        {
            v[i].display();
        }
    }
    void search_vehicle(int id)
    {

        for (int i = 0; i < count; i++)
        {
            if (v[i].get_VehicleId() == id)
            {
                v[i].display();
            }
        }
    }
};

int main()
{
    VehicleRegistry registry;
    int choice;
    do
    {
        cout << "\n======= Vehicle registry operations ======= \n"
             << endl;
        cout << "1. Add a vehicle(different types)" << endl;
        cout << "2. View all vehicles" << endl;
        cout << "3. Search vehicle by id" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice between (1-4): ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\n======= select vehicle  type ======= \n";

            cout << "1.Add new car" << endl;
            cout << "2.Add new electric car" << endl;
            cout << "3.Add new flying car" << endl;
            cout << "4.Add new sports car" << endl;
            cout << "5.Add new sedan car" << endl;
            cout << "6.Add new SUV car" << endl;

            int cartype;
            cout << "Enter your choice between (1-6): ";
            cin >> cartype;

            int vehicleId, year;
            string manufacturer, model;
            cout << "Enter  the vehicle ID: ";
            cin >> vehicleId;

            cout << "Enter the manufacturer: ";
            cin >> manufacturer;

            cout << "Enter the model: ";
            cin >> model;

            cout << "Enter the year:";
            cin >> year;

            if (cartype == 1)
            {
                string fuel;
                cout << "Enter the fuel type: ";
                cin >> fuel;
                cout << "\n======= Add new car ======= \n";
                Car car(vehicleId, manufacturer, model, year, fuel);
                registry.add_new_Vehicle(car);
            }

            else if (cartype == 2)
            {
                cout << "\n======= Add new electric car ======= \n";
            }
            else if (cartype == 3)
            {
                cout << "\n======= Add new flying car ======= \n";
            }
            else if (cartype == 4)
            {
                cout << "\n======= Add new sports car ======= \n";
            }
            else if (cartype == 5)
            {
                cout << "\n======= Add new sedan car ======= \n";
            }
            else if (cartype == 6)
            {
                cout << "\n======= Add new SUV car ======= \n";
            }

            else
            {
                cout << "invalid choice ..." << endl;
            }
        }
        else if (choice == 2)
        {
            cout << "\n======= view all vehicles ======= \n";
            registry.dispaly_vehicle();
        }
        else if (choice == 3)
        {
            cout << "\n======= search vehicle by id ======= \n";
            int id;
            cout << "Entre the vehical id: ";
            cin >> id;
            registry.search_vehicle(id);
        }
        else if (choice == 4)
        {
            cout << "\n======= exit ======= \n";
            choice = 4;
            break;
        }
        else
        {
            cout << "Invalid choice..." << endl;
        }

    } while (choice != 4);

    return 0;
}