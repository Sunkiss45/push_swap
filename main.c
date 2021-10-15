/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2021/10/15 21:30:09 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (adma == NULL || admb == NULL)
		return (free_all(adma, admb, NULL, 1));
	if (list_enter(adma, str, 2) || ft_doub(adma))
		return (free_all(adma, admb, NULL, 1));
	if (ft_sor(adma) || ft_sor_rev(adma))
		return (free_all(adma, admb, NULL, 0));
	list_display(adma, admb);
	return (free_all(adma, admb, NULL, 0));
}

int	one_arg(char *s, t_adm *adma, t_adm *admb, t_dll *dll)
{
	char	**str;
	long	num;

	if (ft_check_one(s, 1))
		return (1);
	str = ft_split(s, " ");
	if (!str || !str[1])
		return (free_all(adma, admb, str, 1));
	num = ft_atoi(str[0]);
	if (num > INT_MAX || num < INT_MIN)
		return (free_all(adma, admb, str, 1));
	adma = list_init_a(adma, dll, num);
	admb = list_init_b(admb);
	if (adma == NULL || admb == NULL)
		return (free_all(adma, admb, str, 1));
	if (list_enter(adma, str, 1) || ft_doub(adma))
		return (free_all(adma, admb, str, 1));
	if (ft_sor(adma) || ft_sor_rev(adma))
		return (free_all(adma, admb, str, 0));
	list_display(adma, admb);
	return (free_all(adma, admb, str, 0));
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
	if (ac <= 1)
		e = 1;
	else if (ac == 2)
		e = one_arg(av[1], adma, admb, dll);
	else
		e = more_arg(av, adma, admb, dll);
	if (e)
		write(2, "Error\n", 6);
	return (0);
}
