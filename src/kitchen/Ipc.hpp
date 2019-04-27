/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Ipc.hpp
*/

#ifndef PLAZZA_IPC_HPP
#define PLAZZA_IPC_HPP

#include <cstring>
#include <string>

namespace plazza {
    class Ipc {
    public:
        Ipc();
        ~Ipc();

        void readParentInput(char *buffer, size_t size) const;
        void readChildInput(char *buffer, size_t size) const;

        void sendToChild(const char *msg) const;
        void sendToParent(const char *msg) const;

        template <typename U>
        void sendToChild(const U &data, size_t size) const
        {
            write(_parentFd, &data, size);
        }

        template <typename U>
        void sendToParent(const U &data, size_t size) const
        {
            write(_childFd, &data, size);
        }

        void closeParentFd() const;
        void closeChildFd() const;

        int getParentFd() const;
        int getChildFd() const;

    private:
        void readInput(int fd, char *buffer, size_t size) const;

        int _childFd;
        int _parentFd;
    };
}

#endif
