/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_play_music.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:25:05 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/23 15:31:01 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kift.h>

char	*choose_play_music(void)
{
	system("sh ../scripts/play_music.script");
	return (ft_strdup("Enjoy the best song that I have in my database.\n"));
}