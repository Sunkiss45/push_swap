/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2021/10/05 16:57:35 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	one_arg(char *s)
{
	int	i;

	i = 0;
	if (s == NULL || s[i] == '\0')
		return (1);
	while (s[i])
	{
		if ((s[i] >= 48 && s[i] <= 57) || s[i] == 45 || s[i] == 43
			|| s[i] == 32)
			i++;
		else
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_dll	*dll;
	t_adm	*adm;
	int		e;

	e = 0;
	if (ac <= 1)
		e = 1;
	else if (ac == 2)
		e = one_arg(av[1]);
	if (e)
		write(2, "Error\n", 6);
	return (0);
}
