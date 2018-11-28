/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_brightness_up.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:03:24 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/26 18:36:55 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char	*choose_brightness_up(void)
{
	system("sh ./scripts/brightness_up.script");
	return (strdup("More light for you <3."));
}
