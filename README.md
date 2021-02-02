# The Plazza

The plazza is an educational project to learn how to use fork and threads from scratch.

The Pizzeria organization:
- First the customer who wants a pizza (You, in the shell)
- The reception (The shell)
- Many kitchens you need to be efficient (Forks of the reception)
- Cooks in kitchens (Threads)
- Ingredient stock shared between cooks in the same kitchen (Ingredients are replaced automatically by kitchen)

## Install

### With Nix (easy)

If you don't have nix yet run `curl -L https://nixos.org/nix/install | sh` and read output messages.
```shell script
nix-shell shell.nix  # This will install all dependencies in a separate environment
make
```

### Manually

Install the following dependencies:
- make
- gcc
- make sure "pthread" c library is available in your library path
- gtest (optional: If you want to run tests)



## USAGE

Program (recpeption):
`./plazza <cooking_pizza_seconds> <number_of_cook_per_kitchen> <milliseconds_to_replace_ingredients>`

In the shell you can order pizzas like this:
`<pizza_name> <pizza_size> x<pizza_number>`

Example:
`regina XXL x6`

You can see what your reception looks like with the `status` command.

You can find the list below in src/pizza/Resolver.cpp

Pizza names:
- regina
- fantasia
- margarita
- americana

Pizza sizes:
- S
- M
- L
- XL
- XXL
