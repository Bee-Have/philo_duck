NAME = philo
NAME_B = philo_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

DEBUG =
ifdef DEBUG
CFLAGS += -fsanitize=address -g3
endif

SRCS_DIR = $(shell find srcs -type d)

OBJS_DIR = objs
OBJS_DIR_B = objs_bonus
INC_DIR = ./philo/includes/
INC_DIR_B = ./philo_bonus/includes/

LIBS = -lpthread
LIBS_B = -lpthread -lrt

INC = -I$(INC_DIR)
INC_B = -I$(INC_DIR_B)

vpath %.c $(foreach dir, $(SRCS_DIR), $(dir):)

SRCS = main.c \
	args_manager.c init_struct.c \
	god_routine.c \
	wait.c death.c \
	eat.c sleep.c \
	time.c print_action_time.c \
	string_tools.c nbr_tools.c \
	error_manager.c

SRCS_B = main_bonus.c

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
OBJS_B = $(addprefix $(OBJS_DIR_B)/,$(SRCS_B:.c=.o))

all: $(NAME) $(NAME_B)

mandatory: $(NAME)

bonus: $(NAME_B)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(NAME_B): $(OBJS_B)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS_B)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJS_DIR_B)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_B) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJS_DIR)
	rm -rf $(OBJS_DIR_B)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_B)

.PHONY : fclean clean re mandatory bonus all