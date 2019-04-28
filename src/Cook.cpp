#include <utility>

/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Cook.cpp
*/

#include <iostream>
#include <queue>
#include "Cook.hpp"

plazza::Cook::Cook(double cookingTimeMultiplier, Stock &stock, std::queue<IPizza *> &queue, std::shared_ptr<std::mutex> pizzasMutex) :
    _cookingTimeMultiplier(cookingTimeMultiplier),
    _status(WAITING),
    _stock(stock),
    _queue(queue),
    _pizzasMutex(std::move(pizzasMutex))
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
    _thread = new std::thread([this]() {
        _pizzasMutex->lock();
        while (1) {
            if (waitPizza())
                preparePizza();
        }
    });
}

bool plazza::Cook::waitPizza()
{
    return !_queue.empty();
}

void plazza::Cook::preparePizza()
{
    std::cout << "getting pizza in stock..." << std::endl;
    _getPizzaInStock();
    _pizzasMutex->unlock();
    std::cout << "I'm preparing..." << std::endl;
    _pizzaToPrepare->prepare(_stock, _cookingTimeMultiplier);
//    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << "pizza done!" << std::endl;
}
