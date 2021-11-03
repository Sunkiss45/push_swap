/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/03 17:31:30 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_one(char *s, int x)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (s == NULL || s[0] == '\0')
		return (1);
	while (s[i + y])
	{
		if (s[i + y] >= 48 && s[i + y] <= 57)
			y++;
		else if (s[i + y] == 43 || s[i + y] == 45)
		{
			if (s[i + y + 1] < 48 || s[i + y + 1] > 57)
				return (1);
			i++;
		}
		else if (x && s[i + y] == 32)
			i++;
		else
			return (1);
	}
	if (y == 0)
		return (1);
	return (0);
}

int	ft_check_more(char **s)
{
	int	i;

	i = 1;
	while (s[i])
	{
		if (ft_check_one(s[i], 0))
			return (1);
		i++;
	}
	return (0);
}

int	ft_doub(t_adm *adm)
{
	t_dll	*now[2];
	int		y;

	now[0] = adm->head;
	y = now[0]->n;
	while (now[0] != adm->tail)
	{
		y = now[0]->n;
		now[1] = adm->head;
		while (now[1] != adm->tail)
		{
			if (y == now[1]->next->n && now[0] != now[1]->next)
				return (1);
			now[1] = now[1]->next;
		}
		now[0] = now[0]->next;
	}
	return (0);
}

int	ft_sor(t_adm *adm)
{
	t_dll	*now;

	now = adm->head;
	while (now->next != adm->head && now->n < now->next->n)
		now = now->next;
	if (now->next == adm->head)
		return (1);
	return (0);
}

int	ft_sor_rev(t_adm *adm)
{
	t_dll	*now;

	now = adm->tail;
	while (now->prev != adm->tail && now->n < now->prev->n)
		now = now->prev;
	if (now->prev == adm->tail)
		return (1);
	return (0);
}
