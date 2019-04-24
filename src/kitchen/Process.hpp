/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Process.hpp
*/

#ifndef PLAZZA_PROCESS_HPP
#define PLAZZA_PROCESS_HPP

#include "Kitchen.hpp"

namespace plazza {
    class Process {
    public:
        explicit Process(int writeFd);
        ~Process();

        void exec();
        void send(const std::string &msg);
    private:
        int _sockets[2];
        int _writeFd;
    };
}

#endif
