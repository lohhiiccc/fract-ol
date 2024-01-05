NAME = fractol

CFLAGS = -Wall -Wextra -Werror -Ofast -march=native -flto -fno-signed-zeros -funroll-loops -D NB_THREADS=$(NB_THREADS)
MLXFLAGS = -L$(MLXLIBDIR) -lmlx_Linux -lX11 -lm -lz -lXext

BUILDDIR = build
INCLUDEDIR = includes
LIBDIR = lib
LIBFTDIR = $(LIBDIR)/libft
MLXLIBDIR = $(LIBDIR)/mlxlib

NB_THREADS = $(shell nproc)

OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

LIBFT = $(LIBFTDIR)/libft.a
MLXLIB = $(MLXLIBDIR)/libmlx_Linux.a
