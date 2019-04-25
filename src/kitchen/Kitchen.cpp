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

plazza::Kitchen::Kitchen(int readFd, int writeFd, size_t nbCooks) :
    _stock(5),
    _readFd(readFd),
    _writeFd(writeFd)
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
    unsigned char buff[sizeof(SerializedPizza)] = {0};
    int nbBytes = read(_readFd, buff, sizeof(SerializedPizza));

    if (nbBytes < 0) {
        perror("read");
        exit(84);
    } else if (nbBytes == 0) {
        write(1, "kitchen destroy...", sizeof("kitchen destroy..."));
        exit(0);
    } else {
        write(_writeFd, "ok", 2);
        handlePizza(SerializedPizza(buff).unpack());
    }
}

void plazza::Kitchen::handlePizza(plazza::IPizza *)
{
}
