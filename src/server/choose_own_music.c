/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_own_music.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:50:06 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/26 18:45:24 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char	*choose_own_music(void)
{
	system("sh ./scripts/own_music_play.script");
	return (strdup("I am trying to singing on my own."));
}
