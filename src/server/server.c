/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:09:57 by dbezruch          #+#    #+#             */
/*   Updated: 2018/11/27 19:28:30 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/kift.h"
#include "../../include/server.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>

void log_term(char *str)
{
	printf("[log]%s\n", str);
}

char *action(char *str)
{
	if (!strcmp(str, "CHECK HISTORY"))
		return choose_history();
	else if (!strcmp(str, "SEARCH MUSIC"))
		return choose_play_music();
	else if (!strcmp(str, "PLAY MUSIC"))
		return choose_play_music();
	else if (!strcmp(str, "TURN MUSIC") || !strcmp(str, "MUSIC"))
		return choose_playpause_music();
	else if (!strcmp(str, "CHECK MUSIC"))
		return choose_check_music();
	else if (!strcmp(str, "SET ALARM"))
		return choose_alarm();
	else if (!strcmp(str, "CHECK EVENTS"))
		return choose_events();
	else if (!strcmp(str, "OPEN BROWSER"))
		return choose_intra();
	else if (!strcmp(str, "BRIGHTNESS INCREASE"))
		return choose_brightness_up();
	else if (!strcmp(str, "BRIGHTNESS DECREASE"))
		return choose_brightness_down();
	else if (!strcmp(str, "LIGHTS ON"))
		return choose_lights_on();
	else if (!strcmp(str, "LIGHTS OFF"))
		return choose_lights_off();
	else if (!strcmp(str, "SHOW JOKE"))
		return choose_inversion();
	else if (!strcmp(str, "SEND EMAIL"))
		return choose_mail();
	else if (!strcmp(str, "SCREENSHOT"))
		return choose_screenshot();
	else if (!strcmp(str, "VOLUME ON"))
		return choose_sound_on();
	else if (!strcmp(str, "VOLUME OFF"))
		return choose_sound_off();
	else if (!strcmp(str, "OPEN"))
		return choose_text();
	else if (!strcmp(str, "SET TIMER"))
		return choose_timer();
	else if (!strcmp(str, "CHECK TRAFFIC"))
		return choose_traffic();
	else if (!strcmp(str, "CHECK WEATHER"))
		return choose_weather();
	else if (!strcmp(str, "WHERE IS CONNECTED"))
		return choose_where();
	else if (!strcmp(str, "WHO IS CONNECTED"))
		return choose_who();
	else if (!strcmp(str, "JOKE"))
		return choose_joke();
	else
		return (strdup("Sorry, try again!"));
}

int main(void)
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char *str;
	char *ans;

	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( PORT );
	if (bind(server_fd, (struct sockaddr *)&address,
			 sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	system("echo \"Server started at:\";ifconfig | sed -En 's/127.0.0.1//;s/.*inet (addr:)?(([0-9]*\\.){3}[0-9]*).*/\\2/p'");
	if ((new_socket = accept(server_fd, (struct sockaddr *) &address,
							 (socklen_t * ) & addrlen)) < 0) {
		perror("accept");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		str = read_string(new_socket);
		ans = action(str);
		send_string(new_socket, ans);
		log_file(ans, str);
		free(str);
		if (ans)
			free(ans);
	}
	return 0;
}
