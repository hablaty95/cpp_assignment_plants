#pragma once
#include <string>
#include "radiation.h"

class Plant
{
protected:
    std::string _name;
    int _nutrition;
    Plant (const std::string &str, int e = 0) :_name(str), _nutrition(e), _alive(true) {}
    bool _alive;
public:
    virtual int simulate(Radiation* &r) = 0;

    virtual void isAlive() = 0;

    bool getAlive(){
        return _alive;
    }

    void changeNutrition(int n){
        _nutrition += n;
    }

    std::string getName(){
        return _name;
    }
    int getNutr(){
        return _nutrition;
    }

    virtual ~Plant() {}

};

class Puffancs : public Plant
{
public:
    Puffancs(const std::string &str, int e) : Plant(str, e) {}
    virtual void isAlive() override
    {
        _alive =(0 < _nutrition && 10 >= _nutrition);
    }


    virtual int simulate(Radiation* &r) override
    {
        return r->simulate(this);
    }


};

class Deltafa : public Plant
{
public:
    Deltafa(const std::string &str, int e) : Plant(str, e) {}
    virtual void isAlive() override
    {
        _alive = ( 0 < _nutrition);
    }

    virtual int simulate(Radiation* &r) override
    {
        return r->simulate(this);
    }
};

class Parabokor : public Plant
{
public:
    Parabokor(const std::string &str, int e) : Plant(str, e) {}
    virtual void isAlive() override
    {
        _alive = ( 0 < _nutrition);
    }

    virtual int simulate(Radiation* &r) override
    {
        return r->simulate(this);
    }
};

