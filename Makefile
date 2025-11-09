CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line.c get_next_line_utils.c main.c
SRC_OBG =$(SRC:.c=.o)

main:$(SRC_OBG)
	$(CC) $(CFLAGS) $(SRC_OBG) -o $@

clean : $(SRC_OBG)
	rm -f $(SRC_OBG)

re : clean main

.PHONY : re clean 