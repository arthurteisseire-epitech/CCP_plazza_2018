/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** main.cpp
*/

#include <pthread.h>
#include <iostream>

#define SIZE 10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *incrementCounter(void *p)
{
    int n = *(int *)p;

    pthread_mutex_lock(&mutex);
    std::cout << "increment n : " << n << std::endl;
    ++(*(int *)p);
    std::cout << "now n is : " << *(int *)p << std::endl;
    pthread_mutex_unlock(&mutex);
    pthread_exit(nullptr);
}

int main()
{
    int n = 0;
    pthread_t thread1[SIZE];

    for (int i = 0; i < SIZE; ++i)
        pthread_create(&thread1[i], nullptr, incrementCounter, &n);
    for (int i = 0; i < SIZE; ++i)
        pthread_join(thread1[i], nullptr);
    std::cout << "n : " << n << std::endl;
    return 0;
}
