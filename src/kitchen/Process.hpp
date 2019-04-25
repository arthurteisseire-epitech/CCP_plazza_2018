/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Process.hpp
*/

#ifndef PLAZZA_PROCESS_HPP
#define PLAZZA_PROCESS_HPP

#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <cstring>
#include <sys/wait.h>
#include "Kitchen.hpp"

namespace plazza {
    template <typename T>
    class Process {
    public:
        explicit Process(int writeFd) :
            _sockets(),
            _writeFd(writeFd)
        {
            if (socketpair(AF_UNIX, SOCK_STREAM, 0, _sockets) < 0)
                perror("socketpair");
        }

        ~Process()
        {
            close(_sockets[1]);
        }

        template <typename ...Args>
        void create(Args... args)
        {
            int childPid = fork();

            if (childPid == -1) {
                perror("fork");
            } else if (childPid == 0) {
                close(_sockets[1]);
                T t(_sockets[0], _writeFd, args...);

                t.launch();
                close(_sockets[0]);
                exit(0);
            } else {
                close(_sockets[0]);
            }
        }

        void send(const char *msg) const
        {
            write(_sockets[1], msg, strlen(msg));
        }

        template <typename U>
        void send(const U &data, size_t size) const
        {
            write(_sockets[1], &data, size);
        }

    private:
        int _sockets[2];
        int _writeFd;
    };
}

#endif
