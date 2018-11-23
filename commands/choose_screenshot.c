/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_screenshot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:28:25 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/23 15:29:18 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kift.h>

char	*choose_screenshot(void)
{
	system("sh ../scripts/screenshot.script");
	return (ft_strdup("Oh, you are too lazy. O'K, I will do this.\n"));
}
