/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_timer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:56:07 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/23 17:56:20 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kift.h>

char	*choose_timer(void)
{
	system("sh ../scripts/timer.script");
	return (ft_strdup("I am not allowed to use crontab. Use this site.\n"));
}