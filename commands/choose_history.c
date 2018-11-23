/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:42:34 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/23 15:43:53 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kift.h>

char	*choose_history(void)
{
	system("sh ../scripts/check_history.script");
	return (ft_strdup("Close your eyes, please! This is not public info.\n"));
}
