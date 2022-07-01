#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <iomanip>
#include "swimmer.h"


std::mutex swimStatus;

void swimmerStatus(Swimmer* swimmer, const int lengthLane)
{
    swimmer->setSwimTime(lengthLane / swimmer->getSpeed());

    int time = 0;
    while (!swimmer->getFinish())
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        ++time;

        if (swimmer->getSpeed() * time >= lengthLane)
        {
            swimmer->setFinish();
        }
        swimStatus.lock();
        std::cout << "Name:";
        std::cout.width(10);
        std::cout << swimmer->getName();
        std::cout << "   time: ";
        std::cout.width(5);
        if (swimmer->getFinish())
        {
            std::cout << "finished";
        }    
        else
        {
            std::cout << swimmer->getSpeed() * time;
        }
            
        std::cout << std::endl;
        swimStatus.unlock();
    }
}

int main()
{
    constexpr int amountSwimmers = 6;
    constexpr int lengthLane = 100;
    Swimmer* newSwimmer;

    std::vector <Swimmer*> swimmers;
    for (int i = 0; i < amountSwimmers; ++i)
    {
        system ("cls");
        std::cout << "Enter information about the " << i + 1 << " swimmer: " << std::endl;
        std::cout << " name: ";
        std::string name = "";
        std::cin >> name;
        std::cout << " speed (m/s): ";
        double speed = 0.0;
        while (speed <= 0.0)
        {
            std::cin >> speed;
        }
            
        newSwimmer = new Swimmer(name, speed);
        swimmers.push_back(newSwimmer);   
    }
    
    system("cls");

    std::vector <std::thread> swimThreads;
    for (int i = 0; i < amountSwimmers; ++i)
    {
        swimThreads.emplace_back(std::thread(swimmerStatus, swimmers[i], lengthLane));
    }
        
    for (auto& t : swimThreads)
    {
        t.join();
    }
     
    system("cls");

    std::cout << "          Final result" << std::endl;
    std::sort(swimmers.begin(), swimmers.end(), compare);

    for (int i = 0; i < amountSwimmers; ++i)
    {
        std::cout.width(10);
        std::cout  << swimmers[i]->getName();
        std::cout.width(10);
        std::cout.fixed;
        std::cout.precision(4);
        std::cout << swimmers[i]->getSwimTime() << " sec" << std::endl;
    }
    delete newSwimmer;
}