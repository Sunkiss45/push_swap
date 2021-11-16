/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:18:43 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/16 14:28:34 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static int	ft_calc_rot(t_adm *adm, int i)
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

void	mort(t_adm *adma, t_adm *admb)
{
	t_dll	*now[2];
//	int		c;

	now[0] = adma->head;
	while(now[0] != adma->tail)
	{
		now[1] = admb->head;
		while(now[1] != admb->tail && now[0]->i < now[1]->i)
			now[1] = now[1]->next;
		if (now[1] == admb->tail)
			now[1] = admb->head;
		ft_calc_rot(adma, 0);
		now[0] = now[0]->next;
	}
	
//	if (adma->head)
//		return (mort(adma, admb));
	return ;
}
