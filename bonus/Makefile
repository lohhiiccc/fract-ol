include comp/src.mk
include comp/var.mk

all: $(NAME)

$(NAME):  $(LIBFT) $(MLXLIB) $(OBJS)
	$(CC) $(CFLAGS) -pthread $(OBJS) -o $(NAME) -L$(LIBFTDIR) -lft $(MLXFLAGS)

$(LIBFT): FORCE
	make -C $(LIBFTDIR)

$(MLXLIB): FORCE
	make -C $(MLXLIBDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -I$(LIBFTDIR) -I$(MLXLIBDIR) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	make -C $(LIBFTDIR) fclean
	make -C $(MLXLIBDIR) clean
	rm -rf $(BUILDDIR)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

FORCE:

.PHONY: all clean fclean re