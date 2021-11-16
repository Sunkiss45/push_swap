/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:18:43 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/16 17:39:39 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	ft_calc_rot(t_adm *adm, int i)
{
	t_dll	*now;
	int		c;

	now = adm->head;
	c = 0;
	while(i != now->i && c++ != -1)
		now = now->next;
	now->r = 0;
	if (c > (count_nb(adm) / 2))
	{
		now = adm->head;
		c = 0;
		while(i != now->i && c++ != -1)
			now = now->prev;
		now->r = 1;
	}
	return (0);
}

t_dll	*pos_b(t_dll *pa, t_adm *admb)
{
	t_dll	*pb;
	int		m[2];

	pb = admb->head;
	m[0] = INT_MAX;
	m[1] = 0;
	while (pb != admb->tail)
	{
		if (pb->i < m[0])
			m[0] = pb->i;
		if (pb->i > m[1])
			m[1] = pb->i;
		if (pa->i > pb->i && pa->i < pb->prev->i)
			return (pb);
		pb = pb->next;
	}
/* FAIRE GAFFE A TAIL */
	pb = admb->head;
	if (pa->i < m[0] || pa->i > m[1])
		while (pb->i != m[1])
			pb = pb->next;
	return (pb);
}

void	mort(t_adm *adma, t_adm *admb)
{
	t_dll	*now[2];
//	int		c;

	now[0] = adma->head;
	while(now[0] != adma->tail)
	{
		now[1] = pos_b(now[0], admb);
		ft_calc_rot(adma, 0);
		now[0] = now[0]->next;
	}
	
//	if (adma->head)
//		return (mort(adma, admb));
	return ;
}
