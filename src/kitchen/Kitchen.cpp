/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Kitchen.cpp
*/

#include <unistd.h>
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

void plazza::Kitchen::exec()
{
    unsigned char buff[sizeof(SerializedPizza)];

    if (read(_readFd, buff, sizeof(SerializedPizza)) == -1)
        perror("read");
    SerializedPizza pizza(buff);
    auto p = pizza.unpack();
    write(_writeFd, "ok", 2);
}
