##
## Makefile for Makefile in /home/dewulf_f//afs/Igraph/fdf
## 
## Made by florian dewulf
## Login   <dewulf_f@epitech.net>
## 
## Started on  Mon Dec  5 13:12:27 2011 florian dewulf
## Last update Fri Mar  2 15:28:01 2012 florian dewulf
##

NAME=	fdf

SRC=	gere.c \
	fdf.c \
	my_getnbr.c \
	func.c \
	get_next_line.c \
	put_tab.c \
	main.c

OBJ=	$(SRC:.c=.o)

FLAG=	-L/usr/X11/lib -lmlx_$(HOSTTYPE) -lXext -lX11

all:	$(OBJ)
	cc -o $(NAME) $(SRC) $(FLAG)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME) $(OBJ)

re:	fclean all