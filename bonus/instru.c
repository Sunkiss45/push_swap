/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instru.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:25:49 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/22 11:27:39 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 && s2)
		while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
			i++;
	return (s1[i] - s2[i]);
}

int	instru(char *s, t_adm *adma, t_adm *admb)
{
	if (!cmp(s, "\0"))
		return (0);
	else if (!cmp(s, "ss"))
		return (ft_ds(adma, admb, NULL));
	else if (!cmp(s, "sa"))
		return (ft_s(adma, NULL));
	else if (!cmp(s, "sb"))
		return (ft_s(admb, NULL));
	else if (!cmp(s, "rr"))
		return (ft_dr(adma, admb, NULL));
	else if (!cmp(s, "ra"))
		return (ft_r(adma, NULL));
	else if (!cmp(s, "rb"))
		return (ft_r(admb, NULL));
	else if (!cmp(s, "rrr"))
		return (ft_drr(adma, admb, NULL));
	else if (!cmp(s, "rra"))
		return (ft_rr(adma, NULL));
	else if (!cmp(s, "rrb"))
		return (ft_rr(admb, NULL));
	else if (!cmp(s, "pa"))
		return (ft_p(admb, adma, NULL));
	else if (!cmp(s, "pb"))
		return (ft_p(adma, admb, NULL));
	return (1);
}
