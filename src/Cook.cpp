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
    this->_start();
    std::cout << "Cook created!" << std::endl;
}

plazza::Cook::status plazza::Cook::getStatus() const
{
    return this->_status;
}

void plazza::Cook::_getPizzaInStock()
{
    if (this->_queue.empty())
        return;
    this->_pizzaToPrepare = this->_queue.front();
    this->_queue.pop();
}

void plazza::Cook::_start()
{
    std::thread *newThread = new std::thread([this](){
        while (1) {
            std::cout << "I'm a waiting cuisto" << std::endl;
            std::unique_lock<std::mutex> locker(this->_nap);
            std::cout << "A" << std::endl;

            this->_alert.wait(locker);
            std::cout << "B" << std::endl;
            this->_getPizzaInStock();
            std::cout << "C" << std::endl;
            locker.unlock();
            std::cout << "The Cuisto got a Pizza!" << std::endl;
        }
    });
    this->_thread = newThread;
}

plazza::Cook::~Cook()
{
    this->_thread->join();
    delete(this->_thread);
}
