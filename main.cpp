#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <typeinfo>

#include "radiation.h"
#include "plant.h"

using namespace std;

void create(const string &file, vector<Plant*> &plants, int &days, Radiation* &rad)
{
    ifstream f(file.c_str());

    if(f.fail())
    {
        std::cout << "Nincs ilyen nevu fajl : " << file << std::endl;
        exit(1);
    }

    int n;
    f >> n;
    plants.resize(n);
    string name;
    char type;
    int nut, m;
    for (int i = 0; i < n; i++)
    {
        f >> name >> type >> nut;
        switch(type){
        case 'p':
            plants[i] = new Puffancs(name, nut);
            break;
        case 'd':
            plants[i] = new Deltafa(name, nut);
            break;
        case 'b':
            plants[i] = new Parabokor(name, nut);
            break;
        }
    }

    f >> m;
    days = m;

    rad = None::instance();
}

void simulateMain(vector<Plant*> &plants, int &days, Radiation* &rad, Plant* &strongest)
{
    try{

        for(int i = 0; i < days; i++){
            cout << i+1 << ". nap" << endl << endl;
            int radInfluence = 0;
            for(int j = 0; j < plants.size(); j++){
                if(plants[j]->getAlive()){
                    radInfluence += plants[j]->simulate(rad);
                    cout << plants[j]->getName() << endl;
                    cout << "Tap : " << plants[j]->getNutr() << endl << endl;
                } else {
                    cout << plants[j]->getName() << " elpusztult" << endl;
                }
            }
            cout << endl << endl << endl;
            cout << i+2 << ". napi sugarzas:";
            rad = Radiation::create(radInfluence);

        }

        strongest = plants[0];
        for(int i = 0; i < plants.size(); i++){
            if(plants[i]->getAlive()){
                if(plants[i]->getNutr() > strongest->getNutr()){
                    strongest = plants[i];
                }
            }
        }

        cout << "____________________________" << endl;
        if(strongest->getAlive()){
            cout << "A legerosebb noveny: " << endl;
            cout << strongest->getName() << ", " << strongest->getNutr() << " tap ponttal." << endl;
        } else {
            cout << "Egy noveny sem elte tul." << endl;
        }


    } catch(exception err) {
        cout << err.what() << endl;
    }
}

void destroyAll(vector<Plant*> &plants){
    for(int i=0; i<(int)plants.size(); ++i) delete plants[i];
    Alpha::destroy();
    Delta::destroy();
    None::destroy();
}

#define NORMAL_MODE
#ifndef NORMAL_MODE


int main()
{
    vector<Plant*> plants;
    Plant* strongest;
    int days;
    Radiation* rad;
    create("inp.txt", plants, days, rad);
    simulateMain(plants, days, rad, strongest);

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("1", "test1.txt") //1 nap, 1 noveny
{
    vector<Plant*> plants;
    Plant* strongest;
    int days;
    Radiation* rad;
    create("test1.txt", plants, days, rad);
    simulateMain(plants, days, rad, strongest);

    CHECK(strongest->getName() == "Puff");
    CHECK(strongest->getNutr() == 2);
    CHECK(strongest->getAlive() == true);

}

TEST_CASE("2", "test2.txt") //1 nap, 3 noveny
{
    vector<Plant*> plants;
    Plant* strongest;
    int days;
    Radiation* rad;
    create("test2.txt", plants, days, rad);
    simulateMain(plants, days, rad, strongest);

    CHECK(strongest->getName() == "Oriaspuff");
    CHECK(strongest->getNutr() == 8);
    CHECK(strongest->getAlive() == true);

}

TEST_CASE("3", "test3.txt"){ //2 noveny, 10 nap, 0 tulelo
    vector<Plant*> plants;
    Plant* strongest;
    int days;
    Radiation* rad;
    create("test3.txt", plants, days, rad);
    simulateMain(plants, days, rad, strongest);

    CHECK(strongest->getAlive() == false);
}

TEST_CASE("4", "test4.txt") //Tobb noveny, 1 tulelo, nagyobb tappontok
{
    vector<Plant*> plants;
    Plant* strongest;
    int days;
    Radiation* rad;
    create("test4.txt", plants, days, rad);
    simulateMain(plants, days, rad, strongest);

    CHECK(strongest->getName() == "Semlegeske");
    CHECK(strongest->getNutr() == 12);
    CHECK(strongest->getAlive() == true);

}

TEST_CASE("5", "test5.txt") //Nagyobb tappontok, nagyobb idointervallum
{
    vector<Plant*> plants;
    Plant* strongest;
    int days;
    Radiation* rad;
    create("test5.txt", plants, days, rad);
    simulateMain(plants, days, rad, strongest);

    CHECK(strongest->getName() == "Bokor");
    CHECK(strongest->getNutr() == 65);
    CHECK(strongest->getAlive() == true);

}


#endif
