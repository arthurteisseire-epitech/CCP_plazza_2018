/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Kitchen.cpp
*/

#include "Kitchen.hpp"

plazza::Kitchen::Kitchen(size_t nbCooks)
{
    for (size_t i = 0; i < nbCooks; ++i)
        _cooks.emplace_back();
}
