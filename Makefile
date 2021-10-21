NAME		=	fractol
LIBFT		=	./libft/libft.a
PATH_HEADER =	./header/
PATH_LIB 	=	./libft/
HEADER  	=	./header/fractol.h

SRCS_UTILS	=	$(shell ls ./utils/*.c)

SRCS		=	$(SRCS_UTILS) main.c
OBG			=	$(SRCS:%.c=%.o)

CFLAGS		=	-Wall -Wextra -Werror 
RM			=	rm -rf
CC			=	gcc

all:		run_libft $(NAME) 

$(NAME):	${OBG} $(HEADER) $(LIBFT)
			$(CC) -lmlx -framework OpenGL -framework AppKit ${OBG} -o $(NAME)

run_libft:	
			@make -C $(PATH_LIB)

%.o: 		%.c	
			$(CC) $(CFLAGS) -I$(PATH_HEADER) -c $< -o $@

clean:
			$(RM) ${OBG} ${OBG_BONUS}
			@make -C $(PATH_LIB) clean

fclean:		clean
			$(RM) $(NAME) $(NAME_BONUS)
			@make -C $(PATH_LIB) fclean

re:			fclean all

.PHONY: clean fclean re all