/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_lights_off.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:58:08 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/26 18:37:23 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char	*choose_lights_off(void)
{
	system("sh ./scripts/lights_off.script");
	return (strdup("All lights off. Good night."));
}
