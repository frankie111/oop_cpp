#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class RoadVehicle {
private:
    int id;
    string brand;
    string model;

public:
    RoadVehicle(int _id, string _brand, string _model)
            : id(_id), brand(_brand), model(_model) {}

    void set_id(int id);

    void set_brand(string _brand);

    void set_model(string _model);

    int const get_id();

    string const get_brand();

    string const get_model();
};

class TransporterTruck : public RoadVehicle {
private:
    int capacity;
    vector<RoadVehicle> vehicles;
public:
    TransporterTruck(int _id, const string &_brand, const string &_model, int _capacity)
            : RoadVehicle(_id, _brand, _model), capacity(_capacity) {}

    void addVehicle(const RoadVehicle& vehicle) {
        if (vehicles.size() < capacity)
            vehicles.push_back(vehicle);
    }

    void removeVehicle(const RoadVehicle& vehicle){
        auto it = find(vehicles.begin(), vehicles.end(), vehicle);

    }
};

/* ------------------------------------------------- */

class Truck : public RoadVehicle {
private:
    int totalWeight;
    string name;

public:
    Truck(int _id, string _brand, string _model, int _totalWeight, string _name)
            : RoadVehicle(_id, _brand, _model), totalWeight(_totalWeight), name(_name) {}

    Truck load(int totalWeight);

    Truck unload(int totalWeight);
};

/* ------------------------------------------------- */

class Car : public RoadVehicle {
private:
    string additionals;

public:
    Car(int _id, string _brand, string _model, string _additionals)
            : RoadVehicle(_id, _brand, _model), additionals(_additionals) {}

    void set_additionals(string _additionals);

    string get_additionals();
};