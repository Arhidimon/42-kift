CLIENT        = client
SERVER        = server
CC          = gcc
CFLAGS      = -O2

SRCS_S_DIR    = ./src/server/
SRCS_C_DIR    = ./src/client/
OBJS_DIR_S   = ./objs
OBJS_DIR_C    = ./objc
HEADERS_DIR = ./include
LIBFT_DIR   = ./libft

SRCS_S      = server.c message_s.c choose_history.c choose_own_music.c log_file.c\
choose_alarm.c\
choose_brightness_down.c\
choose_brightness_up.c\
choose_events.c\
choose_intra.c\
choose_inversion.c\
choose_lights_off.c\
choose_lights_on.c\
choose_mail.c\
choose_play_music.c\
choose_screenshot.c\
choose_search_web.c\
choose_sound_off.c\
choose_sound_on.c\
choose_text.c\
choose_timer.c\
choose_traffic.c\
choose_weather.c\
choose_where.c\
choose_who.c\
choose_check_music.c\
choose_joke.c

SRCS_C        = client.c message_c.c get_user_speech.c

OBJS_S        = $(SRCS_S:.c=.o)
OBJS_C        = $(SRCS_C:.c=.o)

VPATH       = $(SRCS_S_DIR) $(SRCS_C_DIR) $(OBJS_DIR_C) $(OBJS_DIR_S)

INCLUDES_S    = -I include/

INCLUDES_C    = -I include/ \
              -I `pkg-config --cflags --libs pocketsphinx sphinxbase`


LIBFT       = $(LIBFT_DIR)/libft.a



TO_LINKING_S  = $(addprefix $(OBJS_DIR_S)/, $(OBJS_S)) $(INCLUDES_S)
TO_LINKING_C  = $(addprefix $(OBJS_DIR_C)/, $(OBJS_C)) $(INCLUDES_C)



all         : $(SERVER) $(CLIENT)

$(SERVER)		: $(OBJS_DIR_S) $(OBJS_S) $(HEADERS)
	@$(CC) $(CFLAGS) -o $(SERVER) $(TO_LINKING_S)
	@printf "\e[38;5;46m$(SERVER)    CREATED\e[0m\n"

$(CLIENT)		: $(OBJS_DIR_C) $(OBJS_C) $(HEADERS)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(TO_LINKING_C)
	@printf "\e[38;5;46m$(CLIENT)    CREATED\e[0m\n"


$(LIBFT)    :
	@make -C $(LIBFT_DIR)

$(OBJS_DIR_S) :
	@mkdir $(OBJS_DIR_S)
	@printf "\e[38;5;46m$(OBJS_DIR_S)   FOLDER CREATED\e[0m\n"

$(OBJS_DIR_C) :
	@mkdir $(OBJS_DIR_C)
	@printf "\e[38;5;46m$(OBJS_DIR_C)   FOLDER CREATED\e[0m\n"

$(OBJS_C)     : %.o : %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $(OBJS_DIR_C)/$@ $(INCLUDES_C) 2>/dev/null

$(OBJS_S)     : %.o : %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $(OBJS_DIR_S)/$@ $(INCLUDES_S) 2>/dev/null

clean       :
	@rm -rf $(OBJS_DIR_C)
	@rm -rf $(OBJS_DIR_S)
	@printf "\e[38;5;226m$(OBJS_DIR_C) $(OBJS_DIR_S)   FOLDERS DELETED\e[0m\n"

fclean      : clean
	@rm -f $(SERVER) $(CLIENT)
	@printf "\e[38;5;226m./$(SERVER) $(CLIENT)   DELETED\e[0m\n"

re          : fclean all

norm		:
	@norminette src/ includes/

leaks       :
	leaks $(CLIENT) $(SERVER)

test		:
	@make re
	@./$(SERVER)&
	@./$(CLIENT) 127.0.0.1
author		:
	@cat -e author

.PHONY: clean fclean re author
