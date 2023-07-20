#################### INCLUDE ####################

INCCLPATH = client_docs/includes/
INCSEPATH = server_docs/includes/
INCCL = -I $(INCCLPATH)
INCSE = -I $(INCSEPATH)
PRINTF = printf/ft_printf.a

INCSE += ./server_docs/includes/server.h
INCCL += ./client_docs/includes/client.h

#################### SOURCES #####################

SRCSCL += ./client_docs/sources/client.c
SRCSCL += ./client_docs/sources/utils.c
SRCSSE += ./server_docs/sources/server.c
SRCSSE += ./server_docs/sources/utils.c

################# FOLDER PATHS ##################

SRCCLPATH = client_docs/sources/
SRCSEPATH = server_docs/sources/
PRINTFPATH = ft_printf/

#################### MACROS #####################

OBJCL = $(SRCSCL:.c=.o)
OBJSE = $(SRCSSE:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -g3

LPRINTF = -L $(PRINTFPATH) -l :printf.a

NAMECL = client
NAMESE = server

#################### RULES ####################

all: $(NAMECL) $(NAMESE)

$(NAMECL): $(OBJCL) 
	make -sC ft_printf
	$(CC) $(CFLAGS) $(OBJCL) -o $(NAMECL) $(LPRINTF)

$(NAMESE): $(OBJSE)
	make -sC ft_printf
	$(CC) $(CFLAGS) $(OBJSE) -o $(NAMESE) $(LPRINTF)

bonus: $(NAMECL) $(NAMESE)

$(OBJCLPATH)%.o: $(SRCCLPATH)%.c | $(OBJCLPATH)
	$(CC) $(CFLAGS) $(INCCL) -c $< -o $@

$(OBJSEPATH)%.o: $(SRCSEPATH)%.c | $(OBJSEPATH)
	$(CC) $(CFLAGS) $(INCSE) -c $< -o $@

clean:
	rm $(SRCCLPATH)client.o $(SRCCLPATH)utils.o 
	rm $(SRCSEPATH)server.o $(SRCSEPATH)utils.o 
	make clean -C ft_printf

fclean: clean
	rm -f $(NAMECL)
	rm -f $(NAMESE)
	make fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re