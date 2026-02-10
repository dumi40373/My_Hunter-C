##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

SRC	=	execute.c	\
		create_rect.c	\
		create_window.c	\
		manage_hitbox.c	\
		events_analyse.c	\
		create_sprites.c	\
		sprites_time.c	\
		win_lose_verif.c	\
		create_textures.c	\
		my_lib.c	\
		destroy.c	\

OBJ	=	$(SRC:.c=.o)

all: exe

exe: $(OBJ)
	ar rc libmy.a $(OBJ)
	cp libmy.a ../
	cp my.h ../../include/

$(OBJ): $(SRC)
	epiclang -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f libmy.a

re: fclean all