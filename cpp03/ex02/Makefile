NAME = claptrap

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

HEADER = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g #-fsanitize=address

%.o: %.cpp Makefile ${HEADER}
		${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.cpp=.o}

all:
		@$(MAKE) ${NAME} --no-print-directory

${NAME}:: ${OBJS}
	${CC} $(CFLAGS) $(OBJS) -o ${NAME}

clean:
			${RM} ${OBJS}

fclean: clean 
			${RM} ${OBJS} ${NAME}

re: 
			$(MAKE) fclean
			$(MAKE) all

.PHONY: all clean fclean re
