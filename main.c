/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/25 13:24:08 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (free_all(adma, admb, str, 0));
}

int	ft_tolong(char **s, int x)
{
	x -= 1;
	if (!s || !s[0])
		return (1);
	while (s[++x])
	{
		if (ft_strlen(s[x]) > 11)
			return (1);
	}
	return (0);
}

int	start_sort(char *s, t_adm *adma, t_adm *admb, t_dll *dll)
{
	char	**str;
	long	num;

	if (ft_check(s))
		return (1);
	str = ft_split(s, " ");
	if (ft_tolong(str, 0))
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
	t_adm	*adm[2];
	char	*s;
	int		e;

	dll = NULL;
	adm[0] = NULL;
	adm[1] = NULL;
	e = 0;
	if (ac == 1)
		return (0);
	s = ft_strjoin(ac - 1, &av[1], " ");
	if (s == NULL || ft_check_before(av))
		e = free_strjoin(s, 1);
	if (!e)
	{
		e = start_sort(s, adm[0], adm[1], dll);
		free_strjoin(s, 0);
	}
	if (e)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
