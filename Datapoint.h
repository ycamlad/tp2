//
// Created by dalmacychristopher on 23/03/2021.
//

#ifndef TP2_DATAPOINT_H
#define TP2_DATAPOINT_H

#include <iostream>
#include <string>
#include <set>
class Datapoint {
private:
    std::string identifiant;		// Identifiant de la station météorologique
    std::string timestamp;			// Moment lorsque la température a été prise
    double latitude;
    double longitude;
    double celcius;
    std::set<Datapoint*> datas;
public:
    Datapoint(std::string son_identifiant, std::string le_timestamp, double la_latitude, double la_longitude, int farenheit) {
        this->identifiant = son_identifiant;
        this->timestamp = le_timestamp;
        this->latitude = la_latitude;
        this->longitude = la_longitude;

        this->celcius = ((double)farenheit - 32.0) * (5.0 / 9.0);		// Conversion en celcius
    }

    void affichage() {
        std::string result = this->timestamp;
        result += " ";
        result += std::to_string(this->latitude);
        result += " ";
        result += std::to_string(this->longitude);
        result += " ";
        result += std::to_string(this->celcius);
        result += "C°";
        std::cout<<result;
    }
};


#endif //TP2_DATAPOINT_H
