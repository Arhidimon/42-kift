/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_where.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:32:52 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/23 15:34:15 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kift.h>

char	*choose_where(void)
{
	system("sh ../scripts/where_is_connected.script");
	return (ft_strdup("You are now connected at that place.\n"));
}
