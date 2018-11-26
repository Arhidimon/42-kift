CLIENT        = client
SERVER        = server
CC          = gcc
#CFLAGS      = -Wall -Wextra -Werror -O3 -g

SRCS_DIR    = ./src
OBJS_DIR    = ./obj
HEADERS_DIR = ./include
LIBFT_DIR   = ./libft

SRCS_S        = server.c message.c choose_history.c choose_own_music.c log_file.c\
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
choose_who.c

SRCS_C        = client.c message.c get_user_speech.c

SPHINX_FLAGS = -DMODELDIR=\"`pkg-config --variable=modeldir pocketsphinx`\" \
			   -DDICTDIR=\"$(shell pwd)/\"

OBJS_S        = $(SRCS_S:.c=.o)
OBJS_C        = $(SRCS_C:.c=.o)

VPATH       = $(SRCS_DIR) $(OBJS_DIR)

INCLUDES    = -I include/ \
              -I `pkg-config --cflags --libs pocketsphinx sphinxbase`


LIBFT       = $(LIBFT_DIR)/libft.a



TO_LINKING_S  = $(addprefix $(OBJS_DIR)/, $(OBJS_S)) $(INCLUDES)
TO_LINKING_C  = $(addprefix $(OBJS_DIR)/, $(OBJS_C)) $(INCLUDES)

all         : $(SERVER) $(CLIENT)

$(SERVER)		: $(OBJS_DIR) $(OBJS_S) $(HEADERS)
	$(CC) $(CFLAGS) -o $(SERVER) $(TO_LINKING_S)

$(CLIENT)		: $(OBJS_DIR) $(OBJS_C) $(HEADERS)
	$(CC) $(CFLAGS) -o $(CLIENT) $(TO_LINKING_C) $(SPHINX_FLAGS)


$(LIBFT)    :
	@make -C $(LIBFT_DIR)

$(OBJS_DIR) :
	@mkdir $(OBJS_DIR)
	@printf "\e[38;5;46m$(OBJS_DIR)    FOLDER CREATED\e[0m\n"

$(OBJS_C)     : %.o : %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $(OBJS_DIR)/$@ $(INCLUDES) $(SPHINX_FLAGS)

$(OBJS_S)     : %.o : %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $(OBJS_DIR)/$@ $(INCLUDES)

clean       :
	@rm -rf $(OBJS_DIR)
	@printf "\e[38;5;226m$(OBJS_DIR)    FOLDER DELETED\e[0m\n"

fclean      : clean
	@rm -f $(SERVER) $(CLIENT)
	@printf "\e[38;5;226m./$(SERVER) $(CLIENT)   DELETED\e[0m\n"

re          : fclean all

norm		:
	norminette src/ includes/

leaks       :
	leaks $(CLIENT) $(SERVER)

test		:
	make
	./$(NAME) 4

author		:
	cat -e author

.PHONY: clean fclean re author
