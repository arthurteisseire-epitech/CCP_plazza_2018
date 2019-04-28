/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Reception.hpp
*/

#ifndef PLAZZA_RECEPTION_HPP
#define PLAZZA_RECEPTION_HPP

#include "KitchenManager.hpp"

namespace plazza {
    class Reception {
    public:
        Reception(double cookingTime, size_t nbCooks, size_t timeToReplaceIngredient);
        void open();
    private:
        void waitAnyEvent(fd_set *set);
        void handleEvents(fd_set *set);
        void sendOrderFromUserInput();

        KitchenManager _kitchenManager;
        double _cookingTimeMultiplier;
        size_t _nbCooks;
        size_t _timeToReplaceIngredient;
    };
}

#endif
