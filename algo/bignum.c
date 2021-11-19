/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:18:43 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/19 21:20:27 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_calc_rot(t_adm *adm, int i)
{
	t_dll	*now;
	int		op;

	now = adm->head;
	op = 0;
	while (i != now->i && op++ != -1)
		now = now->next;
	now->rev = 0;
	if (op > (count_nb(adm) / 2))
	{
		now = adm->head;
		op = 0;
		while (i != now->i && op++ != -1)
			now = now->prev;
		now->rev = 1;
	}
	return (op);
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

void	ft_push_opti(t_adm *adma, t_adm *admb, t_dll *opti)
{
	while (opti->opr-- > 0)
	{
		if (opti->rev)
			ft_drr(adma, admb, "rrr\n");
		else
			ft_dr(adma, admb, "rr\n");
	}
	while (opti->opa-- > 0)
	{
		if (opti->rev)
			ft_rr(adma, "rra\n");
		else
			ft_r(adma, "ra\n");
	}
	while (opti->opb-- > 0)
	{
		if (opti->revb)
			ft_rr(admb, "rrb\n");
		else
			ft_r(admb, "rb\n");
	}
	ft_p(adma, admb, "pb\n");
}

void	do_final(t_adm *adma, t_adm *admb)
{
	t_dll	*now;
	int		x;

	while (admb->head)
		ft_p(admb, adma, "pa\n");
	now = adma->head;
	x = ft_calc_rot(adma, 0);
	while (now->i != 0)
		now = now->next;
	while (x-- > 0)
	{
		if (now->rev)
			ft_rr(adma, "rra\n");
		else
			ft_r(adma, "ra\n");
	}
}

t_dll	**init_rdm(t_adm *adma, t_adm *admb, t_dll **now)
{
	now[1] = pos_b(now[0], admb);
	now[0]->opa = ft_calc_rot(adma, now[0]->i);
	now[0]->opb = ft_calc_rot(admb, now[1]->i);
	now[0]->revb = now[1]->rev;
	now[0]->opr = 0;
	return (now);
}

void	bignum(t_adm *adma, t_adm *admb, t_dll **now, int x)
{
	while (adma->head)
	{
		x = 0;
		now[0] = adma->head;
		now[2] = adma->head;
		while (x++ < count_nb(adma))
		{
			now = init_rdm(adma, admb, now);
			if (now[0]->rev == now[1]->rev)
				while (now[0]->opa > 0 && now[0]->opb > 0 
					&& now[0]->opa-- != -1 && now[0]->opb-- != -1)
					now[0]->opr++;
			now[0]->opt = (now[0]->opa + now[0]->opb + now[0]->opr);
			if (now[0]->opt < now[2]->opt)
				now[2] = now[0];
			now[0] = now[0]->next;
		}
		ft_push_opti(adma, admb, now[2]);
	}
	do_final(adma, admb);
}
