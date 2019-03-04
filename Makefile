
CHECKER :=			checker
PS :=			push_swap

SRC_PATH :=		src/
CHECKER_PATH :=	$(SRC_PATH)checker/
PS_PATH :=		$(SRC_PATH)push_swap/


all:
	@ make -C $(CHECKER_PATH)
	@ make -C $(PS_PATH)
	@ ln -fs $(CHECKER_PATH)$(CHECKER) $(CHECKER)
	@ ln -fs $(PS_PATH)$(PS) $(PS)
	@ chmod 744 $(CHECKER) $(PS)

mre:
	@ make mre -C $(CHECKER_PATH)
	@ make mre -C $(PS_PATH)
	@ ln -fs $(CHECKER_PATH)$(CHECKER) $(CHECKER)
	@ ln -fs $(PS_PATH)$(PS) $(PS)
	@ chmod 744 $(CHECKER) $(PS)
clean:
	make clean -C $(CHECKER_PATH)
	make clean -C $(PS_PATH)
fclean:
	make fclean -C $(CHECKER_PATH)
	make fclean -C $(PS_PATH)
	rm -f $(CHECKER) $(PS)
re: fclean all

.PHONY: all clean fclean re mre
