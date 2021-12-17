##
## EPITECH PROJECT, 2021
## nm/objdump
## File description:
## Makefile
##

CXX = gcc

CFLAGS = #options de compilation

LDFLAGS = #options de link

SRCNM = 	nm/main.c			\
			nm/check_input.c	\
			nm/check_magic.c	\
			nm/run_nm.c			\
			nm/get_struct.c

SRCOBJ = 	objdump/main.c				\
			objdump/check_input.c		\
			objdump/run_objdump.c		\
			objdump/get_struct.c		\
			objdump/check_magic.c		\
			objdump/objdump_f.c			\
			objdump/get_flags.c			\
			objdump/print_flags.c		\
			objdump/get_architecture.c	\
			objdump/objdump_s.c			\
			objdump/print_section.c		\
			objdump/print_sections.c	\
			objdump/is_printable.c		\
			objdump/print_hexadecimal.c	\
			objdump/print_space.c

OBJNM = $(SRCNM:.c=.o)

OBJOBJ = $(SRCOBJ:.c=.o)

OUTPUTNM = my_nm #nom de l'exectutable

OUTPUTOBJ = my_objdump

all: nm objdump

nm:	$(OBJNM)
	@$(CXX) $(LDFLAGS) -o $(OUTPUTNM) $^
	@echo "Compilation ended"

objdump:	$(OBJOBJ)
	@$(CXX) $(LDFLAGS) -o $(OUTPUTOBJ) $^
	@echo "Compilation ended"

$(OBJNM): %.o: %.c
	@$(CXX) $(CFLAGS) -c $< -o $@
	@echo "$@ Creation"

$(OBJOBJ): %.o: %.c
	@$(CXX) $(CFLAGS) -c $< -o $@
	@echo "$@ Creation"

clean:
	@rm -rf nm/*.o objdump/*.o
	@echo "Clean"

fclean: clean
	@rm -rf $(OUTPUTNM) $(OUTPUTOBJ)
	@echo "Fclean"

re: fclean all