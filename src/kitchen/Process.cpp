/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Process.cpp
*/

#include <unistd.h>
#include <sys/socket.h>
#include <cstring>
#include "Process.hpp"

plazza::Process::Process(int writeFd) :
    _sockets(),
    _writeFd(writeFd)
{
}

plazza::Process::~Process()
{
    close(_sockets[1]);
}

void plazza::Process::exec()
{
    int childPid;

    if (socketpair(AF_UNIX, SOCK_STREAM, 0, _sockets) < 0)
        perror("socketpair");
    childPid = fork();
    if (childPid == -1) {
        perror("fork");
    } else if (childPid == 0) {
        close(_sockets[1]);
        Kitchen kitchen(_sockets[0], _writeFd, 5);

        kitchen.exec();
        close(_sockets[0]);
        exit(0);
    } else {
        close(_sockets[0]);
    }
}

void plazza::Process::send(const std::string &msg)
{
    write(_sockets[1], msg.c_str(), msg.length());
}
