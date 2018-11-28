#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

void send_string(int socket_fd, const char *str)
{
	size_t len;

	len = strlen(str);
	if (write(socket_fd, &len, sizeof(size_t)) < 0 || write(socket_fd, str, len) < 0)
	{
		printf("send str");
		exit(EXIT_FAILURE);
	}
}

char *read_string(int socket_fd)
{
	size_t len;
	char	*str;
	if (read(socket_fd, &len, sizeof(size_t)) < 0)
	{
		perror("read strlen error");
		exit(EXIT_FAILURE);
	}
	str = malloc(len + 1);
	if (read(socket_fd, str, len) < 0)
	{
		printf("read str error");
		exit(EXIT_FAILURE);
	}
	str[len] = 0;
	return (str);
}