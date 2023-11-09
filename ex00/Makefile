#===PROGRAM===#

NAME = Megaphone

#===COMPILER===#

COMPILER = c++

#===COMPILE_OPTION===#

WARN_FLAG = -Wall -Wextra -Werror
STD_FLAG = -std=c++98
DEP_FLAG = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d
CPP_FLAG = $(WARN_FLAG) $(STD_FLAG)

#===RM====#

RM = rm -rf

#===DIRECTORY===#

SRCDIR = ./src
OBJDIR = ./obj
DEPDIR = ./dep

#===FILE===#

SRC = $(shell find $(SRCDIR) -name "*.cpp")
OBJ = $(patsubst $(SRCDIR)%.cpp, $(OBJDIR)%.o, $(SRC))
DEP = $(patsubst $(SRCDIR)%.cpp, $(DEPDIR)%.d, $(SRC))
vpath %.cpp $(SRCDIR)

#===RULES===#

all: $(OBJDIR) $(DEPDIR) $(NAME) 


$(OBJDIR):
	@mkdir -p $@

$(DEPDIR):
	@mkdir -p $@

$(NAME): $(OBJ) 
	$(COMPILER) $(CPP_FLAG) -c $(OBJ) -o $@

$(OBJDIR)/%.o: %.cpp
	$(COMPILER) $(CPP_FLAG) $(DEP_FLAG) -c $< -o $@

clean:
	$(RM) $(OBJDIR) $(DEPDIR)

fclean:clean
	$(RM) $(NAME)

re:fclean all

git:
	@read -p "write commit message :" MESSAGE;\
    git add .; \
    git commit -m "$$MESSAGE"; \
	git push

-include $(DEP)
