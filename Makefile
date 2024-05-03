# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbrousse <jbrousse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 20:01:31 by jbrousse          #+#    #+#              #
#    Updated: 2024/01/31 13:52:48 by jbrousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##############
##`COMPILER	##
##############

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -g3 -O3


###############
##	  LIB	 ##
###############

LIBFT_DIR	=	libft/
LIBFT		=	$(LIBFT_DIR)libft.a

STACKFT_DIR	=	StackFT/
STACKFT		=	$(STACKFT_DIR)stackft.a

###############
##	INCLUDE	 ##
###############

INCLUDE_DIR	=	include/
INCLUDES	=	-I includes \
				-I $(LIBFT_DIR)includes \
				-I $(STACKFT_DIR)includes
			
##############
##  SOURCE	##
##############

SRC_DIR			=	sources/
SRC_UTILS		=	parse.c		\
					pslang.c	\
					utils.c

SRC_MANDATORY_DIR	=	mandatory/
SRC_MANDATORY_LIST	=	divide_algo.c	\
						medians.c		\
						ps_utils.c		\
						push_swap.c		\
						turkish_algo.c	\
						turkish_utils.c
SRC_MANDATORY_PRE	=	$(addprefix $(SRC_MANDATORY_DIR), $(SRC_MANDATORY_LIST))

SRC_BONUS_DIR		=	bonus/
SRC_BONUS_LIST		=	checker_bonus.c		\
						reader_bonus.c
SRC_BONUS_PRE		=	$(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS_LIST))


SRC_BONUS			=	$(addprefix $(SRC_DIR), $(SRC_BONUS_PRE))		\
						$(addprefix $(SRC_DIR), $(SRC_UTILS))

SRC_MANDATORY		=	$(addprefix $(SRC_DIR), $(SRC_MANDATORY_PRE))	\
						$(addprefix $(SRC_DIR), $(SRC_UTILS))
			

##################
##   OBJ/NAME	##
##################

NAME		=	push_swap
NAME_BONUS	=	checker

OBJ_DIR	=	obj/
OBJ		=	$(addprefix $(OBJ_DIR), $(SRC_MANDATORY_PRE:.c=.o))	\
			$(addprefix $(OBJ_DIR), $(SRC_UTILS:.c=.o))

OBJ_BONUS = $(addprefix $(OBJ_DIR), $(SRC_BONUS_PRE:.c=.o))		\
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
	@make -sC $(LIBFT_DIR) all

$(STACKFT) : 
	@make -sC $(STACKFT_DIR) all

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_BONUS_DIR)
	@mkdir -p $(OBJ_DIR)$(SRC_MANDATORY_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBFT) $(STACKFT)
	@echo "$(COLOR_GREEN)COMPILE DONE !$(COLOR_RESET)"

$(NAME_BONUS) : $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT) $(STACKFT)
	@echo "$(COLOR_GREEN)COMPILE BONUS DONE !$(COLOR_RESET)"

clean :
	@rm -rf $(OBJ_DIR)
	@make -sC $(LIBFT_DIR) clean
	@make -sC $(STACKFT_DIR) clean

fclean : clean
	@rm -f norme_log
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make -sC $(LIBFT_DIR) fclean
	@make -sC $(STACKFT_DIR) fclean

norme:
	@echo "$(COLOR_BLUE)Norminette...$(COLOR_RESET)"
	@norminette $(SRC_DIR) $(INCLUDES_DIR) $(LIBFT_DIR) $(STACKFT_DIR) > norme_log ; \
	if grep -q "Error" norme_log; then \
		echo "$(COLOR_RED)Norme : KO!$(COLOR_RESET)"; \
	else \
		echo "$(COLOR_GREEN)Norme : OK!$(COLOR_RESET)"; \
	fi; \

re : fclean all

.PHONY: all clean fclean re norm bonus