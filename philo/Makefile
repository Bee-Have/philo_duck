NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS_DIR = $(shell find srcs -type d)

OBJS_DIR = objs
INC_DIR = ./includes/

LIBS = -lpthread
INC = -I$(INC_DIR)

vpath %.c $(foreach dir, $(SRCS_DIR), $(dir):)

SRCS = main.c \
	args_manager.c init_struct.c \
	god_routine.c \
	wait.c death.c \
	eat.c sleep.c \
	time.c print_action_time.c \
	string_tools.c nbr_tools.c \
	error_manager.c

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm $(NAME)

.PHONY: fclean clean re all