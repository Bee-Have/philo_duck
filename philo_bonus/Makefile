NAME = philo_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

SRCS_DIR = $(shell find srcs_bonus -type d)

OBJS_DIR = objs_bonus
INC_DIR = ./includes_bonus/

LIBS = -lpthread -lrt
INC = -I$(INC_DIR)

vpath %.c $(foreach dir, $(SRCS_DIR), $(dir):)

SRCS = main_bonus.c \
	args_manager_bonus.c \
	death_bonus.c \
	init_routine_bonus.c \
	vitals_routine_bonus.c \
	eat_bonus.c sleep_bonus.c \
	wait_bonus.c \
	time_bonus.c print_bonus.c \
	string_tools_bonus.c nbr_tools_bonus.c \
	error_manager_bonus.c

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