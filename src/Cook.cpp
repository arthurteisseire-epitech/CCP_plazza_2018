/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Cook.cpp
*/

#include <iostream>
#include <utility>
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
    _status = COOKING;
    _getPizzaInStock();
    _pizzasMutex->unlock();
    if (_stock.containsEach(_pizzaToPrepare->getIngredients()))
        _pizzaToPrepare->prepare(_stock, _cookingTimeMultiplier);
#ifdef PLAZZADEBUG
    else
        std::cout << "no more ingredients in stock" << std::endl;
    std::cout << "pizza done!" << std::endl;
#endif
    _status = WAITING;
}
