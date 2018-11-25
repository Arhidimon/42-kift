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

void action(char *str, char **ans)
{
 // do smthng
 strcpy(*ans, "Answer"); //FIXME ft_strcpy
}

int main(int argc, char const *argv[])
{
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char *str;
	char *ans = "Answer";
	size_t len;

	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	// Forcefully attaching socket to the port 8080
//	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
//				   &opt, sizeof(opt)))
//	{
//		perror("setsockopt");
//		exit(EXIT_FAILURE);
//	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( PORT );

	// Forcefully attaching socket to the port 8080
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
		log_term(str);
		//action(buffer, &ans);
		//log_term(ans);
		free(str);
		send_string(new_socket, ans);
		//send(new_socket, ans, strlen(ans), 0);
	}
	return 0;
}