/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_check_music.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:25:05 by dbezruch          #+#    #+#             */
/*   Updated: 2018/11/26 18:45:09 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"
#include <stdio.h>
#include <stdlib.h>

char	*choose_check_music(void)
{
	FILE *file;
	char buffer[500];

	system("./scripts/spotify.script > cur.tmp");
	file = fopen("cur.tmp", "r");
	fgets(buffer, 499, file);
	fclose(file);
	system("rm -f cur.tmp");
	if (strlen(buffer) > 0 && buffer[strlen(buffer) - 1] == '\n')
		buffer[strlen(buffer) - 1] = 0;
	return (strdup(buffer));
}
