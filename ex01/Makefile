#===PROGRAM===#

NAME = PhoneBook

#===COMPILER===#

COMPILER = c++

#===COMPILE_OPTION===#

WARN_FLAG = -Wall -Wextra -Werror -Wconversion -Wshadow
STD_FLAG = -std=c++98
DEP_FLAG = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d
INCLUDE_FLAG = -I

CXX_FLAG = $(STD_FLAG) $(WARN_FLAG)

#===RM===#

RM = rm -rf

#===DIRECTORY===#

SRCDIR = ./srcs
SRC_SUBDIR = $(shell find $(SRCDIR) -type d)
OBJDIR = ./objs
OBJ_SUBDIR = $(patsubst $(SRCDIR)%, $(OBJDIR)%, $(SRC_SUBDIR))
DEPDIR = ./deps
DEP_SUBDIR = $(patsubst $(SRCDIR)%, $(DEPDIR)%, $(SRC_SUBDIR))
INCDIR = ./include

#===FILE===#

SRC = $(shell find $(SRCDIR) -name "*.cpp" -type f )
OBJ = $(patsubst $(SRCDIR)%.cpp, $(OBJDIR)%.o, $(SRC))
DEP = $(patsubst $(SRCDIR)%.cpp, $(DEPDIR)%.d, $(SRC))
vpath %.cpp $(SRCDIR) : $(SRCDIR)*

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

all: $(DEPDIR) $(NAME) 


$(DEPDIR):
	##@mkdir -p $@/src2
	mkdir -p $(DEP_SUBDIR)

$(NAME): $(OBJ) 
	$(COMPILER) $(CPP_FLAG) $(OBJ) -o $@

#https://qiita.com/progrunner/items/9687ff35c364f3d864e3
$(OBJ): | $(OBJDIR)

$(OBJDIR):
	##@mkdir -p $@/src2
	@mkdir -p $(OBJ_SUBDIR)

$(OBJDIR)/%.o: %.cpp
	$(COMPILER) $(CXX_FLAG) $(DEP_FLAG) $(INCLUDE_FLAG) $(INCDIR) -c $< -o $@

clean:
	$(RM) $(OBJDIR) $(DEPDIR)

fclean:clean
	$(RM) $(NAME)

re:fclean all

#https://www.nooozui.com/entry/20200129/1580277274
git:
	@echo "remote repository :"
	@echo ""
	@git remote -v | grep '(push)' | cut -d ' ' -f 1
	@echo ""
	@read -p "select ->" REPOSITORY ;\
	read -p "write commit message : " MESSAGE;\
	git add -A ;\
	git commit -m "$$MESSAGE";\
	git push $$REPOSITORY;


HAS_TREE = $(shell brew list | grep "tree")

ifeq ($(HAS_TREE),)
    TREE_CMD = @pwd;find . | sort | sed '1d;s/^\.//;s/\/\([^/]*\)$$/|--\1/;s/\/[^/|]*/|  /g'
else
    TREE_CMD := @tree
endif

tree:
	$(TREE_CMD)


-include $(DEP)

