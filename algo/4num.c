/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4num.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:56:37 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/12 16:59:55 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	counter(t_adm *adm)
{
	t_dll	*now;
	int		y;

	now = adm->head;
	y = now->i;
	while (now != adm->tail)
	{
		if (now->i < y)
			y = now->i;
		now = now->next;
	}
	if (now->i < y)
		y = now->i;
	return (y);
}

static void	rot2(t_adm *adma, int	*i)
{
	int	y;

	y = counter(adma);
	i[0] = 0;
	i[1] = adma->head->i;
	while (adma->head->i != y && i[0]++ != -1)
		ft_r(adma, NULL);
	while (adma->head->i != i[1])
		ft_r(adma, NULL);
	if (i[0] > (count_nb(adma) / 2))
		while (adma->head->i != y)
			ft_rr(adma, "rra\n");
	else
		while (adma->head->i != y)
			ft_r(adma, "ra\n");
}

static void	rot(t_adm *adma, t_adm *admb, int x)
{
	int	i[2];

	if (x)
		ft_p(adma, admb, "pb\n");
	i[0] = 0;
	i[1] = adma->head->i;
	while (adma->head->i < admb->head->i && i[0]++ != -1)
		ft_r(adma, NULL);
	while (adma->head->i != i[1])
		ft_r(adma, NULL);
	if (i[0] > (count_nb(adma) / 2))
		while (adma->head->i < admb->head->i)
			ft_rr(adma, "rra\n");
	else
		while (adma->head->i < admb->head->i)
			ft_r(adma, "ra\n");
	ft_p(admb, adma, "pa\n");
	rot2(adma, i);
}

void	algo_4(t_adm *adma, t_adm *admb)
{
	ft_p(adma, admb, "pb\n");
	if (!ft_sor(adma))
		algo_3(adma);
	if (admb->head->i == 0 || admb->head->i >= 3)
	{
		ft_p(admb, adma, "pa\n");
		if (adma->head->i >= 3)
			ft_r(adma, "ra\n");
	}
	else
		rot(adma, admb, 0);
}
