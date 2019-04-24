/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** KitchenManager.cpp
*/

#include <sys/socket.h>
#include <unistd.h>
#include "KitchenManager.hpp"
#include "Kitchen.hpp"

plazza::KitchenManager::KitchenManager(size_t nbCooks) :
    _nbCooks(nbCooks),
    _sockets()
{
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, _sockets) < 0)
        perror("socketpair");
}

void plazza::KitchenManager::sendOrder(const Order &)
{
    char buff[40];

    createKitchen();
    _processes[0].send("hey");
    write(1, "receive : ", sizeof("receive : "));
    write(1, buff, read(_sockets[0], buff, 40));
}

void plazza::KitchenManager::createKitchen()
{
    _processes.emplace_back(_sockets[1]);
    _processes[0].exec(_nbCooks);
}
