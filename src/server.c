/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:09:57 by dbezruch          #+#    #+#             */
/*   Updated: 2018/10/26 17:09:08 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/kift.h"
#include "../include/server.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

void log_term(char *str)
{
	printf("[log]%s\n", str); // TODO better log
}

char *action(char *str)
{
	if (!strcmp(str, "history"))
		return choose_history();
	else if (!strcmp(str, "music"))
		return choose_own_music();
	else if (!strcmp(str, "alarm"))
		return choose_alarm();
	else if (!strcmp(str, "events"))
		return choose_events();
	else if (!strcmp(str, "intra"))
		return choose_intra();
	else if (!strcmp(str, "brightness up"))
		return choose_brightness_up();
	else if (!strcmp(str, "brightness down"))
		return choose_brightness_down();
	else if (!strcmp(str, "lights on"))
		return choose_lights_on();
	else if (!strcmp(str, "lights off"))
		return choose_lights_off();
	else if (!strcmp(str, "inversion"))
		return choose_inversion();
	else if (!strcmp(str, "mail"))
		return choose_mail();
	else if (!strcmp(str, "screenshot"))
		return choose_screenshot();
	else if (!strcmp(str, "sound on"))
		return choose_sound_on();
	else if (!strcmp(str, "sound off"))
		return choose_sound_off();
	else if (!strcmp(str, "text"))
		return choose_text();
	else if (!strcmp(str, "timer"))
		return choose_timer();
	else if (!strcmp(str, "traffic"))
		return choose_traffic();
	else if (!strcmp(str, "weather"))
		return choose_weather();
	else if (!strcmp(str, "where"))
		return choose_where();
	else if (!strcmp(str, "who"))
		return choose_who();
	else
		return (strdup("Sorry, try again!"));
}

int main(int argc, char const *argv[])
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char *str;
	char *ans;
	size_t len;

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
	if ((new_socket = accept(server_fd, (struct sockaddr *) &address,
							 (socklen_t * ) & addrlen)) < 0) {
		perror("accept");
		exit(EXIT_FAILURE);
	}
	while (1)
	{

		str = read_string(new_socket);
		//log_term(str);
		printf("[Server get] %s\n", str);
		ans = action(str);
		//free(str);
		send_string(new_socket, ans);
		printf("[Server send] %s\n", ans);
		log_file("str", ans);
		//if (ans)
		//	free(ans);
	}
	return 0;
}