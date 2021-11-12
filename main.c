/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/12 14:34:36 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_adm *adm)
{
	t_dll	*now[2];

	now[0] = adm->head;
	while (now[0] != adm->tail)
	{
		now[1] = adm->head;
		while (now[1] != adm->tail)
		{
			if (now[0]->n > now[1]->n)
				now[0]->i++;
			now[1] = now[1]->next;
		}
		if (now[0]->n > now[1]->n)
			now[0]->i++;
		now[0] = now[0]->next;
	}
	now[1] = adm->head;
	while (now[1] != adm->tail)
	{
		if (now[0]->n > now[1]->n)
			now[0]->i++;
		now[1] = now[1]->next;
	}
	if (now[0]->n > now[1]->n)
		now[0]->i++;
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

int	more_arg(char **str, t_adm *adma, t_adm *admb, t_dll *dll)
{
	long	num;

	if (ft_check_more(str))
		return (1);
	num = ft_atoi(str[1]);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	adma = list_init_a(adma, dll, num);
	admb = list_init_b(admb);
	if (adma == NULL || admb == NULL || list_enter(adma, str, 2)
		|| ft_doub(adma))
		return (free_all(adma, admb, NULL, 1));
	if (ft_sor(adma))
		return (free_all(adma, admb, NULL, 0));
	return (pre_algo(adma, admb, NULL));
}

int	one_arg(char *s, t_adm *adma, t_adm *admb, t_dll *dll)
{
	char	**str;
	long	num;

	if (ft_check_one(s, 1))
		return (1);
	str = ft_split(s, " ");
	if (!str || !str[0])
		return (free_all(adma, admb, str, 1));
	num = ft_atoi(str[0]);
	if (num > INT_MAX || num < INT_MIN)
		return (free_all(adma, admb, str, 1));
	adma = list_init_a(adma, dll, num);
	admb = list_init_b(admb);
	if (adma == NULL || admb == NULL || list_enter(adma, str, 1)
		|| ft_doub(adma))
		return (free_all(adma, admb, str, 1));
	if (ft_sor(adma))
		return (free_all(adma, admb, str, 0));
	return (pre_algo(adma, admb, str));
}

int	main(int ac, char **av)
{
	t_dll	*dll;
	t_adm	*adma;
	t_adm	*admb;
	int		e;

	dll = NULL;
	adma = NULL;
	admb = NULL;
	e = 0;
	if (ac == 1)
		return (0);
	else if (ac == 2)
		e = one_arg(av[1], adma, admb, dll);
	else
		e = more_arg(av, adma, admb, dll);
	if (e)
		write(2, "Error\n", 6);
	return (0);
}
