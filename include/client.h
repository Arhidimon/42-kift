/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:58:39 by dbezruch          #+#    #+#             */
/*   Updated: 2018/10/26 14:58:39 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KIFT_CLIENT_H
#define KIFT_CLIENT_H

# include <unistd.h>
# include <stdio.h>
# include <sphinxbase/ad.h>
# include <sphinxbase/err.h>
# include "pocketsphinx.h"

char		*recognize_from_mic(cmd_ln_t *config, ps_decoder_t *ps);
char		*get_user_speech(void);

#endif //KIFT_CLIENT_H
