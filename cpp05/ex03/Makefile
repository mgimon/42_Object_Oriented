NAME = bureaucrat

SRCS = main.cpp Bureaucrat.cpp AForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp Intern.cpp

HEADER = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp

CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g #-fsanitize=address -fsanitize=leak

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
