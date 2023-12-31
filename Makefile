include src.mk
include var.mk

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
	make -C $(LIBFTDIR) fclean
	make -C $(MLXLIBDIR) clean
	rm -rf $(BUILDDIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re