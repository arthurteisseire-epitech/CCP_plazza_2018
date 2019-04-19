/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** APizza.cpp
*/

#include <utility>
#include "APizza.hpp"

plazza::APizza::APizza(plazza::PizzaType type, plazza::PizzaSize size,
                       std::vector<plazza::Ingredient> ingredients, std::chrono::duration<double> time) :
    _type(type),
    _size(size),
    _ingredients(std::move(ingredients)),
    _time(time)
{
}
