/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Process.hpp
*/

#ifndef PLAZZA_PROCESS_HPP
#define PLAZZA_PROCESS_HPP

#include <unistd.h>
#include <sys/socket.h>
#include "Kitchen.hpp"

namespace plazza {
    template <typename T>
    class Process {
    public:
        explicit Process(int writeFd) :
            _sockets(),
            _writeFd(writeFd)
        {}

        ~Process()
        {
            close(_sockets[1]);
        }

        template <typename ...Args>
        void exec(Args... args)
        {
            int childPid;

            if (socketpair(AF_UNIX, SOCK_STREAM, 0, _sockets) < 0)
                perror("socketpair");
            childPid = fork();
            if (childPid == -1) {
                perror("fork");
            } else if (childPid == 0) {
                close(_sockets[1]);
                T t(_sockets[0], _writeFd, args...);

                t.exec();
                close(_sockets[0]);
                exit(0);
            } else {
                close(_sockets[0]);
            }
        }

        void send(const std::string &msg)
        {
            write(_sockets[1], msg.c_str(), msg.length());
        }

    private:
        int _sockets[2];
        int _writeFd;
    };
}

#endif
