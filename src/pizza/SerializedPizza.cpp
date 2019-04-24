/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** SerializedPizza.cpp
*/

#include "SerializedPizza.hpp"
#include "PizzaFactory.hpp"

plazza::SerializedPizza::SerializedPizza(PizzaType type, PizzaSize size) :
    _type(type),
    _size(size)
{
}

plazza::IPizza *plazza::SerializedPizza::unpack() const
{
    return PizzaFactory::create(_type, _size);
}
