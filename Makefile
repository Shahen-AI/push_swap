NAME = push_swap

LFT_DIR = ./libft
LFT = $(LFT_DIR)/libft.a
LFT_FLAGS = -L. -lft
CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
PS_FILES = main.c \
			source/parse_arg.c \
			source/parse_arg2.c \
			source/step_actions.c \
			source/error.c \
			source/utils.c \
			source/sorting.c \

RM = rm -rf
# PS_OBJS = ${PS_FILES:.c=.o}

all : $(NAME)

$(NAME) : $(LFT_DIR) ./$(NAME)
	@cd $(LFT_DIR) && $(MAKE) all && mv libft.a ../
	$(CC)  $(LFT_FLAGS) -o $(NAME) $(PS_FILES) 

clean : 
	@cd $(LFT_DIR) && $(MAKE) clean

fclean : 
	$(MAKE) clean
	$(RM) ./libft.a
	$(RM) ./$(NAME)

re : fclean all

push : 
	$(MAKE) fclean
	git add .
	git commit -m "some message"
	git push