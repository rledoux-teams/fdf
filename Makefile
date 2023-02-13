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
WHITE='\033[1;37m'

# -----------------------------------------------------
#						Path/Name
# -----------------------------------------------------

NAME			= fdf

SRC_DIR			= ./src
OBJ_DIR			= ./obj
INC_DIR			= ./inc
LFT_DIR			= ./inc/libft
MLX_DIR			= ./inc/MLX42

# -----------------------------------------------------
#						VAR
# -----------------------------------------------------

MAKE			= make -sC
CC				= gcc -g
CFLAGS			= -Wall -Werror -Wextra
MLXFLAGS		= -ldl -lglfw -pthread -lm
LFLAGS			= -L./inc/libft/ $(LFT) -L./inc/MLX42/ $(MLX)
RM				= rm -f

# -----------------------------------------------------
#					OBJS/SRCS/Libary
# -----------------------------------------------------

SRC				= ft_fdf.c \
				  ft_maps.c \
				  ft_maps_utils.c \
				  ft_color.c \
				  ft_mlx.c \
				  ft_screen.c \
				  ft_mlx_utils.c

SRCS			= $(addprefix $(SRC_DIR)/, $(SRC))

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@echo -e $(GREEN)Compiling:$(NC) $(notdir $<)
	$(CC) $(CFLAGS) -c $< -o $@

OBJS			=  $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


# -----------------------------------------------------
#						Compilation
# -----------------------------------------------------

all :			$(LFT) $(MLX) $(NAME)

$(NAME):		$(OBJS)
				make -C inc/libft/ all
				make -C inc/MLX42/ all
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L inc/libft -lft -L inc/MLX42 -lmlx42 -L/usr/lib -lXext -lX11 -lm -lz $(MLXFLAGS)
# -----------------------------------------------------
#						Rules
# ----------------------------------------------------- 

clean:
				$(MAKE) $(LFT_DIR) clean
				$(MAKE) $(MLX_DIR) clean
				$(RM) obj/*.o
				@echo $(LRED)"Clean fdf !"$(NC)
 
fclean:			clean
				$(MAKE) $(LFT_DIR) fclean
				$(MAKE) $(MLX_DIR) fclean
				$(RM) $(NAME)
 
re:				fclean $(NAME)  

.SILENT:		all clean fclean re LFT MLX $(NAME) $(OBJS)

.PHONY:			all clean fclean re



