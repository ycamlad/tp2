#include "Datapoint.h"
#include <fstream>
#include <sstream>
#include <set>



int main()
{
    std::ofstream rawdata("rawdata.txt");
    std::string data="30.20\n-81.39\nKHB39\n62\n2021-02-28T08:00\n34.03\n-118.15\nKWO37\n72\n2021-02-28T08:05\n61.34\n-149.27\nKZZ97\n25\n2021-02-28T08:00\n32.30\n-93.44\nWXJ97\n85\n2021-02-28T08:05\n26.22 \n-98.49 \nWNG601 \n72 \n2021-02-28T08:05 \n32.30 \n-110.55 \nWXL30 \n89 \n2021-02-28T08:05 \n18.24 \n-66.03 \nWXJ69 \n85 \n2021-02-28T08:10 \n40.71 \n-74.00 \nKWO35 \n33 \n2021-02-28T08:10 \n45.31 \n-122.40 \nKIG98 \n55 \n2021-02-28T08:10 \n47.36 \n-122.19 \nKHB60 \n45 \n2021-02-28T08:10";

    rawdata<<data;

    rawdata.close();

    const char* space = " ";
    std::set<Datapoint*> datas;				// Création de l'arbre binaire
    std::ifstream lecteur("rawdata.txt", std::ios::app);
    double latitude;
    double longitude;
    std::string identifiant;
    int temperature;
    std::string timestamp;
    std::string line;
    for (int i = 0;i<10;i++) {
        std::getline(lecteur, line);
        latitude = atof(line.c_str());
        std::getline(lecteur, line);
        longitude = atof(line.c_str());
        std::getline(lecteur, line);
        identifiant = line.c_str();
        std::getline(lecteur, line);
        temperature = atoi(line.c_str());
        std::getline(lecteur, line);
        timestamp = line;

        Datapoint* mydatas = new Datapoint(identifiant, timestamp, latitude, longitude, temperature);
        std::cout << std::endl;
        mydatas->affichage();
        std::cout << std::endl;

        datas.insert(mydatas);
        datas.insert(mydatas);
        std::ofstream candata("candata.txt");
        if (candata.is_open()) {
            candata << mydatas;				// Écriture dans le fichier candata
            datas.insert(mydatas);			// Insertion des données dans l'arbre binaire
        }
        else {
            std::cout << "Le fichier candata.txt n'est pas ouvert" << std::endl;
        }
        candata.close();
    }
    lecteur.close();

    /*std::set<int>::reverse_iterator i;
    for (i = datas.rbegin(); i != datas.rend(); i++) {
        std::cout << *i << std::endl;
    }*/
}