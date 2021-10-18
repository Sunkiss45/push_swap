/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3-5num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:27:52 by ebarguil          #+#    #+#             */
/*   Updated: 2021/10/18 17:11:28 by ebarguil         ###   ########.fr       */
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
	ft_p(adma, admb, "pb\n");
	ft_p(adma, admb, "pb\n");
	algo_3(adma);
	ft_p(admb, adma, "pa\n");

}
