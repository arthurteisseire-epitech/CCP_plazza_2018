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

plazza::SerializedPizza::SerializedPizza(const unsigned char *bytes) :
    _type(0),
    _size(0)
{
    for (int i = 3; i >= 0; --i)
        _type = (_type << 1u) | bytes[i];
    for (int i = 7; i >= 4; --i)
        _size = (_size << 1u) | bytes[i];
}

plazza::IPizza *plazza::SerializedPizza::unpack() const
{
    return PizzaFactory::create(static_cast<PizzaType>(_type), static_cast<PizzaSize>(_size));
}
