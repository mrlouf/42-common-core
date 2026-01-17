# -=-=-=-=-    NAME -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= #

NAME 		= moreForms

# -=-=-=-=-    FLAG -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= #

CC			= c++
FLAGS		= -Werror -Wall -Wextra -std=c++98 -Wshadow -pedantic -fsanitize=address -fsanitize=leak

RM			= rm -fr

# -=-=-=-=-    FILES -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

SRC 		= 	AForm.cpp					\
				main.cpp					\
				RobotomyRequestForm.cpp		\
				Bureaucrat.cpp				\
				PresidentialPardonForm.cpp	\
				ShrubberyCreationForm.cpp


HEADERS		=	AForm.hpp					\
				PresidentialPardonForm.hpp	\
				ShrubberyCreationForm.hpp	\
				Bureaucrat.hpp				\
				RobotomyRequestForm.hpp

OBJDIR		= .obj
OBJS		= $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

# -=-=-=-=-    TARGETS -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- #

all: $(NAME)

$(OBJDIR)/%.o: %.cpp Makefile $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -I. -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean: 
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME) Oktorok_shrubbery

re: fclean all

.PHONY: all clean fclean re