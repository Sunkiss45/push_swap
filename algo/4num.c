/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4num.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:56:37 by ebarguil          #+#    #+#             */
/*   Updated: 2021/10/27 21:54:53 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rot2(t_adm *adma, int	*i)
{
	i[0] = 0;
	i[1] = adma->head->i;
	while (adma->head->i != 0 && i[0]++ != -1)
		ft_r(adma, NULL);
	while (adma->head->i != i[1])
		ft_r(adma, NULL);
	if (i[0] > (count_nb(adma) / 2))
		while (adma->head->i != 0)
			ft_rr(adma, "rra\n");
	else
		while (adma->head->i != 0)
			ft_r(adma, "ra\n");
}

void	rot(t_adm *adma, t_adm *admb)
{
	int	i[2];

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
	ft_p(adma, admb, NULL);
	if (ft_sor(adma))
	{
		ft_p(admb, adma, NULL);
		ft_r(adma, NULL);
		if (ft_sor(adma))
			write(1, "ra\n", 3);
		else
		{
			ft_rr(adma, NULL);
			rot(adma, admb);
		}
	}
}
