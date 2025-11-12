CC = cc
#CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c main.c
SRC_OBG =$(SRC:.c=.o)

all : main

main:$(SRC_OBG)
	$(CC) -g $(CFLAGS) $(SRC_OBG) -o $@

clean : 
	rm -f $(SRC_OBG)
fclean : clean
	rm -f main 

re : fclean all

.PHONY : re clean all