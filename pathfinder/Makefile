NAME	=	pathfinder

CFLG	=	-std=c11 -Wall -Wextra -Werror -Wpedantic -g
COMP 	= 	clang

SRCD	=	src
INCD	=	inc
OBJD	=	obj

LMXD	=	libmx
LMXA:=	$(LMXD)/libmx.a
LMXI:=	$(LMXD)/inc

INC		=	path.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC		= 	mx_count_set.c mx_create_l.c mx_create_island.c mx_pI.c \
			mx_pop_front_island.c mx_pop_middle_island.c \
			mx_addIndexPathes.c mx_sortPath.c mx_join.c \
			mx_printOutput.c mx_delMat.c mx_create_path.c \
			mx_delPath.c mx_addPath.c mx_pushPath.c mx_copyPath.c \
			mx_uniquePath.c mx_check_empty_line.c mx_errors.c mx_parse.c \
			mx_create_arrarr.c mx_create_set.c mx_create_matrix.c \
			mx_print_mat.c mx_algo.c mx_shortest.c main.c

SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install clean

install: $(LMXA) $(NAME)

$(NAME): $(OBJS)
	@$(COMP) $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@$(COMP) $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

$(LMXA):
	@make -sC $(LMXD)

clean:
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)

uninstall: clean
	@make -sC $(LMXD) $@
	@rm -rf $(NAME)

reinstall: uninstall install
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)
