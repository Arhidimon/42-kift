/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_traffic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:53:12 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/23 15:53:36 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kift.h>

char	*choose_traffic(void)
{
	system("sh ../scripts/traffic.script");
	return (ft_strdup("Traffic jams in your city.\n"));
}
