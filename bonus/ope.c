/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:03:54 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/21 23:03:50 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_s(t_adm *adm, char *s)
{
	int	y;

	if (!adm->head)
		return (0);
	y = adm->head->n;
	adm->head->n = adm->head->next->n;
	adm->head->next->n = y;
	if (s)
		write(1, &s[0], 3);
	return (0);
}

int	ft_r(t_adm *adm, char *s)
{
	if (!adm->head)
		return (0);
	adm->head = adm->head->next;
	adm->tail = adm->tail->next;
	if (s)
		write(1, &s[0], 3);
	return (0);
}

int	ft_rr(t_adm *adm, char *s)
{
	if (!adm->head)
		return (0);
	adm->head = adm->head->prev;
	adm->tail = adm->tail->prev;
	if (s)
		write(1, &s[0], 4);
	return (0);
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

int	ft_p(t_adm *admfrom, t_adm *admto, char *s)
{
	t_dll	*now;

	if (!admfrom->head)
		return (0);
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
	if (s)
		write(1, &s[0], 3);
	return (0);
}
