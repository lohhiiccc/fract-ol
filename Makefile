NAME = fractol

all:
	$(MAKE) -C mandatory
	cp mandatory/$(NAME) ./

bonus:
	make -C bonus all
	rm -f $(NAME)
	cp bonus/$(NAME) ./

clean:
	$(MAKE) -C mandatory clean
	$(MAKE) -C bonus clean

fclean: clean
	rm -fr $(NAME)
	rm -rf mandatory/$(NAME)
	rm -rf bonus/$(NAME)

re: fclean
	$(MAKE) all

save:
	touch fractal.save

rebonus: fclean
	$(MAKE) bonus

.PHONY: all clean fclean bonus rebonus save