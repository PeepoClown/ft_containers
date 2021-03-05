NAME = containers
CXX = clang++
CXXFLAGS = -MMD -Wall -Wextra -Werror -std=c++98 -I Utils/

SRCDIR = srcs/
OBJDIR = objs/
OBJS = mapTest.o \
	   multimapTest.o \
	   setTest.o \
	   multisetTest.o \
	   main.o

OBJ = $(addprefix $(OBJDIR),$(OBJS))

.PHONY: all
all: $(OBJDIR) $(NAME)
	@printf "\e[1;34mContainers built\e[0m\n"

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@printf "\e[1;32mDONE\e[0m\n"

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: clean
clean:
	rm -rf $(OBJDIR)
	@printf "\e[1;33mCLEAN\e[0m\n"

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)
	@printf "\e[1;31mFCLEAN\e[0m\n"

.PHONY: re
re: fclean all

-include $(OBJ:.o=.d)
