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

CFLAGS		=	#-Wall -Wextra -Werror
LFLAGS		=	-L./mlx_linux -lmlx -L$(INCLIB) -lXext -lX11 -lm
RM			=	rm -rf
CC			=	gcc

all:		run_libft $(NAME) 

$(NAME):	${OBG} $(HEADER)
			$(CC) -o $(NAME) ${OBG} $(LFLAGS) 

run_libft:	
			@make -C $(PATH_LIB)

%.o: 		%.c	
			$(CC) $(CFLAGS) -I$(PATH_HEADER) -Imlx_linux -I$(INC) -c $< -o $@

clean:
			$(RM) ${OBG} ${OBG_BONUS}
			@make -C $(PATH_LIB) clean

fclean:		clean
			$(RM) $(NAME) $(NAME_BONUS)
			@make -C $(PATH_LIB) fclean

re:			fclean all

.PHONY: clean fclean re all