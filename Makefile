NAME = philo

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = $(shell find srcs -type d)

OBJS_DIR = objs
INC_DIR = ./includes/

LIBS = -lpthread

INCLUDES = -I$(INC_DIR)

vpath %.c $(foreach dir, $(SRCS_DIR), $(dir):)

SRCS = main_test.c \
	string_tools.c nbr_tools.c \
	time.c print_action_time.c

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJS_DIR)

fclean: clear
	rm -rf $(NAME)

.PHONY : fclean clean re all 