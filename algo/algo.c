/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:07:33 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/20 21:56:40 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_index(t_adm *adm)
{
	t_dll	*now[2];
	int		x[2];

	x[0] = 0;
	now[0] = adm->head;
	while (x[0]++ < count_nb(adm))
	{
		x[1] = 0;
		now[1] = adm->head;
		while (x[1]++ < count_nb(adm))
		{
			if (now[0]->n > now[1]->n)
				now[0]->i++;
			now[1] = now[1]->next;
		}
		now[0] = now[0]->next;
	}
}

int	count_nb(t_adm *adm)
{
	t_dll	*now;
	int		i;

	now = adm->head;
	if (!now)
		return (0);
	i = 1;
	while (now->next != adm->head)
	{
		i++;
		now = now->next;
	}
	return (i);
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

void	algo_main(t_adm *adma, t_adm *admb)
{
	t_dll	*now[3];
	int		i;

	i = count_nb(adma);
	if (i == 2)
		return (ft_s(adma, "sa\n"));
	else if (i == 3)
		return (algo_3(adma));
	else if (i == 4)
		return (algo_4(adma, admb));
	else if (i == 5)
		return (algo_5(adma, admb));
	else
		ft_p(adma, admb, "pb\n");
	return (bignum(adma, admb, now, 0));
}
