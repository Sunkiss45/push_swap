/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:03:54 by ebarguil          #+#    #+#             */
/*   Updated: 2021/10/18 15:54:13 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s(t_adm *adm, char *s)
{
	int	y;

	y = adm->head->n;
	adm->head->n = adm->head->next->n;
	adm->head->next->n = y;
	write(1, &s[0], 3);
	return ;
}

void	ft_r(t_adm *adm, char *s)
{
	adm->head = adm->head->next;
	adm->tail = adm->tail->next;
	write(1, &s[0], 3);
	return ;
}

void	ft_rr(t_adm *adm, char *s)
{
	adm->head = adm->head->prev;
	adm->tail = adm->tail->prev;
	write(1, &s[0], 4);
	return ;
}

void	ft_p2(t_adm *admto, t_dll *now)
{
	if (!admto->head)
	{
		admto->head = now;
		admto->tail = now;
		now->next = admto->head;
		now->prev = admto->tail;
	}
	else
	{
		now->next = admto->head;
		now->prev = admto->tail;
		admto->head = now;
		admto->tail->next = admto->head;
		now->next->prev = now;
	}
	return ;
}

void	ft_p(t_adm *admfrom, t_adm *admto, char *s)
{
	t_dll	*now;

	now = admfrom->head;
	if (now->next == now)
	{
		admfrom->head = NULL;
		admfrom->tail = NULL;
	}
	else
	{
		admfrom->head = now->next;
		now->next->prev = admfrom->tail;
		admfrom->tail->next = admfrom->head;
	}
	ft_p2(admto, now);
	write(1, &s[0], 3);
	return ;
}

/*void	ft_r(t_adm *adm)
{
	t_dll	*now;
	int		y;

	now = adm->head;
	y = now->n;
	now->n = adm->tail->n;
	adm->tail->n = y;
	return ;
}

void	ft_rr(t_adm *adm)
{
	t_dll	*now;
	int		y;

	now = adm->tail;
	y = now->n;
	now->n = adm->head->n;
	adm->head->n = y;
	return ;
}*/
