NAME	=	my_runner

SRC	=	src/main.c \
		src/my_revstr.c	\
		src/my_getchar.c	\
		src/game/launcher.c	\
		src/game/init_game.c	\
		src/game/create_window.c	\
		src/game/game.c	\
		src/menu/menu.c	\
		src/menu/manage_event_menu.c	\
		src/menu/anim_button_menu.c	\
		src/game/destroy_game.c	\
		src/game/move_sky_and_background.c	\
		src/game/move_foreground_and_player.c	\
		src/game/anim_player_jump.c	\
		src/game/move_life_and_end_game.c	\
		src/game/move_npc.c	\
		src/game/finish_game.c	\
		src/game/launch_end.c

OBJ	=	$(SRC:.c=.o)

CPPFLAGS	=	-I include

CFLAGS	=	-Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

clean:
	-rm src/*~
	-rm $(OBJ)
fclean:
	-rm $(NAME)
	-rm $(OBJ)

re:	fclean all

.PHONY:	all clean fclean re
