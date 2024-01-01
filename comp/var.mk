NAME = fractol

CFLAGS = -Wall -Wextra -Werror -Ofast -march=native -flto -fno-signed-zeros -funroll-loops
MLXFLAGS = -L$(MLXLIBDIR) -lmlx_Linux -lX11 -lm -lz -lXext

BUILDDIR = build
INCLUDEDIR = includes
LIBDIR = lib
LIBFTDIR = $(LIBDIR)/libft
MLXLIBDIR = $(LIBDIR)/mlxlib

OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

LIBFT = $(LIBFTDIR)/libft.a
MLXLIB = $(MLXLIBDIR)/libmlx_Linux.a
