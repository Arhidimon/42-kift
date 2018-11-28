/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sound_off.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:52:11 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/26 18:40:12 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char	*choose_sound_off(void)
{
	system("sh ./scripts/sound_off.script");
	return (strdup("Sound off. Shhhh."));
}
