/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_lights_on.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:58:46 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/26 18:37:36 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char	*choose_lights_on(void)
{
	system("sh ./scripts/lights_on.script");
	return (strdup("All lights on. Wake up."));
}
