/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_brightness_down.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:04:24 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/23 16:05:13 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kift.h>

char	*choose_brightness_down(void)
{
	system("sh ../scripts/brightness_down.script");
	return (ft_strdup("Less light for you.\n"));
}
