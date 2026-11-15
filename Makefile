NAME = get_next_line.a

BONUS_NAME = get_next_line_bonus.a

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = get_next_line.c \
		get_next_line_utils.c 

BONUS_SRCS = get_next_line_bonus.c \
		get_next_line_utils_bonus.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME) $(BONUS_NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(BONUS_NAME): $(BONUS_OBJS)
	ar rcs $(BONUS_NAME) $(BONUS_OBJS)

%.o: %.c get_next_line.h 
	$(CC) $(FLAGS) -c $< -o $@

%.o: %.c get_next_line_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

bonus: $(BONUS_NAME)

norm:
	norminette $(SRCS) $(BONUS_SRCS) *.h

.PHONY: all clean fclean re norm bonus
