#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

char	*get_datetime()
{
	char	*dt_str;
	time_t	t;
	struct tm tm;

	t = time(NULL);
	tm = *localtime(&t);
	dt_str = (char *)malloc(sizeof(char) * 20);
	bzero(dt_str, 20);
	sprintf(dt_str, "%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900,
			tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	return (dt_str);
}

void	log_file(char *command, char *more_data)
{
	FILE *f;

	if (!(f = fopen("kift.log", "a+")))
		return ;
	if (strcmp("Sorry, try again!", more_data))
		fprintf(f, "[%s] [%s] [success] [%s]\n", get_datetime(), command, more_data);
	else
		fprintf(f, "[%s] [%s] [failed] [%s]\n", get_datetime(), command, more_data);

}