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

#===RREMOTE_REPSITORY===#

REMOTE_REPSITORY = $(shell git remote)


#===COLOR===#

RED				:=	"\033[1;31m"
GREEN			:=	"\033[1;32m"
CYAN			:=	"\033[1;35m"
BLUE			:=	"\033[1;36m"
PURPLE          :=	"\033[1;34m"
YELLOW			:=	"\033[1;33m"
PINK            :=	"\033[38;5;206m"
BOLD	   		:=  "\033[1m"
EOC				:=	"\033[0;0m"

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

#https://www.nooozui.com/entry/20200129/1580277274
git:
	@echo "remote repository :"
	@echo ""
	@echo $(REMOTE_REPSITORY)
	@echo ""
	@read -p "select ->" REPOSITORY ;\
	read -p "write commit message : " MESSAGE;\
	git add -A ;\
	git commit -m "$$MESSAGE";\
	git push $$REPOSITORY;

test:

-include $(DEP)

