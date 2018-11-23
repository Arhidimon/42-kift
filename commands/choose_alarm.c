/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_alarm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 14:59:15 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/23 15:31:27 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kift.h>

char	*choose_alarm(void)
{
	system("sh ../scripts/alarm.script");
	return (ft_strdup("I am not allowed to use crontab. Use this site.\n"));
}
