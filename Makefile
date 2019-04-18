##
## EPITECH PROJECT, 2018
## plazza
## File description:
## Makefile
##

CC	=	g++

DTESTS	=	tests/
DSRC	=	src/
DPARSE	=	$(DSRC)parse/

SRC	=		$(wildcard $(DSRC)*.cpp)		\
			$(wildcard $(DPARSE)*.cpp)		\

MAIN	=	main.cpp

SRC_UT	=	$(wildcard $(DTESTS)parse/*.cpp)		\

INC	=	-I. -I$(DSRC) -I$(DPARSE)

CXXFLAGS	+=  -Wall -Wextra $(INC) -lpthread
OBJ	=	$(SRC:.cpp=.o) $(MAIN:.cpp=.o)
NAME	=	plazza
NAME_UT	=	units

all: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_UT)

re: fclean all

debug: CXXFLAGS += -g
debug: re

tests_run: CXXFLAGS += --coverage -lgcov
tests_run: LDFLAGS += -lgtest -lgtest_main
tests_run:
	$(CC) -o $(NAME_UT) $(SRC) $(SRC_UT) $(CXXFLAGS) $(LDFLAGS) $(INC_UT)
	./$(NAME_UT)
	gcov *.gcno &> /dev/null

tests_clean:
	rm -f $(NAME_UT) *.gcno *.gcov *.gcda

.PHONY: all clean fclean re debug tests_run tests_clean
