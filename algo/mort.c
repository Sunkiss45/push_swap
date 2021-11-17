/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:18:43 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/17 17:28:49 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_calc_rot(t_adm *adm, int i)
{
	t_dll	*now;
	int		c;

	now = adm->head;
	c = 0;
	while (i != now->i && c++ != -1)
		now = now->next;
	now->r = 0;
	if (c > (count_nb(adm) / 2))
	{
		now = adm->head;
		c = 0;
		while (i != now->i && c++ != -1)
			now = now->prev;
		now->r = 1;
	}
	return (0);
}

t_dll	*pos_b(t_dll *pa, t_adm *admb)
{
	t_dll	*pb;
	int		x[2];

	pb = admb->head;
	x[0] = 0;
	x[1] = 0;
	if (admb->head == admb->tail)
		return (pb);
	while (x[0]++ < count_nb(admb))
	{
		if (pb->i > x[1])
			x[1] = pb->i;
		if (pa->i > pb->i && pa->i < pb->prev->i)
			return (pb);
		pb = pb->next;
	}
	while (pb->i != x[1])
		pb = pb->next;
	return (pb);
}

void	mort(t_adm *adma, t_adm *admb)
{
	t_dll	*now[2];
	int		x;
//	int		c;

	x = 0;
/*ft_p(adma, admb, "pb\n");
ft_p(adma, admb, "pb\n");
ft_p(adma, admb, "pb\n");
ft_p(adma, admb, "pb\n");*/
	now[0] = adma->head;
	while (x++ < count_nb(adma))
	{
		now[1] = pos_b(now[0], admb);
		printf(RED"\nnow[0]->n = [%d] to now[1]->n = [%d]\n"RESET, now[0]->n,
			now[1]->n);
//		ft_calc_rot(adma, 0);
		now[0] = now[0]->next;
	}
//	if (adma->head)
//		return (mort(adma, admb));
	return ;
}
