CC = cc
#CFLAGS = -Wall -Wextra -Werror -Ofast -march=native -flto -fno-signed-zeros -funroll-loops
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=thread -march=native -flto -fno-signed-zeros -funroll-loops
NAME = fractol

BUILDDIR = build
LIBFTDIR = libft
MLXLIBDIR = mlxlib
INCLUDEDIR = includes
include src.mk

OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

LIBFT = $(LIBFTDIR)/libft.a
MLXLIB = $(MLXLIBDIR)/libmlx_Linux.a

MLXFLAGS = -L$(MLXLIBDIR) -lmlx_Linux -lX11 -lm -lz -lXext

all: $(NAME)

$(NAME): $(LIBFT) $(MLXLIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -pthread -o $(NAME) -L$(LIBFTDIR) -lft $(MLXFLAGS)

$(LIBFT):
	make -C $(LIBFTDIR)

$(MLXLIB):
	make -C $(MLXLIBDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	make -C $(LIBFTDIR) fclean
	make -C $(MLXLIBDIR) clean
	rm -rf $(BUILDDIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re