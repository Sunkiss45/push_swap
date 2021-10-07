/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2021/10/07 16:05:33 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checker_1(char *s, int x)
{
	int	i;

	i = 0;
	if (s == NULL || s[i] == '\0')
		return (1);
	while (s[i])
	{
		if (s[i] >= 48 && s[i] <= 57)
			i++;
		else if (s[i] == 43 || s[i] == 45)
		{
			if (s[i + 1] < 48 || s[i + 1] > 57)
				return (1);
			i++;
		}
		else if (x && s[i] == 32)
			i++;
		else
			return (1);
	}
	return (0);
}

int	one_arg(char *s, t_adm *adm, t_dll *dll)
{
	char	**str;
	int		i;
	int		num;

	if (ft_checker_1(s, 1))
		return (1);
	str = ft_split(s, " ");
	if (str == NULL)
		return (1);
	num = ft_atoi(str[0]);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	adm = list_init(adm, dll, num);
	i = 1;
	while (str[i])
	{
		num = ft_atoi(str[i]);
		if (num > INT_MAX || num < INT_MIN)
			return(1);
		list_inser(adm, num);
		i++;
	}
	list_display(adm);
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
