/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:35:43 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/12 15:36:14 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	pre_algo(t_adm *adma, t_adm *admb, char **str)
{
	int	i;

	i = 0;
	if (count_nb(adma) == 1)
		return (free_all(adma, admb, str, 0));
	if (ft_sorr(adma) && count_nb(adma) > 5)
		i = is_sorr(adma, admb);
	ft_index(adma);
	i += is_rot(adma);
	if (!i)
		algo_main(adma, admb);
	list_display(adma, admb);
	return (free_all(adma, admb, str, 0));
}
