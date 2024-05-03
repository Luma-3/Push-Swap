# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 20:01:31 by jbrousse          #+#    #+#              #
#    Updated: 2024/05/03 13:16:42 by jbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##############
##`COMPILER	##
##############

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -O3


###############
##	  LIB	 ##
###############

LIB_PATH		=	lib/

LIBFT_PATH		=	$(LIB_PATH)libft/
LIBFT			=	$(LIBFT_PATH)libft.a
LIBFT_INC		=	$(LIBFT_PATH)includes/

STACKFT_PATH	=	$(LIB_PATH)stackft/
STACKFT			=	$(STACKFT_PATH)stackft.a
STACKFT_INC		=	$(STACKFT_PATH)includes/

###############
##	INCLUDE	 ##
###############

INC		=	./inc/			\
			./$(LIBFT_INC)	\
			./$(STACKFT_INC)
INCLUDE	=	$(addprefix -I, $(INC))
			
##############
##  SOURCE	##
##############

SRC_DIR		=	src/
SRC_UTILS	=	parse.c		\
				pslang.c	\
				utils.c

SRC_M_DIR	=	mandatory/
SRC_M_LIST	=	divide_algo.c	\
				medians.c		\
				ps_utils.c		\
				push_swap.c		\
				turkish_algo.c	\
				turkish_utils.c
SRC_M_PRE	=	$(addprefix $(SRC_M_DIR), $(SRC_M_LIST))

SRC_B_DIR	=	bonus/
SRC_B_LIST	=	checker_bonus.c		\
				reader_bonus.c
SRC_B_PRE	=	$(addprefix $(SRC_B_DIR), $(SRC_B_LIST))


SRC_BONUS			=	$(addprefix $(SRC_DIR), $(SRC_B_PRE))	\
						$(addprefix $(SRC_DIR), $(SRC_UTILS))

SRC_MANDATORY		=	$(addprefix $(SRC_DIR), $(SRC_M_PRE))	\
						$(addprefix $(SRC_DIR), $(SRC_UTILS))
			

##################
##   OBJ/NAME	##
##################

NAME		=	push_swap
NAME_BONUS	=	checker

OBJ_DIR	=	obj/
OBJ		=	$(addprefix $(OBJ_DIR), $(SRC_M_PRE:.c=.o))	\
			$(addprefix $(OBJ_DIR), $(SRC_UTILS:.c=.o))

OBJ_BONUS = $(addprefix $(OBJ_DIR), $(SRC_B_PRE:.c=.o))	\
			$(addprefix $(OBJ_DIR), $(SRC_UTILS:.c=.o))

##############
##	COLORS	##
##############

COLOR_RESET	=	\033[0m
COLOR_GREEN	=	\033[32m
COLOR_BLUE	=	\033[34m
COLOR_RED	=	\033[31m

##############
##  RULES	##
##############

all : $(LIBFT) $(STACKFT) $(NAME)

bonus : $(LIBFT) $(STACKFT) $(NAME_BONUS)

$(LIBFT) : 
	@make -sC $(LIBFT_PATH)

$(STACKFT) : 
	@make -sC $(STACKFT_PATH)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJ) $(LIBFT) $(STACKFT)
	@echo "$(COLOR_GREEN)COMPILE DONE !$(COLOR_RESET)"

$(NAME_BONUS) : $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT) $(STACKFT)
	@echo "$(COLOR_GREEN)COMPILE BONUS DONE !$(COLOR_RESET)"

clean :
	@rm -rf $(OBJ_DIR)
	@make -sC $(LIBFT_PATH) clean
	@make -sC $(STACKFT_PATH) clean

fclean : clean
	@rm -f norme_log
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make -sC $(LIBFT_PATH) fclean
	@make -sC $(STACKFT_PATH) fclean

norme:
	@echo "$(COLOR_BLUE)Norminette...$(COLOR_RESET)"
	@norminette $(SRC_DIR) $(INC) $(LIBFT_PATH) $(STACKFT_PATH) > norme_log ; \
	if grep -q "Error" norme_log; then \
		echo "$(COLOR_RED)Norme : KO!$(COLOR_RESET)"; \
	else \
		echo "$(COLOR_GREEN)Norme : OK!$(COLOR_RESET)"; \
	fi; \

re : fclean all

.PHONY: all clean fclean re norm bonus