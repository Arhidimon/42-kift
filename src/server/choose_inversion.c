/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_inversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:23:45 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/26 18:35:31 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char	*choose_inversion(void)
{
	system("sh ./scripts/inv.script");
	system("sh ./scripts/own_music_play.script");
	return (strdup("I have no idea what I am doing."));
}
