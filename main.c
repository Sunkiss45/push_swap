/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2021/10/14 16:37:47 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	more_arg(char **str, t_adm *adm, t_dll *dll)
{
	long	num;

	if (ft_check_more(str))
		return (1);
	num = ft_atoi(str[1]);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	adm = list_init_a(adm, dll, num);
	if (list_enter(adm, str, 2) || ft_doub(adm))
		return (list_delete(adm, 1));
	if (ft_sor(adm) || ft_sor_rev(adm))
		return (list_delete(adm, 0));
	list_display(adm);
	return (list_delete(adm, 0));
}

int	one_arg(char *s, t_adm *adma, t_dll *dll)
{
	t_adm	*admb;
	char	**str;
	long	num;

	if (ft_check_one(s, 1))
		return (1);
	str = ft_split(s, " ");
	if (!str || !str[1])
		return (free_all(adma, str, 1));
	num = ft_atoi(str[0]);
	if (num > INT_MAX || num < INT_MIN)
		return (free_all(adma, str, 1));
	adma = list_init_a(adma, dll, num);
	admb = list_init_b(admb);
	if (adma == NULL || admb == NULL)
		return (free_all(adma, str, 1));
	if (list_enter(adma, str, 1) || ft_doub(adma))
		return (free_all(adma, str, 1));
	if (ft_sor(adma) || ft_sor_rev(adma))
		return (free_all(adma, str, 0));
	
	list_display(adma);
	return (free_all(adma, str, 0));
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
	else
		e = more_arg(av, adm, dll);
	if (e)
		write(2, "Error\n", 6);
	return (0);
}
