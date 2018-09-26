# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlecart <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/26 19:15:45 by rlecart           #+#    #+#              #
#    Updated: 2018/09/26 19:41:20 by rlecart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
PROJECT		=	FT_MALLOC
NAME		=	libft_ft_malloc_$(HOSTTYPE).so
LINK		=	libft_ft_malloc.so
OBJSDIR		=	objs/
SRCSDIR		=	srcs/
SRCS		=	ft_free.c \
				ft_malloc.c \
				ft_realloc.c \
				show_alloc_mem.c
LIBFTP		=	libs/libft/
LIBFT		=	$(LIBFTP)libft.a
OBJS		=	$(addprefix $(OBJSDIR),$(SRCS:.c=.o))
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I includes/ -I libs/libft/includes/ $(OPTI) $(DEBUG)
OPTI		=	
DEBUG		=	

WHITE		=	\033[7;49;39m
BLUE		=	\033[7;49;34m
RED			=	\x1B[31m
YELLOW		=	\x1B[33m
GREEN		=	\033[0;49;32m
GREEN_BG	=	\033[1;49;32m
GRAY		=	\033[7;49;90m
NO_COLOR	=	\033[m

all: lib $(NAME)

$(NAME): $(LIBFT) $(OBJSDIR) $(OBJS)
	@printf "\r$(GREEN)[$(PROJECT)] Objs compilation done.                                                        \n"
	@printf "$(YELLOW)[$(PROJECT)] Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -shared -o $(NAME)
	@ln -s $(NAME) $(LINK)
	@printf "\r$(GREEN)[$(PROJECT)] Compilation done.                          \n$(NO_COLOR)"

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	@printf "$(YELLOW)\r[$(PROJECT)] Compiling $< to $@ -g                                                          \r"
	@$(CC) $(CFLAGS) -o $@ -c $<

lib:
	@make -s -C $(LIBFTP) 2> /dev/null > /dev/null

$(OBJSDIR):
	@mkdir $(OBJSDIR)

clean:
	@make -s -C $(LIBFTP) clean
	@printf "$(YELLOW)[$(PROJECT)] Removing objs..."
	@rm -rf $(OBJS)
	@rm -rf $(OBJSDIR)
	@printf "\r$(GREEN)[$(PROJECT)] Objs removed.                                                   \n$(NO_COLOR)"

fclean:
	@make -s -C $(LIBFTP) fclean
	@printf "$(YELLOW)[$(PROJECT)] Removing objs..."
	@rm -rf $(OBJS)
	@rm -rf $(OBJSDIR)
	@printf "\r$(GREEN)[$(PROJECT)] Objs removed.                                                   \n$(NO_COLOR)"
	@printf "$(YELLOW)[$(PROJECT)] Removing $(NAME)..."
	@rm -rf $(LINK)
	@rm -rf $(NAME)
	@printf "\r$(GREEN)[$(PROJECT)] $(NAME) removed.                                               \n$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re
