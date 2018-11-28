/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:57:59 by dbezruch          #+#    #+#             */
/*   Updated: 2018/10/26 17:16:45 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/kift.h"
#include "../../include/client.h"
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

void say(char *str)
{
	char buf[256];
	snprintf(buf, sizeof buf, "say \"-vMoira\" \"%s\"", str);
	system(buf);
}

int main(int argc, char const *argv[])
{
	struct sockaddr_in address;
	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	size_t len;
	char *ans;

	//voice rec
	char	*speech;
	if(argc != 2)
		exit(0);
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}
	memset(&serv_addr, '0', sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}
	while (1)
	{
		speech = NULL;
		speech = get_user_speech();
		if (!speech || strlen(speech) == 0)
		{
			printf("%s\n","Your speech is not recognized.");
			continue ;
		}
		else
		{
			len = strlen(speech);
			send_string(sock,speech);
			ans = read_string(sock);
			printf("Answer:%s\n", ans);
			say(ans);
			free(ans);
		}

	}
	return 0;
}