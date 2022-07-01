#pragma once

#include <string>


class Swimmer
{
public:
    Swimmer(std::string& name, double speed): name(name), speed(speed) {}

    std::string getName()
    {
        return name;
    }

    double getSpeed()
    {
        return speed;
    }

    void setFinish()
    {
        finish = true;
    }

    bool getFinish()
    {
        return finish;
    }

    void setSwimTime(double time)
    {
        this->time = time;
    }

    double getSwimTime()
    {
        return time;
    }

private:
    std::string name = "unknown";
    double speed = 0.0;
    double time = 0.0;
    bool finish = false;
};


int compare(Swimmer* a, Swimmer* b)
{
    return (a->getSwimTime() < b->getSwimTime());
}