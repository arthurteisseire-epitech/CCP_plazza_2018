/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Cook.hpp
*/

#ifndef PLAZZA_COOK_HPP
#define PLAZZA_COOK_HPP

#include <thread>
#include <condition_variable>
#include "APizza.hpp"

namespace plazza {
    class Cook {
        public:
        enum status {
            WAITING,
            COOKING
        };

        Cook(double cookingTimeMultiplier, Stock &stock, std::queue<IPizza *> &queue,
             std::shared_ptr<std::mutex> pizzasMutex, std::shared_ptr<std::mutex> ingredientsMutex);
        ~Cook();
        status getStatus() const;

        private:
        void _start();

        void preparePizza();

        double _cookingTimeMultiplier;
        status _status;
        Stock &_stock;
        std::queue<IPizza *> &_queue;
        IPizza *_pizzaToPrepare;
        std::thread *_thread;
        std::shared_ptr<std::mutex> _pizzasMutex;
        std::shared_ptr<std::mutex> _ingredientsMutex;
    };
}

#endif
