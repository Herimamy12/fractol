CC				=	gcc -Wall -Wextra -Werror -g

NAME			=	libft.a

SRCS			=	./src/ft_atoi.c ./src/ft_isdigit.c ./src/ft_memmove.c ./src/ft_split.c ./src/ft_strlcpy.c \
					./src/ft_strtrim.c ./src/ft_bzero.c ./src/ft_isprint.c ./src/ft_memset.c ./src/ft_strchr.c \
					./src/ft_strlen.c ./src/ft_substr.c ./src/ft_calloc.c ./src/ft_itoa.c ./src/ft_putchar_fd.c \
					./src/ft_strdup.c ./src/ft_strmapi.c ./src/ft_tolower.c ./src/ft_isalnum.c ./src/ft_memchr.c \
					./src/ft_putendl_fd.c ./src/ft_striteri.c ./src/ft_strncmp.c  ./src/ft_toupper.c \
					./src/ft_isalpha.c ./src/ft_memcmp.c  ./src/ft_putnbr_fd.c  ./src/ft_strjoin.c  ./src/ft_strnstr.c \
					./src/ft_isascii.c ./src/ft_memcpy.c  ./src/ft_putstr_fd.c  ./src/ft_strlcat.c  ./src/ft_strrchr.c \
					./src/ft_lstadd_back_bonus.c ./src/ft_lstadd_front_bonus.c ./src/ft_lstmap_bonus.c \
					./src/ft_lstsize_bonus.c ./src/ft_lstnew_bonus.c ./src/ft_lstclear_bonus.c \
					./src/ft_lstlast_bonus.c ./src/ft_lstdelone_bonus.c ./src/ft_lstiter_bonus.c \
					./src/get_next_line_bonus.c ./src/get_next_line_utils_bonus.c \
					./src/ft_printf.c ./src/ft_utils.c ./src/ft_utilstwo.c ./src/ft_utilsthree.c \
					./src/ft_iswhitespace.c ./src/ft_ishexa.c ./src/ft_strcmp.c ./src/ft_atol.c

OBJ_DIR			=	obj/

.SILENT			:

OBJ				=	$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

$(OBJ_DIR)/%.o	:	%.c
					@mkdir -p $(addprefix $(OBJ_DIR), src)
					$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

all				:	$(NAME)

$(NAME)			:	$(OBJ)
					ar rsc $@ $^
					echo "Libft :: Compilation successfully."

clean			:
					rm -rf $(OBJ_DIR)
					echo "Libft :: Clean successfully."

fclean			:	clean
					rm -f $(NAME)
					echo "Libft :: Fclean successfully."

re				:	fclean all

.PHONY			:	all clean fclean re