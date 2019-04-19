/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Margarita.cpp
*/

#include "Margarita.hpp"

plazza::Margarita::Margarita(plazza::PizzaSize size) :
    APizza(PizzaType::Margarita, size, {DOE, TOMATOE, GRUYERE}, std::chrono::duration<double>(1))
{
}
