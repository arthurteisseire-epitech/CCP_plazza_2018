/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** ArgParser.hpp
*/

#ifndef PLAZZA_ARGPARSER_HPP
#define PLAZZA_ARGPARSER_HPP

namespace plazza {
    class ArgParser {
    public:
        ArgParser(int ac, const char *av[]);

        double getCookingTimeMultiplier() const;
        size_t getNbCooks() const;
        size_t getTimeToReplaceIngredient() const;

        bool failed();
    private:
        void parseArgs(const char *av[]);
        double _cookingTimeMultiplier;
        size_t _nbCooks;
        size_t _timeToReplaceIngredient;
        bool _failed;
    };
}

#endif
