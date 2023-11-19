#pragma once

class Puffancs;
class Deltafa;
class Parabokor;

class Radiation
{
protected:
    int radInfluence = 0;
public:

    virtual int simulate(Puffancs *p) = 0;
    virtual int simulate(Deltafa *p) = 0;
    virtual int simulate(Parabokor *p) = 0;

    virtual ~Radiation() {}

    static Radiation* create(int n);
};

class Alpha : public Radiation
{
public:
    static Alpha* instance();
    int simulate(Puffancs *p) override;
    int simulate(Deltafa *p) override;
    int simulate(Parabokor *p) override;
    static void destroy();
protected:
    Alpha(){}
private:
    static Alpha* _instance;
};


class Delta : public Radiation
{
public:
    static Delta* instance();
    int simulate(Puffancs *p) override;
    int simulate(Deltafa *p) override;
    int simulate(Parabokor *p) override;
    static void destroy();
protected:
    Delta(){}
private:
    static Delta* _instance;
};

class None : public Radiation
{
public:
    static None* instance();
    int simulate(Puffancs *p) override;
    int simulate(Deltafa *p) override;
    int simulate(Parabokor *p) override;
    static void destroy();
protected:
    None(){}
private:
    static None* _instance;
};

