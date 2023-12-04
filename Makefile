# Compiler options
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = srcs
BUILDDIR = build
LIBFTDIR = libft
MLXLIBDIR = mlxlib
INCLUDEDIR = include

# Source files
SRCS = $(SRCDIR)/main.c
OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

# Libraries
LIBFT = $(LIBFTDIR)/libft.a
MLXLIB = $(MLXLIBDIR)/libmlx_Linux.a

# Compilation flags for mlxlib
MLXFLAGS = -L$(MLXLIBDIR) -lmlx_Linux -lX11 -lm -lz -lXext
MLXINCLUDE = -I$(MLXLIBDIR)

# Compilation flags for libft
LIBFTINCLUDE = -I$(LIBFTDIR)

# Target executable
NAME = fractol

# Default rule
all: $(NAME)

# Rule to build the executable
$(NAME): $(LIBFT) $(MLXLIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFTDIR) -lft $(MLXFLAGS)

# Rule to build the libft library
$(LIBFT):
	make -C $(LIBFTDIR)

# Rule to build the mlxlib library
$(MLXLIB):
	make -C $(MLXLIBDIR)

# Rule to build object files
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(MLXINCLUDE) $(LIBFTINCLUDE) -I$(INCLUDEDIR) -MMD -c $< -o $@

# Clean rule
clean:
	make -C $(LIBFTDIR) clean
	make -C $(MLXLIBDIR) clean
	rm -rf $(BUILDDIR)

# Fclean rule
fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)

# Rebuild rule
re: fclean all

# Include dependencies
-include $(DEPS)

# Debug rule for Valgrind
debug: $(LIBFT) $(MLXLIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFTDIR) -lft $(MLXFLAGS) -g3

# Debug rule for Valgrind with sanitize
debug-adr: $(LIBFT) $(MLXLIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFTDIR) -lft $(MLXFLAGS) -g3 -fsanitize=address,undefined

# Phony targets
.PHONY: all clean fclean re debug debug-adr
