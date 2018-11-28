/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_play_music.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:25:05 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/26 18:45:09 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char	*choose_play_music(void)
{
	system("sh ./scripts/play_music.script");
	return (strdup("Enjoy the best song that I have in my database."));
}

char	*choose_playpause_music(void)
{
	system("./scripts/playpause.script");
	return (strdup("Yes, milord."));
}