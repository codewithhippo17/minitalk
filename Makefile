NAME_SERVER = server
NAME_CLIENT = client
NAME = $(NAME_SERVER) $(NAME_CLIENT)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_SERVER =	server.c \
				utils.c

SRC_CLIENT =	client.c \
				utils.c



OBJ_SERVER = $(SRC:.c=.o)
OBJ_CLIENT = $(SRC_1:.c=.o)

all: $(NAME)

$(NAME_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(SRC_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) -o $(NAME_CLIENT)

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: clean fclean all re