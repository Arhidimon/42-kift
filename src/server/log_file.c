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

	if (command && *command && more_data && *more_data)
	{
		if (!(f = fopen("./kift.log", "a+")))
			return ;
		if (strcmp("Sorry, try again!", command))
			fprintf(f, "[%s] [%s] [success] [%s]\n", get_datetime(), more_data, command);
		else
			fprintf(f, "[%s] [Wrong command] [failed] [%s]\n", get_datetime(), more_data);
		fclose(f);
	}
}