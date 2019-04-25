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

void plazza::KitchenManager::sendOrder(Order &order)
{
    IPizza *pizza = order.takePizza();
    char buff[40] = {0};

    if (pizza == nullptr)
        return;
    createKitchen();
    _processes[0].send(pizza->pack(), sizeof(SerializedPizza));
    read(_sockets[0], buff, 40);
    write(1, "receive : ", sizeof("receive : "));
    dprintf(1, "%s\n", buff);
}

void plazza::KitchenManager::createKitchen()
{
    _processes.emplace_back(_sockets[1]);
    _processes[0].exec(_nbCooks);
}
