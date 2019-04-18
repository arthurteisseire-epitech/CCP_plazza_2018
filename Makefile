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

DSRC_UT	=	$(DTESTS)src/

SRC	=		$(DPARSE)CommandParser.cpp	\

MAIN	=	$(DSRC)main.cpp

SRC_UT	=	$(wildcard $(DSRC_UT)/parse/*.cpp)		\

INC	=	-I. -I$(DSRC) -I$(DPARSE)

CXXFLAGS	+=  -Wall -Wextra $(INC) -lpthread
LDFLAGS	+=	-lgtest -lgtest_main
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

tests_run: CXXFLAGS += --coverage -ftest-coverage -fprofile-arcs -lgcov
tests_run:
	$(CC) -o $(NAME_UT) $(SRC) $(SRC_UT) $(CXXFLAGS) $(LDFLAGS) $(INC_UT)
	./$(NAME_UT)
	gcov *.gcno &> /dev/null

tests_debug: CXXFLAGS += -g
tests_debug: tests_run

tests_clean:
	rm -f $(NAME_UT) *.gcno *.gcov *.gcda

.PHONY: all clean fclean re debug tests_run tests_debug tests_clean
