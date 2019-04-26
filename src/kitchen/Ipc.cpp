/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Ipc.cpp
*/

#include <unistd.h>
#include <cstdio>
#include <sys/socket.h>
#include <iostream>
#include "Ipc.hpp"

plazza::Ipc::Ipc()
{
    int sockets[2];

    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockets) < 0)
        perror("socketpair");
    _childFd = sockets[0];
    _parentFd = sockets[1];
}

plazza::Ipc::~Ipc()
{
    close(_childFd);
    close(_parentFd);
}

void plazza::Ipc::readParentInput(char *buffer, size_t size) const
{
    int nbBytes = ::read(_childFd, buffer, size);

    if (nbBytes == -1)
        perror("read");
    else
        buffer[nbBytes] = 0;
}

void plazza::Ipc::readChildInput(char *buffer, size_t size) const
{
    int nbBytes = ::read(_parentFd, buffer, size);

    if (nbBytes == -1)
        perror("read");
    else
        buffer[nbBytes] = 0;
}

void plazza::Ipc::closeParentFd() const
{
    close(_parentFd);
}

void plazza::Ipc::closeChildFd() const
{
    close(_childFd);
}

int plazza::Ipc::getParentFd() const
{
    return _parentFd;
}

int plazza::Ipc::getChildFd() const
{
    return _childFd;
}

void plazza::Ipc::sendToChild(const char *msg) const
{
    write(_parentFd, msg, strlen(msg));
}

void plazza::Ipc::sendToParent(const char *msg) const
{
    write(_childFd, msg, strlen(msg));
}
