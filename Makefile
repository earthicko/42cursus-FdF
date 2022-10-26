NAME			= fdf
BONUS			= fdf

LIBFT_DIR		= libft
LIBFT			= libft.a
LINK_LIBFT		= -L $(LIBFT_DIR) $(LIBFT_DIR)/$(LIBFT)
INC_DIR_LIBFT	= -I $(LIBFT_DIR)/includes

LIBMLX_DIR		= minilibx_macos
LIBMLX			= libmlx.a
LINK_LIBMLX		= -L $(LIBMLX_DIR) $(LIBMLX_DIR)/$(LIBMLX) -framework OpenGL -framework AppKit
INC_DIR_LIBMLX	= -I $(LIBMLX_DIR)

LINK_LIBM		= -lm

LINK_LIBS		= $(LINK_LIBFT) $(LINK_LIBMLX) $(LINK_LIBM)

INC_DIR			= -I . $(INC_DIR_LIBFT) -I includes
INC_DIR_BONUS	= -I . $(INC_DIR_LIBFT) -I includes_bonus

SRCNAME			= \
				parser/parser \
				parser/parse_map_info \
				parser/parse_map_content \
				arithmetic/multiply_m44 \
				arithmetic/rotate_m44 \
				arithmetic/translate_m44 \
				geometry/matrix \
				geometry/map \
				display/camera \
				display/projection \
				display/display \
				display/display_putline \
				display/display_putbuffer \
				mlx_interface/mlx_interface \
				fdf

SRCNAME_BONUS	= \
				parser/parser_bonus \
				parser/parse_map_info_bonus \
				parser/parse_map_content_bonus \
				arithmetic/multiply_m44_bonus \
				arithmetic/rotate_m44_bonus \
				arithmetic/translate_m44_bonus \
				geometry/matrix_bonus \
				geometry/map_bonus \
				display/camera_bonus \
				display/camera_increment_bonus \
				display/project_to_camera_bonus \
				display/project_to_display_bonus \
				display/display_bonus \
				display/display_putline_bonus \
				display/display_putbuffer_bonus \
				mlx_interface/keyboard_bonus \
				mlx_interface/state_bonus \
				fdf_bonus

SRC				= $(addprefix src/, $(addsuffix .c, $(SRCNAME)))
OBJ				= $(addprefix src/, $(addsuffix .o, $(SRCNAME)))
SRC_BONUS		= $(addprefix src_bonus/, $(addsuffix .c, $(SRCNAME_BONUS)))
OBJ_BONUS		= $(addprefix src_bonus/, $(addsuffix .o, $(SRCNAME_BONUS)))

RM				= rm -f
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(LIBFT) $(LIBMLX) $(OBJ)
	@$(CC) $(CFLAGS) $(INC_DIR) $(OBJ) $(LINK_LIBS) -o $(NAME)

bonus : $(LIBFT) $(LIBMLX) $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(INC_DIR_BONUS) $(OBJ_BONUS) $(LINK_LIBS) -o $(BONUS)

$(LIBFT) :
	make -s -C $(LIBFT_DIR)/

$(LIBMLX) :
	make -s -C $(LIBMLX_DIR)/

src/%.o : src/%.c
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

src_bonus/%.o : src_bonus/%.c
	$(CC) $(CFLAGS) $(INC_DIR_BONUS) -c $< -o $@

clean :
	$(RM) $(OBJ) $(OBJ_BONUS) $(NAME).o $(BONUS).o
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBMLX_DIR)

fclean : clean
	$(RM) $(NAME) $(BONUS)
	make fclean -C $(LIBFT_DIR)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re $(NAME) bonus
