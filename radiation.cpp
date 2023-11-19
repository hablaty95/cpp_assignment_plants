#include "radiation.h"
#include "plant.h"

#include <iostream>


Radiation* Radiation::create(int n)
{
    if(n > 3){
        std::cout << "Alpha" << std::endl;
        return Alpha::instance();
    } else if (n < -3){
        std::cout << "Delta" << std::endl;
        return Delta::instance();
    } else {
        std::cout << "Nincs" << std::endl;
        return None::instance();
    }
}

Alpha* Alpha::_instance = nullptr;
Alpha* Alpha::instance() {
    if (_instance == nullptr) {
        _instance = new Alpha();
    }
    return _instance;
}
void Alpha::destroy() {
    if (nullptr!=_instance) delete _instance;
}

int Alpha::simulate(Puffancs *p)
{
    int ret = 0;
    p->changeNutrition(2);
    if(p->getAlive()){
        ret = 10;
    }
    p->isAlive();
    return ret;
}

int Alpha::simulate(Deltafa *p)
{
    int ret = 0;
    p->changeNutrition(-3);
    if(p->getAlive()){
        int tmp = p->getNutr();
        if(tmp < 5){
            ret = -4;
        } else if ( tmp < 10){
            ret = -1;
        } else {
            ret = 0;
        }
    }
    p->isAlive();
    return ret;
}

int Alpha::simulate(Parabokor *p)
{
    int ret = 0;
    p->changeNutrition(1);
    if(p->getAlive()){
        ret = 0;
    }
    p->isAlive();
    return ret;
}


Delta* Delta::_instance = nullptr;
Delta* Delta::instance() {
    if (_instance == nullptr) {
        _instance = new Delta();
    }
    return _instance;
}
void Delta::destroy() {
    if (nullptr!=_instance) delete _instance;
}

int Delta::simulate(Puffancs *p)
{
    int ret = 0;
    p->changeNutrition(-2);
    if(p->getAlive()){
        ret = 10;
    }
    p->isAlive();
    return ret;
}

int Delta::simulate(Deltafa *p)
{
    int ret = 0;
    p->changeNutrition(4);
    if(p->getAlive()){
        int tmp = p->getNutr();
        if(tmp < 5){
            ret = -4;
        } else if ( tmp < 10){
            ret = -1;
        } else {
            ret = 0;
        }
    }
    p->isAlive();
    return ret;
}

int Delta::simulate(Parabokor *p)
{
    int ret = 0;
    p->changeNutrition(1);
    if(p->getAlive()){
        ret = 0;
    }
    p->isAlive();
    return ret;
}

None* None::_instance = nullptr;
None* None::instance() {
    if (_instance == nullptr) {
        _instance = new None();
    }
    return _instance;
}
void None::destroy() {
    if (nullptr!=_instance) delete _instance;
}

int None::simulate(Puffancs *p)
{
    int ret = 0;
    p->changeNutrition(-1);
    if(p->getAlive()){
        ret = 10;
    }
    p->isAlive();
    return ret;
}

int None::simulate(Deltafa *p)
{
    int ret = 0;
    p->changeNutrition(-1);
    if(p->getAlive()){
        int tmp = p->getNutr();
        if(tmp < 5){
            ret = -4;
        } else if ( tmp < 10){
            ret = -1;
        } else {
            ret = 0;
        }
    }

    p->isAlive();
    return ret;
}

int None::simulate(Parabokor *p)
{
    int ret = 0;
    p->changeNutrition(-1);
    if(p->getAlive()){
        ret = 0;
    }

    p->isAlive();
    return ret;
}


