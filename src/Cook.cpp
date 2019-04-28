/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Cook.cpp
*/

#include <iostream>
#include <queue>
#include "Cook.hpp"

plazza::Cook::Cook(Stock &stock, std::queue<IPizza *> &queue, std::mutex
&nap, std::condition_variable &alert) :
_status(WAITING), _stock(stock), _queue(queue), _nap(nap), _alert(alert)
{
    _start();
    std::cout << "Cook created!" << std::endl;
}

plazza::Cook::~Cook()
{
    _thread->join();
    delete _thread;
}

plazza::Cook::status plazza::Cook::getStatus() const
{
    return _status;
}

void plazza::Cook::_getPizzaInStock()
{
    _pizzaToPrepare = _queue.front();
    _queue.pop();
}

void plazza::Cook::_start()
{
    _thread = new std::thread([this](){
        while (1) {
            if (waitPizza())
                preparePizza();
        }
    });
}

bool plazza::Cook::waitPizza()
{
//    std::unique_lock<std::mutex> locker(_nap);

//    std::cout << "I'm a waiting cook" << std::endl;
//    _alert.wait(locker);
    return !_queue.empty();
}

void plazza::Cook::preparePizza()
{
    std::cout << "I got a Pizza!" << std::endl;
    _getPizzaInStock();
    std::cout << "I'm preparing..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << "pizza done!" << std::endl;
}
