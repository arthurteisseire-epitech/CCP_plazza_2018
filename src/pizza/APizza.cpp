/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** APizza.cpp
*/

#include <utility>
#include "APizza.hpp"

plazza::APizza::APizza(plazza::PizzaType type, plazza::PizzaSize size,
                       std::vector<plazza::Ingredient> ingredients, size_t time) :
    _type(type),
    _size(size),
    _ingredients(std::move(ingredients)),
    _time(time * 1000000)
{
}

bool plazza::APizza::prepare(Stock &stock) const
{
    return stock.takeEach(_ingredients);
}

plazza::SerializedPizza plazza::APizza::pack() const
{
    return {_type, _size};
}
