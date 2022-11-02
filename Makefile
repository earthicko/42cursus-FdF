NAME			= fdf
################################# LIBRARIES ####################################
LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a
LINK_LIBFT		= -L$(LIBFT_DIR)
INC_DIR_LIBFT	= -I$(LIBFT_DIR)/includes

LIBMLX_DIR		= minilibx_macos
LIBMLX			= $(LIBMLX_DIR)/libmlx.a
LINK_LIBMLX		= -L$(LIBMLX_DIR) -framework OpenGL -framework AppKit
INC_DIR_LIBMLX	= -I$(LIBMLX_DIR)

LINK_LIBM		= -lm

LINK_LIBS		= $(LINK_LIBFT) $(LINK_LIBMLX) $(LINK_LIBM)

INC_DIR_M		= -I. $(INC_DIR_LIBFT) $(INC_DIR_LIBMLX) -Iincludes_mandatory
INC_DIR_B		= -I. $(INC_DIR_LIBFT) $(INC_DIR_LIBMLX) -Iincludes_bonus
################################# COMMANDS #####################################
RM				= rm -f
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -MMD -MP
################################ FILENAMES #####################################
NAME_M			= \
				parser/parser \
				parser/parse_map_info \
				parser/parse_map_content \
				parser/vertexarr \
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

NAME_B			= \
				parser/parser_bonus \
				parser/parse_map_info_bonus \
				parser/parse_map_content_bonus \
				parser/vertexarr_bonus \
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

SRC_M			= $(addprefix src_mandatory/, $(addsuffix .c, $(NAME_M)))
OBJ_M			= $(addprefix src_mandatory/, $(addsuffix .o, $(NAME_M)))
DEP_M			= $(addprefix src_mandatory/, $(addsuffix .d, $(NAME_M)))
STAT_M			= mandatory.log

SRC_B			= $(addprefix src_bonus/, $(addsuffix .c, $(NAME_B)))
OBJ_B			= $(addprefix src_bonus/, $(addsuffix .o, $(NAME_B)))
DEP_B			= $(addprefix src_bonus/, $(addsuffix .d, $(NAME_B)))
STAT_B			= bonus.log
################################# SRC SET ######################################
ifdef TARGET
ifeq ($(TARGET), MANDATORY)
SRC				= $(SRC_M)
OBJ				= $(OBJ_M)
DEP				= $(DEP_M)
INC_DIR			= $(INC_DIR_M)
STAT			= $(STAT_M)
endif
ifeq ($(TARGET), BONUS)
SRC				= $(SRC_B)
OBJ				= $(OBJ_B)
DEP				= $(DEP_B)
INC_DIR			= $(INC_DIR_B)
STAT			= $(STAT_B)
endif
else
SRC				= $(SRC_M)
OBJ				= $(OBJ_M)
DEP				= $(DEP_M)
INC_DIR			= $(INC_DIR_M)
STAT			= $(STAT_M)
endif
################################# TARGETS ######################################
all:
	@make TARGET=MANDATORY $(NAME)

bonus:
	@make TARGET=BONUS $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(OBJ) $(STAT)
	$(CC) $(CFLAGS) $(INC_DIR) $(LINK_LIBS) $(LIBFT) $(LIBMLX) $(OBJ) -o $@

$(LIBFT):
	@make -j4 -C $(LIBFT_DIR)/

$(LIBMLX):
	@make -j4 -C $(LIBMLX_DIR)/

$(STAT_M): $(OBJ_M)
	rm -f $(STAT_B)
	touch $(STAT_M)

$(STAT_B): $(OBJ_B)
	rm -f $(STAT_M)
	touch $(STAT_B)

-include $(DEP)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

clean:
	$(RM) $(OBJ_M) $(OBJ_B) $(DEP_M) $(DEP_B) $(STAT_M) $(STAT_B)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS)
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(LIBMLX_DIR)

re:
	@make fclean
	@make all

.PHONY: all bonus clean fclean re
