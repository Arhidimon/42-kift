#ifndef KIFT_MESSAGE_H
#define KIFT_MESSAGE_H

#define PORT 8080

void send_string(int socket_fd, const char *str);
char *read_string(int socket_fd);

#endif //KIFT_MESSAGE_H
