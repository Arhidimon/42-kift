/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_weather.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:53:48 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/23 15:55:03 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kift.h>

char	*choose_weather(void)
{
	system("sh ../scripts/weather.script");
	return (ft_strdup("Current weather forecast in your country.\n"));
}
