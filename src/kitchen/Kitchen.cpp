/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Kitchen.cpp
*/

#include <unistd.h>
#include <chrono>
#include <cstring>
#include <iostream>
#include "Kitchen.hpp"
#include "SerializedPizza.hpp"

plazza::Kitchen::Kitchen(int fd, size_t nbCooks) :
    _stock(5),
    _fd(fd)
{
    for (size_t i = 0; i < nbCooks; ++i)
        _cooks.emplace_back();
}

void plazza::Kitchen::launch()
{
    while (true)
        waitCommand();
}

void plazza::Kitchen::waitCommand()
{
    unsigned char buff[4096] = {0};
    int nbBytes;

    checkTimeout();
    nbBytes = read(_fd, buff, 4096);
    if (nbBytes < 0) {
        perror("read");
        exit(84);
    } else if (nbBytes == 0) {
        write(1, "kitchen destroy...", sizeof("kitchen destroy..."));
        exit(0);
    } else {
        handlePizza(SerializedPizza(buff).unpack());
    }
}

void plazza::Kitchen::checkTimeout() const
{
    struct timeval time = {5, 0};
    fd_set set;

    FD_ZERO(&set);
    FD_SET(_fd, &set);
    select(_fd + 1, &set, nullptr, nullptr, &time);
    if (!FD_ISSET(_fd, &set)) {
        write(_fd, "timeout", sizeof("timeout"));
        exit(0);
    }
}

void plazza::Kitchen::handlePizza(plazza::IPizza *)
{
}
