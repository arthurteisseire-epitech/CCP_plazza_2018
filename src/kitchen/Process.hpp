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
#include "Ipc.hpp"

namespace plazza {
    template <typename T>
    class Process {
    public:
        Process() = default;

        template <typename ...Args>
        void create(Args... args) const
        {
            int childPid = fork();

            if (childPid == -1) {
                perror("fork");
            } else if (childPid == 0) {
                ipc.closeParentFd();
                T t(ipc, args...);

                t.launch();
                exit(0);
            } else {
                ipc.closeChildFd();
            }
        }

        void send(const char *msg) const
        {
            ipc.sendToChild(msg);
        }

        template <typename U>
        void send(const U &data, size_t size) const
        {
            ipc.sendToChild(data, size);
        }

        std::string read() const
        {
            char buffer[4096];

            ipc.readChildInput(buffer, sizeof(buffer));
            return std::string(buffer);
        }

        int getReadFd() const
        {
            return ipc.getParentFd();
        }

    private:
        Ipc ipc;
    };
}

#endif
