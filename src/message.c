#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void send_string(int socket_fd, const char *str)
{
	size_t len;

	len = strlen(str);//FIXME ft_strlen
	write(socket_fd, &len, sizeof(size_t));
	write(socket_fd, str, len);
}

char *read_string(int socket_fd)
{
	size_t len;
	char	*str;

	read(socket_fd, &len, sizeof(size_t));
	str = malloc(len + 1);
	read(socket_fd, str, len);
	str[len + 1] = 0;
	return (str);
}