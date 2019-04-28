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

        Cook(Stock &stock, std::queue<IPizza *> &queue, std::mutex &nap,
                std::condition_variable &alert);
        ~Cook();
        status getStatus() const;

        private:
        void _start();
        void _getPizzaInStock();

        bool waitPizza();
        void preparePizza();

        status _status;
        Stock &_stock;
        std::queue<IPizza *> &_queue;
        std::mutex &_nap;
        std::condition_variable &_alert;
        IPizza *_pizzaToPrepare;
        std::thread *_thread;
    };
}

#endif
