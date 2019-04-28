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

plazza::Cook::Cook(double cookingTimeMultiplier, Stock &stock, std::queue<IPizza *> &queue,
                   std::shared_ptr<std::mutex> pizzasMutex, std::shared_ptr<std::mutex> ingredientsMutex) :
    _cookingTimeMultiplier(cookingTimeMultiplier),
    _status(WAITING),
    _stock(stock),
    _queue(queue),
    _pizzasMutex(std::move(pizzasMutex)),
    _ingredientsMutex(std::move(ingredientsMutex))
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

void plazza::Cook::_start()
{
    _thread = new std::thread([this]() {
        while (true) {
            _pizzasMutex->lock();
            while (_queue.empty());
            preparePizza();
        }
    });
}

void plazza::Cook::preparePizza()
{
    bool containsEach;

    _status = COOKING;
    _pizzaToPrepare = _queue.front();
    _ingredientsMutex->lock();
    containsEach = _stock.takeEach(_pizzaToPrepare->getIngredients());
    _ingredientsMutex->unlock();
    if (containsEach) {
        _queue.pop();
        _pizzasMutex->unlock();
        _pizzaToPrepare->prepare(_cookingTimeMultiplier);
    } else
        _pizzasMutex->unlock();
#ifdef PLAZZADEBUG
    else
        std::cout << "no more ingredients in stock" << std::endl;
    std::cout << "pizza done!" << std::endl;
#endif
    _status = WAITING;
}
