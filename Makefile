NAME			= fdf
BONUS			= 

LIBFT_DIR		= libft
LIBFT			= libft.a
LINK_LIBFT		= -L $(LIBFT_DIR) $(LIBFT_DIR)/$(LIBFT)
INC_DIR_LIBFT	= -I $(LIBFT_DIR)

LINK_MINILIBX	= -L . -lmlx -lXext -lX11

INC_DIR			= -I . $(INC_DIR_LIBFT) -I includes

SRCNAME			= \
				src/epsilon \
				src/consts \
				src/matrix_multiply \
				src/matrix \
				src/translate \
				src/vertex_matrix_multiply \
				src/camera \
				test_camera \
				src/matrix_debug \
				src/camera_debug

SRCNAME_BONUS	= \

SRC				= $(addsuffix .c, $(SRCNAME))
OBJ				= $(addsuffix .o, $(SRCNAME))
SRC_BONUS		= $(addsuffix .c, $(SRCNAME_BONUS))
OBJ_BONUS		= $(addsuffix .o, $(SRCNAME_BONUS))

RM				= rm -f
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(INC_DIR) $(OBJ) $(LINK_LIBFT) $(LINK_MINILIBX) -o $(NAME)

bonus : $(LIBFT) $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(INC_DIR) $(OBJ_BONUS) $(LINK_LIBFT) $(LINK_MINILIBX) -o $(BONUS)

$(LIBFT) :
	make -C $(LIBFT_DIR)/

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
