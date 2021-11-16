/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/16 14:22:46 by ebarguil         ###   ########.fr       */
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
	list_display(adma, admb);
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

int	more_arg(char **str, t_adm *adma, t_adm *admb, t_dll *dll)
{
	long	num;

	if (ft_check_more(str))
		return (1);
	if (ft_tolong(str, 1))
		return (free_all(adma, admb, NULL, 1));
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
