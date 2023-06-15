#################### INCLUDE ####################

-include make/inc_client.mk
-include make/inc_server.mk
-include make/srcs_client.mk
-include make/srcs_server.mk

INCCLPATH = client_docs/includes/
INCSEPATH = server_docs/includes/
INCCL = -I $(INCCLPATH)
INCSE = -I $(INCSEPATH)
PRINTF = printf/ft_printf.a


################# FOLDER PATHS ##################

OBJCLPATH = .objs_client/
OBJSEPATH = .objs_server/
SRCCLPATH = client_docs/sources/
SRCSEPATH = server_docs/sources/
PRINTFPATH = ft_printf/

#################### MACROS #####################

OBJCL = $(patsubst $(SRCCLPATH)%.c, $(OBJCLPATH)%.o, $(SRCSCL))
OBJSE = $(patsubst $(SRCSEPATH)%.c, $(OBJSEPATH)%.o, $(SRCSSE))

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g -g3

LPRINTF = -L $(PRINTFPATH) -l :printf.a

NAMECL = client
NAMESE = server

#################### RULES ####################

all: $(NAMECL) $(NAMESE)

$(NAMECL): $(OBJCL) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJCL) -o $(NAMECL) $(LPRINTF)

$(NAMESE): $(OBJSE) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJSE) -o $(NAMESE) $(LPRINTF)

$(OBJCLPATH)%.o: $(SRCCLPATH)%.c | $(OBJCLPATH)
	$(CC) $(CFLAGS) $(INCCL) -c $< -o $@

$(OBJSEPATH)%.o: $(SRCSEPATH)%.c | $(OBJSEPATH)
	$(CC) $(CFLAGS) $(INCSE) -c $< -o $@

$(OBJCLPATH):
	mkdir -p $(OBJCLPATH)

$(OBJSEPATH):
	mkdir -p $(OBJSEPATH)

$(PRINTF):
	make -sC ft_printf

clean:
	rm -rf $(OBJCLPATH)
	rm -rf $(OBJSEPATH)
	make clean -C ft_printf

fclean: clean
	rm -f $(NAMECL)
	rm -f $(NAMESE)
	make fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re