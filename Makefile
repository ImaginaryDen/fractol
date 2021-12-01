NAME		=	fractol
LIBFT		=	./libft/libft.a
PATH_HEADER =	./header/
PATH_LIB 	=	./libft/
HEADER  	=	./header/fractol.h
INC			=	/usr/include
INCLIB		=	$(INC)/../lib

SRCS_UTILS	=	$(shell ls ./utils/*.c)

SRCS		=	$(SRCS_UTILS) main.c
OBG			=	$(SRCS:%.c=%.o) $(LIBFT)

CFLAGS		=	-o3 #-Wall -Wextra -Werror 
LFLAGS		=	-L./mlx -lmlx -L$(INCLIB) -lXext -lX11 -lm 
RM			=	rm -rf
CC			=	gcc

UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
	INC		=	/usr/X11/include
endif

all:		run_libft $(NAME) 

$(NAME):	$(OBG)
			$(CC) -o $(NAME) ${OBG} $(LFLAGS) 

run_libft:	
			@make -sC ./mlx
			@make -sC $(PATH_LIB)

%.o: 		%.c $(PATH_HEADER)*
			$(CC) $(CFLAGS) -I$(PATH_HEADER) -Imlx -I$(INC) -c $< -o $@

clean:
			$(RM) ${OBG} ${OBG_BONUS}
			@make -sC $(PATH_LIB) clean

fclean:		clean
			$(RM) $(NAME) $(NAME_BONUS)
			@make -sC $(PATH_LIB) fclean

re:			fclean all

.PHONY: clean fclean re all