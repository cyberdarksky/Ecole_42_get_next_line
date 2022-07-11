NAME = libnext.a

SRCS = get_next_line.c get_next_line_utils.c
OBJS = ${SRCS:.c=.o}


$(NAME) : 
	gcc -c $(SRCS)
	ar rc $(NAME) $(OBJS)

all : $(NAME)

clean : 
	rm -rf $(OBJS) $(NAME)
re : clean all

.PHONY : all
