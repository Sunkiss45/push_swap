/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:07:33 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/16 14:23:18 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	algo_main(t_adm *adma, t_adm *admb)
{
	int	i;

	i = count_nb(admb);
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
	{
		ft_p(adma, admb, "pb\n");
		return (mort(adma, admb));
	}
}
