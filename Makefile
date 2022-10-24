NAME			= fdf
BONUS			= 

LIBFT_DIR		= libft
LIBFT			= libft.a
LINK_LIBFT		= -L $(LIBFT_DIR) $(LIBFT_DIR)/$(LIBFT)
INC_DIR_LIBFT	= -I $(LIBFT_DIR)

LINK_MLX		= -L . -lmlx -lXext -lX11
LINK_MLX_		= -L . -lmlx -framework OpenGL -framework AppKit

LINK_LIBM		= -lm

LINK_LIBS		= $(LINK_LIBFT) $(LINK_MLX) $(LINK_LIBM)

INC_DIR			= -I . $(INC_DIR_LIBFT) -I includes

SRCNAME			= \
				src/debug/debug_matrix \
				src/debug/debug_camera \
				src/debug/debug_map \
				src/test_drivers/make_cube \
				src/arithmetic/epsilon \
				src/arithmetic/multiply_m44_m44 \
				src/arithmetic/multiply_vertex_m44 \
				src/arithmetic/rotate_m44 \
				src/arithmetic/scale_m44 \
				src/arithmetic/translate_m44 \
				src/geometry/matrix \
				src/geometry/map \
				src/projection/camera \
				src/projection/projection \
				src/display/display \
				src/display/display_putline \
				src/display/display_putbuffer \
				src/mlx_interface/keyboard \
				src/mlx_interface/state \
				src/fdf

SRCNAME_BONUS	= \

SRC				= $(addsuffix .c, $(SRCNAME))
OBJ				= $(addsuffix .o, $(SRCNAME))
SRC_BONUS		= $(addsuffix .c, $(SRCNAME_BONUS))
OBJ_BONUS		= $(addsuffix .o, $(SRCNAME_BONUS))

RM				= rm -f
CC				= gcc
CFLAGS			= -g -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(INC_DIR) $(OBJ) $(LINK_LIBS) -o $(NAME)

bonus : $(LIBFT) $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(INC_DIR) $(OBJ_BONUS) $(LINK_LIBS) -o $(BONUS)

$(LIBFT) :
	make -s -C $(LIBFT_DIR)/

%.o : %.c
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

clean :
	$(RM) $(OBJ) $(OBJ_BONUS) $(NAME).o $(BONUS).o
	make clean -C $(LIBFT_DIR)

fclean : clean
	$(RM) $(NAME) $(BONUS)
	make fclean -C $(LIBFT_DIR)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re $(NAME) bonus
