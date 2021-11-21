/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opesup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:44:26 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/21 23:07:28 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_ds(t_adm *adma, t_adm *admb, char *s)
{
	ft_s(adma, NULL);
	ft_s(admb, NULL);
	if (s)
		write(1, &s[0], 3);
	return (0);
}

int	ft_dr(t_adm *adma, t_adm *admb, char *s)
{
	ft_r(adma, NULL);
	ft_r(admb, NULL);
	if (s)
		write(1, &s[0], 3);
	return (0);
}

int	ft_drr(t_adm *adma, t_adm *admb, char *s)
{
	ft_rr(adma, NULL);
	ft_rr(admb, NULL);
	if (s)
		write(1, &s[0], 4);
	return (0);
}
