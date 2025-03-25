NAME_SERVER = server
NAME_CLIENT = client
NAME = $(NAME_SERVER) $(NAME_CLIENT)

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_SERVER =	server.c \
				utils.c

SRC_CLIENT =	client.c \
				utils.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(NAME)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(SRC_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) -o $(NAME_CLIENT)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: clean fclean all re