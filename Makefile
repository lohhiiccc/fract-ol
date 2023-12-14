CC = cc
CFLAGS = -Wall -Wextra -Werror -Ofast -march=native -flto -fno-signed-zeros -funroll-loops

SRCDIR = srcs
BUILDDIR = build
LIBFTDIR = libft
MLXLIBDIR = mlxlib
INCLUDEDIR = includes

SRCS = $(SRCDIR)/main.c \
	   $(SRCDIR)/c_tools.c \
	   $(SRCDIR)/mouse.c \
	   $(SRCDIR)/arrow.c \
	   $(SRCDIR)/fractal.c \
	   $(SRCDIR)/draw.c \
	   $(SRCDIR)/keyboard.c \
	   $(SRCDIR)/pixel_color.c \
	   $(SRCDIR)/bilinear_interpolation.c

OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

LIBFT = $(LIBFTDIR)/libft.a
MLXLIB = $(MLXLIBDIR)/libmlx_Linux.a

MLXFLAGS = -L$(MLXLIBDIR) -lmlx_Linux -lX11 -lm -lz -lXext

NAME = fractol


all: $(NAME)

$(NAME): $(LIBFT) $(MLXLIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFTDIR) -lft $(MLXFLAGS)


$(LIBFT):
	make -C $(LIBFTDIR)

$(MLXLIB):
	make -C $(MLXLIBDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	make -C $(LIBFTDIR) clean
	make -C $(MLXLIBDIR) clean
	rm -rf $(BUILDDIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all


.PHONY: all clean fclean re
