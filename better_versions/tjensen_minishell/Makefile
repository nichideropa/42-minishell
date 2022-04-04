# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjensen <tjensen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 22:03:08 by tjensen           #+#    #+#              #
#    Updated: 2022/01/17 15:47:15 by tjensen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#	PROJECT SPECIFIC														   #
# **************************************************************************** #

NAME		:= minishell

SRCS_BUILTIN:= builtin_echo.c builtin_cd.c builtin_exit.c builtin_pwd.c \
			   builtin_env.c builtin_export.c builtin_unset.c builtin.c
SRCS_CMD	:= cmd.c scmd.c
SRCS_ENV	:= env.c env_modify.c
SRCS_EXEC	:= exec.c exec_pipeline.c exec_pipeline_pipes.c exec_scmd.c \
			   exec_scmd_path.c exec_wait.c exec_group.c exec_exit_status.c
SRCS_EXPAND	:= expand.c expand_wildcard.c expand_wildcard_utils.c \
			   expand_var.c expand_var_split.c
SRCS_LEXER	:= lexer.c lexer_syntax.c lexer_token_other.c lexer_token_text.c
SRCS_PARSER	:= parser.c parser_scmd.c parser_pipeline.c parser_group.c \
			   parser_heredoc.c
SRCS_PRINTER:= printer_token.c printer_scmd.c printer_cmd.c
SRCS_REDIR	:= redir.c redir_undo.c
SRCS_SIGNALS:= signals.c
SRCS_TOKEN	:= token.c token_list.c
SRCS_UTILS	:= utils_error.c utils_gnl.c utils_lst.c utils_split.c utils_str.c

SRCS		:= minishell.c
SRCS		+= $(addprefix builtin/, $(SRCS_BUILTIN)) \
			   $(addprefix cmd/, $(SRCS_CMD)) \
			   $(addprefix env/, $(SRCS_ENV)) \
			   $(addprefix exec/, $(SRCS_EXEC)) \
			   $(addprefix expand/, $(SRCS_EXPAND)) \
			   $(addprefix lexer/, $(SRCS_LEXER)) \
			   $(addprefix parser/, $(SRCS_PARSER)) \
			   $(addprefix printer/, $(SRCS_PRINTER)) \
			   $(addprefix redir/, $(SRCS_REDIR)) \
			   $(addprefix signals/, $(SRCS_SIGNALS)) \
			   $(addprefix token/, $(SRCS_TOKEN)) \
			   $(addprefix utils/, $(SRCS_UTILS))

LDLIBS		:= -lft -lreadline

# **************************************************************************** #
#	GENERAL VARIABLES														   #
# **************************************************************************** #

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

SDIR		:= src
ODIR		:= obj
OBJS		:= $(addprefix $(ODIR)/, $(SRCS:.c=.o))

LIBDIRS		:= $(wildcard lib/*)
LDLIBS		:= $(addprefix -L./, $(LIBDIRS)) $(LDLIBS)
INCLUDES	:= -I./inc/ $(addprefix -I./, $(LIBDIRS)) \
			   $(addprefix -I./, $(addsuffix /inc, $(LIBDIRS)))

# COLORS
LB   		= \033[0;36m
B			= \033[0;34m
Y  			= \033[0;33m
G		    = \033[0;32m
R 			= \033[0;31m
X		    = \033[m

# **************************************************************************** #
#	SYSTEM SPECIFIC SETTINGS							   					   #
# **************************************************************************** #

ifeq ($(shell uname -s), Linux)
	CFLAGS += -D LINUX -Wno-unused-result
endif

# **************************************************************************** #
#	FUNCTIONS									   							   #
# **************************************************************************** #

define MAKE_LIBS
	for DIR in $(LIBDIRS); do \
		$(MAKE) -C $$DIR $(1) --silent; \
	done
endef

# **************************************************************************** #
#	RULES																	   #
# **************************************************************************** #

.PHONY: all header clean fclean re bonus debug release libs test

all: $(NAME)

$(NAME): libs header $(OBJDIRS) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDLIBS)
	@printf "$(G)======= $(NAME)$(X)\n"

$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "%-57b %b" "$(B)compile $(LB)$@" "$(G)[✓]$(X)\n"

header:
	@printf "###############################################\n"
	@printf "$(Y)####### $(shell echo "$(NAME)" | tr '[:lower:]' '[:upper:]')$(X)\n"

clean: libs header
	@$(RM) -r $(ODIR)
	@$(RM) -r *.dSYM $(SDIR)/*.dSYM $(SDIR)/$(NAME)
	@printf "%-50b %b" "$(R)clean" "$(G)[✓]$(X)\n"

fclean: libs header clean
	@$(RM) $(NAME)
	@printf "%-50b %b" "$(R)fclean" "$(G)[✓]$(X)\n"

re: fclean all

bonus: all

debug: CFLAGS += -O0 -DDEBUG -g
debug: all

release: fclean
release: CFLAGS	+= -O2 -DNDEBUG
release: all clean

libs:
ifeq ($(MAKECMDGOALS), $(filter $(MAKECMDGOALS), clean fclean re debug release))
	@$(call MAKE_LIBS,$(MAKECMDGOALS))
else
	@$(call MAKE_LIBS,all)
endif

test:
	@cd tests && bash tester.sh a
