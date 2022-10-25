NAME			= fdf
BONUS			= fdf

LIBFT_DIR		= libft
LIBFT			= libft.a
LINK_LIBFT		= -L $(LIBFT_DIR) $(LIBFT_DIR)/$(LIBFT)
INC_DIR_LIBFT	= -I $(LIBFT_DIR)/includes

BUILD_DEBUG		= 
BUILD_TARGET	= APPKIT

ifeq ($(BUILD_TARGET), APPKIT)
	LINK_MLX	= -L . -lmlx -framework OpenGL -framework AppKit
	DEF_TARGET	= -D BUILD_APPKIT
endif
ifeq ($(BUILD_TARGET), X11)
	LINK_MLX	= -L . -lmlx -lXext -lX11
	DEF_TARGET	= -D BUILD_X11
endif

LINK_LIBM		= -lm

LINK_LIBS		= $(LINK_LIBFT) $(LINK_MLX) $(LINK_LIBM)

INC_DIR			= -I . $(INC_DIR_LIBFT) -I includes

SRCNAME			= \
				parser/parser \
				parser/parse_map_info \
				parser/parse_map_content \
				arithmetic/multiply_m44_m44 \
				arithmetic/multiply_vertex_m44 \
				arithmetic/rotate_m44 \
				arithmetic/translate_m44 \
				geometry/matrix \
				geometry/map \
				projection/camera \
				projection/projection \
				display/display \
				display/display_putline \
				display/display_putbuffer \
				mlx_interface/state \
				fdf

SRCNAME_BONUS	= \
				debug/debug_matrix \
				debug/debug_camera \
				debug/debug_map \
				parser/parser \
				parser/parse_map_info \
				parser/parse_map_content \
				arithmetic/epsilon \
				arithmetic/multiply_m44_m44 \
				arithmetic/multiply_vertex_m44 \
				arithmetic/rotate_m44 \
				arithmetic/scale_m44 \
				arithmetic/translate_m44 \
				geometry/matrix \
				geometry/map \
				projection/camera \
				projection/camera_increment \
				projection/projection \
				display/display \
				display/display_putline \
				display/display_putbuffer \
				mlx_interface/keyboard \
				mlx_interface/state \
				fdf

SRC				= $(addprefix src/, $(addsuffix .c, $(SRCNAME)))
OBJ				= $(addprefix src/, $(addsuffix .o, $(SRCNAME)))
SRC_BONUS		= $(addprefix src_bonus/, $(addsuffix .c, $(SRCNAME_BONUS)))
OBJ_BONUS		= $(addprefix src_bonus/, $(addsuffix .o, $(SRCNAME_BONUS)))

RM				= rm -f
CC				= gcc
CFLAGS			= $(BUILD_DEBUG) -Wall -Werror -Wextra $(DEF_TARGET)

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
