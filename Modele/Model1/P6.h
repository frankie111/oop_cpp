#ifndef MODELE_P6_H
#define MODELE_P6_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class EnergySource {
        private:
        virtual int efficiency() = 0;

        int mass;

        public:
        explicit EnergySource(int _mass) {
            mass = _mass;
        }
};

class FuelCell : public EnergySource {
        private:
        string fuelType;
        double consumption;

        public:
        int efficiency() override {
            return 10;
        }

        FuelCell(const string &fuelType, double consumption) : EnergySource(0) {
            this->fuelType = fuelType;
            this->consumption = consumption;
        }

        const string &getFuelType() const {
            return fuelType;
        }

        void setFuelType(const string &fuelType) {
            this->fuelType = fuelType;
        }

        double getConsumption() const {
            return consumption;
        }

        void setConsumption(double consumption) {
            this->consumption = consumption;
        }
};

class SolarPanel : public EnergySource {
        private:
        string cellType;
        int lightIntensity;

        public:
        int efficiency() override {
            return 10;
        }

        SolarPanel(const string &cellType, int lightIntensity) : EnergySource(0) {
            this->cellType = cellType;
            this->lightIntensity = lightIntensity;
        }

        const string &getCellType() const {
            return cellType;
        }

        void setCellType(const string &cellType) {
            this->cellType = cellType;
        }

        int getLightIntensity() const {
            return lightIntensity;
        }

        void setLightIntensity(int lightIntensity) {
            this->lightIntensity = lightIntensity;
        }
};

#endif //MODELE_P6_H
