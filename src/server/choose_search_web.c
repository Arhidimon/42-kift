/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_search_web.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:41:41 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/26 18:39:13 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char	*choose_search_web(void)
{
	system("sh ./scripts/search_the_web.script");
	return (strdup("You can surf the Internet smth like this."));
}
