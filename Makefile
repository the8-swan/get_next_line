CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c main.c
SRC_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c main.c

SRC_OBG =$(SRC:.c=.o)
SRC_OBG_BONUS =$(SRC_BONUS:.c=.o)

all : main

main:$(SRC_OBG)
	$(CC) -g $(CFLAGS) $(SRC_OBG) -o $@

# main : $(SRC_OBG_BONUS)
# 	$(CC) -g $(CFLAGS) $(SRC_OBG_BONUS) -o $@

clean : 
	rm -f $(SRC_OBG) $(SRC_OBG_BONUS)
	
fclean : clean
	rm -f main 

re : fclean all

.PHONY : re clean all