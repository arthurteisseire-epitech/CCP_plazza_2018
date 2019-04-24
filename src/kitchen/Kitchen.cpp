/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Kitchen.cpp
*/

#include <unistd.h>
#include "Kitchen.hpp"

plazza::Kitchen::Kitchen(int readFd, int writeFd, size_t nbCooks) :
    _stock(5),
    _readFd(readFd),
    _writeFd(writeFd)
{
    for (size_t i = 0; i < nbCooks; ++i)
        _cooks.emplace_back();
}

void plazza::Kitchen::exec()
{
    char buff[4096] = "hih";
    int nbBytes = read(_readFd, buff + 3, sizeof(buff));

    write(_writeFd, buff, nbBytes + 3);
}
