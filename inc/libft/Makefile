# -----------------------------------------------------
#						Color
# -----------------------------------------------------

# Black        0;30     Dark Gray     1;30
# Red          0;31     Light Red     1;31
# Green        0;32     Light Green   1;32
# Brown/Orange 0;33     Yellow        1;33
# Blue         0;34     Light Blue    1;34
# Purple       0;35     Light Purple  1;35
# Cyan         0;36     Light Cyan    1;36
# Light Gray   0;37     White         1;37
#
BLUE='\033[1;34m'
RED='\033[0;31m'
OR='\033[0;33m'
NC='\033[0m'
GREEN='\033[0;32m'
LRED='\033[1;31m'
LGREEN='\033[1;32m'
LBLUE='\033[1;34m'
BLACK='\033[0;30m'
LGRAY='\033[0;37m'
WHITE='\033[1;37m'

# -----------------------------------------------------
#						Path/Name
# -----------------------------------------------------

NAME			= libft.a

SRC_DIR			= ./src
OBJ_DIR			= ./obj
INC_DIR			= ./inc

# -----------------------------------------------------
#						VAR
# -----------------------------------------------------

MAKE			= make -sC
MAKEFLAGS		:=	--no-print-directory
CC				= gcc -g
CFLAGS			= -Wall -Werror -Wextra
RM				= rm -f

# -----------------------------------------------------
#					OBJS/SRCS/Libary
# -----------------------------------------------------

SRC			= ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
				ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
				ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
				ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c  \
				ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
				ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
				ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c \
				ft_printf.c ft_write_format_c.c ft_write_format_int.c \
				ft_utils.c ft_write_format_percent.c ft_write_format_s.c \
				ft_write_format_p.c ft_write_format_x.c ft_write_format_x2.c \
				ft_write_format_u.c get_next_line.c get_next_line_utils.c

SRCS			= $(addprefix $(SRC_DIR)/, $(SRC))

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
				@echo $(GREEN)"Compiling:"$(NC) $(notdir $<)
				$(CC) $(CFLAGS) -c $< -o $@

OBJS			=  $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# -----------------------------------------------------
#						Compilation
# -----------------------------------------------------

all :			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)
				@cat libft_text.txt
				
# -----------------------------------------------------
#						Rules
# ----------------------------------------------------- 

clean:
				$(RM) obj/*.o
				echo $(LRED)"LIBFT clean"$(NC)
 
fclean:			clean
				$(RM) $(NAME)
 
re:				fclean $(NAME)  

.SILENT:		all clean fclean re $(NAME) $(OBJS)

.PHONY:			all clean fclean re
