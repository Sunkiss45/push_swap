/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo-utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:35:43 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/19 17:41:16 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_index(t_adm *adm)
{
	t_dll	*now[2];
	int		x;

	x = 0;
	now[0] = adm->head;
	while (x++ < count_nb(adm))
	{
		now[1] = adm->head;
		while (now[1] != adm->tail)
		{
			if (now[0]->n > now[1]->n)
				now[0]->i++;
			now[1] = now[1]->next;
		}
		if (now[0]->n > now[1]->n)
			now[0]->i++;
		now[0] = now[0]->next;
	}
}

int	is_rot(t_adm *adm)
{
	t_dll	*now[2];
	int		y;

	now[0] = adm->head;
	y = 0;
	while (now[0]->i != 0 && y++ != -1)
		now[0] = now[0]->next;
	now[1] = now[0];
	while (now[1] != now[0]->prev)
	{
		if (now[1]->i > now[1]->next->i)
			return (0);
		now[1] = now[1]->next;
	}
	if (y > (count_nb(adm) / 2))
		while (adm->head->i != 0)
			ft_rr(adm, "rra\n");
	else
		while (adm->head->i != 0)
			ft_r(adm, "ra\n");
	return (1);
}

int	is_sorr(t_adm *adma, t_adm *admb)
{
	ft_p(adma, admb, "pb\n");
	while (adma->head)
	{
		ft_p(adma, admb, "pb\n");
		ft_r(admb, "rb\n");
	}
	while (admb->head)
		ft_p(admb, adma, "pa\n");
	return (1);
}
