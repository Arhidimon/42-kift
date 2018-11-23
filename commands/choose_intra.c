/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_intra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:30:00 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/23 15:30:39 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kift.h>

char	*choose_intra(void)
{
	system("sh ../scripts/intra.script");
	return (ft_strdup("Welcome to the intra. Please, follow me.\n"));
}
