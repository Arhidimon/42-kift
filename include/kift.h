#ifndef KIFT_MESSAGE_H
#define KIFT_MESSAGE_H

#define PORT 8080

#include <string.h>
#include <stdlib.h>

void send_string(int socket_fd, const char *str);
char *read_string(int socket_fd);
void	log_file(char *command, char *more_data);
/*
** Script prototypes
*/

char	*choose_who(void);
char	*choose_where(void);
char	*choose_weather(void);
char	*choose_traffic(void);
char	*choose_timer(void);
char	*choose_text(void);
char	*choose_sound_on(void);
char	*choose_sound_off(void);
char	*choose_search_web(void);
char	*choose_screenshot(void);
char	*choose_play_music(void);
char	*choose_own_music(void);
char	*choose_mail(void);
char	*choose_lights_on(void);
char	*choose_lights_off(void);
char	*choose_inversion(void);
char	*choose_intra(void);
char	*choose_history(void);
char	*choose_events(void);
char	*choose_brightness_up(void);
char	*choose_brightness_down(void);
char	*choose_alarm(void);
char	*choose_joke(void);
char	*choose_check_music(void);
char	*choose_playpause_music(void);

#endif //KIFT_MESSAGE_H
