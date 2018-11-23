/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sound_on.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:51:01 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/23 17:51:54 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kift.h>

char	*choose_sound_on(void)
{
	system("sh ../scripts/sound_on.script");
	return (ft_strdup("Sound on. Enjoy listening to smth.\n"));
}
