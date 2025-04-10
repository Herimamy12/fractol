NAME				:=	fractol

BONUS				:=	fractol_bonus

LIBFT				=	./libft/libft.a

LIBX				=	./minilibx-linux/libmlx.a

LIBXX				=	./minilibx-linux/libmlx_Linux.a

LIBFT_DIR			=	./libft/

LIBXDIR				=	./minilibx-linux/

SRC					=	./src/main.c ./src/new_data.c ./src/print.c \
						./src/destroy.c ./src/new_img.c ./src/loop.c \
						./src/draw.c ./src/hook.c ./src/setters_type.c \
						./src/mouse.c

SRC_BONUS			=	./src_bonus/main.c ./src_bonus/new_data.c ./src_bonus/print.c \
						./src_bonus/destroy.c ./src_bonus/new_img.c ./src_bonus/loop.c \
						./src_bonus/draw.c ./src_bonus/hook.c ./src_bonus/setters_type.c \
						./src_bonus/mouse.c

CC					=	cc -Wall -Werror -Wextra

XFLAGS				=	-lXext -lX11 -lm -lbsd

OBJ_DIR				=	obj

OBJ_DIR_B			=	obj_bonus

OBJ					=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir ${SRC}))

OBJ_BONUS			=	$(patsubst %.c, $(OBJ_DIR_B)/%.o, $(notdir ${SRC_BONUS}))

${shell mkdir -p ${OBJ_DIR}}

${shell mkdir -p ${OBJ_DIR_B}}

${OBJ_DIR}/%.o		:	./src/%.c
						@${CC} -o $@ -c $<

${OBJ_DIR_B}/%.o	:	./src_bonus/%.c
						@${CC} -o $@ -c $<

all					:	$(NAME)

bonus				:	$(BONUS)

$(NAME)				:	$(OBJ)
						@make --no-print-directory -C $(LIBXDIR)
						@make --no-print-directory -C $(LIBFT_DIR)
						@$(CC) -o $@ $^ $(LIBFT) $(LIBX) $(LIBXX) $(XFLAGS)
						@rm -rf $(OBJ_DIR_B)
						@echo "Fractol :: Compilation successfully."

$(BONUS)			:	$(OBJ_BONUS)
						@make --no-print-directory -C $(LIBXDIR)
						@make --no-print-directory -C $(LIBFT_DIR)
						@$(CC) -o $@ $^ $(LIBFT) $(LIBX) $(LIBXX) $(XFLAGS)
						@echo "Fractol_bonus :: Compilation successfully."

clean				:
						@make clean --no-print-directory -C ${LIBXDIR}
						@make clean --no-print-directory -C ${LIBFT_DIR}
						@rm -rf $(OBJ_DIR) $(OBJ_DIR_B)
						@echo "Fractol :: Clean successfully."

fclean				:	clean
						@make fclean --no-print-directory -C ${LIBFT_DIR}
						@rm -f $(NAME) $(BONUS)
						@echo "Fractol :: Fclean successfully."

re					:	fclean
						@make --no-print-directory -C ./

.PHONY				:	all bonus clean fclean re
