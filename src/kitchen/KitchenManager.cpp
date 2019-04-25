/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** KitchenManager.cpp
*/

#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include "KitchenManager.hpp"
#include "Kitchen.hpp"

plazza::KitchenManager::KitchenManager(size_t nbCooks) :
    _nbCooks(nbCooks),
    _sockets()
{
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, _sockets) < 0)
        perror("socketpair");
    _process = std::make_unique<Process<Kitchen>>(_sockets[1]);
}

void plazza::KitchenManager::sendOrder(Order &order)
{
    IPizza *pizza = order.takePizza();
    char buff[40] = {0};
    static int isFirst = true;

    if (pizza == nullptr)
        return;
    if (isFirst) {
        _process->exec(_nbCooks);
        isFirst = false;
    }
    _process->send(pizza->pack(), sizeof(SerializedPizza));
    read(_sockets[0], buff, 40);
    std::cout << "receive : " << buff << std::endl;
}
