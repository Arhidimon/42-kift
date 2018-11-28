/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_mail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omaiko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:44:09 by omaiko            #+#    #+#             */
/*   Updated: 2018/11/26 18:44:12 by omaiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kift.h"

char	*choose_mail(void)
{
	system("sh ./scripts/mail.script");
	return (strdup("In theory this should work properly. But..."));
}
