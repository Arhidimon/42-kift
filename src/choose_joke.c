#include "kift.h"
#include <stdio.h>
#include <stdlib.h>

char	*choose_joke(void)
{
    FILE *file;
    char buffer[500];

    system("curl -H \"Accept: text/plain\" https://icanhazdadjoke.com/ > joke.txt");
    file = fopen("joke.txt", "r");
    fgets(buffer, 499, file);
    fclose(file);

    return (strdup(buffer));
}