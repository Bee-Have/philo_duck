MANDA_DIR = ./philo
BONUS_DIR = ./philo_bonus

all:
	make -C $(MANDA_DIR)
	make -C $(BONUS_DIR)

manda:
	make -C $(MANDA_DIR)

bonus:
	make -C $(BONUS_DIR)

re: fclean all

re_manda:
	make -C $(MANDA_DIR) re

re_bonus:
	make -C $(BONUS_DIR) re

clean:
	make -C $(MANDA_DIR) clean
	make -C $(BONUS_DIR) clean

fclean:
	make -C $(MANDA_DIR) fclean
	make -C $(BONUS_DIR) fclean

.PHONY: fclean clean re_bonus re_manda re bonus manda all