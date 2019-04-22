/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** IPizza.hpp
*/

#ifndef PLAZZA_IPIZZA_HPP
#define PLAZZA_IPIZZA_HPP

namespace plazza {
    class IPizza {
    public:
        ~IPizza() = default;
        virtual bool prepare(Stock &stock) const = 0;
    };
}

#endif
