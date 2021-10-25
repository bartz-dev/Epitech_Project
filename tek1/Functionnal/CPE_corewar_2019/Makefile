##
## EPITECH PROJECT, 2019
## CPE_corewar_2019
## File description:
## Makefile
##

MK		=	make --no-print-directory

all:
		@echo -e "\033[01m\033[31mBuilding asm...\033[00m"
		@$(MK) -C asm/
		@echo -e "\033[01m\033[31mBuilding corewar...\033[00m"
		@$(MK) -C corewar/

clean:
		@echo -e "\033[01m\033[31mRemoving asm objects...\033[00m"
		@$(MK) clean -C asm/
		@echo -e "\033[01m\033[31mRemoving corewar objects...\033[00m"
		@$(MK) clean -C corewar/

fclean:		clean
		@echo -e "\033[01m\033[31mRemoving binary: asm\033[00m"
		@$(MK) fclean -C asm/
		@echo -e "\033[01m\033[31mRemoving binary: corewar\033[00m"
		@$(MK) fclean -C corewar/

re:		fclean all

.PHONY:	all corewar asm re clean fclean