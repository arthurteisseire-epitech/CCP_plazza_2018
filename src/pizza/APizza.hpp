/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** APizza.hpp
*/

#ifndef PLAZZA_APIZZA_HPP
#define PLAZZA_APIZZA_HPP

#include <gtest/gtest_prod.h>
#include <string>
#include <vector>
#include <chrono>
#include "IPizza.hpp"
#include "PizzaType.hpp"
#include "Ingredient.hpp"
#include "PizzaSize.hpp"

namespace plazza {
    class APizza : public IPizza {
    public:
        bool prepare(Stock &stock, double timeMultiplier) const override;
        SerializedPizza pack() const override ;
        const std::vector<Ingredient> &getIngredients() const;
    protected:
        APizza(PizzaType type, PizzaSize size, std::vector<Ingredient> ingredients, size_t time);
    private:
        PizzaType _type;
        PizzaSize _size;
        const std::vector<Ingredient> _ingredients;
        double _time;

        FRIEND_TEST(PizzaTest, create);
        FRIEND_TEST(SerializedPizzaTest, unpack);
        FRIEND_TEST(Order, takePizza);
    };
}

#endif
