/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-5num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:27:52 by ebarguil          #+#    #+#             */
/*   Updated: 2021/10/27 20:56:21 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_3(t_adm *adm)
{
	t_dll	*mid;

	mid = adm->head->next;
	if (ft_sor_rev(adm))
	{
		ft_s(adm, "sa\n");
		ft_rr(adm, "rra\n");
	}
	else if (adm->head->n > mid->n)
	{
		if (adm->tail->n > adm->head->n)
			ft_s(adm, "sa\n");
		else if (adm->tail->n < adm->head->n)
			ft_r(adm, "ra\n");
	}
	else if (adm->head->n < mid->n)
	{
		if (adm->tail->n > adm->head->n)
		{
			ft_s(adm, "sa\n");
			ft_r(adm, "ra\n");
		}
		else if (adm->tail->n < adm->head->n)
			ft_rr(adm, "rra\n");
	}
}

void	algo_5(t_adm *adma, t_adm *admb)
{
	while (count_nb(adma) > 3)
		ft_p(adma, admb, NULL);
	if (ft_sor(adma))
		while (admb->head)
			ft_p(admb, adma, NULL);
	else
	{
		while (admb->head)
			ft_p(admb, adma, NULL);
		while (count_nb(adma) > 3)
			ft_p(adma, admb, "pb\n");
		algo_3(adma);
	}
	while (admb->head)
	{
		if (admb->head->i > adma->tail->i)
		{
			ft_p(admb, adma, "pa\n");
			ft_r(adma, "ra\n");
		}
		else if (admb->head->i < adma->head->i)
			ft_p(admb, adma, "pa\n");
	}
	return ;
}
