/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opesup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:44:26 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/19 12:01:12 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dr(t_adm *adma, t_adm *admb, char *s)
{
	ft_r(adma, NULL);
	ft_r(admb, NULL);
	if (s)
		write(1, &s[0], 3);
}

void	ft_drr(t_adm *adma, t_adm *admb, char *s)
{
	ft_rr(adma, NULL);
	ft_rr(admb, NULL);
	if (s)
		write(1, &s[0], 4);
}
