/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2021/10/10 17:06:11 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checker_1(char *s, int x)
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

int	ft_doub(t_adm *adm)
{
	t_dll	*now[2];
	int		y;

	now[0] = adm->head;
	y = now[0]->n;
	while (now[0]->next != adm->head)
	{
		y = now[0]->n;
		now[1] = adm->head;
		while (now[1]->next != adm->head)
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

int	one_arg(char *s, t_adm *adm, t_dll *dll)
{
	char	**str;
	long	num;

	if (ft_checker_1(s, 1))
		return (1);
	str = ft_split(s, " ");
	if (!str || !str[1])
		return (free_error(adm, str, 0));
	num = ft_atoi(str[0]);
	if (num > INT_MAX || num < INT_MIN)
		return (free_error(adm, str, 0));
	adm = list_init(adm, dll, num);
	if (list_enter(adm, str) || ft_doub(adm) || ft_sor(adm) || ft_sor_rev(adm))
		return (free_error(adm, str, 1));
	list_display(adm);
	free_all(adm, str);
	return (0);
}

int	main(int ac, char **av)
{
	t_dll	*dll;
	t_adm	*adm;
	int		e;

	dll = NULL;
	adm = NULL;
	e = 0;
	if (ac <= 1)
		e = 1;
	else if (ac == 2)
		e = one_arg(av[1], adm, dll);
	if (e)
		write(2, "Error\n", 6);
	return (0);
}
