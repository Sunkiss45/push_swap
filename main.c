/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2021/10/07 15:10:29 by ebarguil         ###   ########.fr       */
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

int	one_arg(char *s)
{
	char	**str;
	int		i;

//	printf(RED"Si +1 -> %d\n", ft_checker_1(s, 1));
//	printf(RED"Si =1 -> %d\n", ft_checker_1(s, 0));
	if (ft_checker_1(s, 1))
		return (1);
	str = ft_split(s, " ");
	if (str == NULL)
		return (1);
	i = 0;
	while (str[i])
	{
		printf(GREEN"[%s]\n", str[i]);
		i++;
	}
	printf(YELLOW"(%d)\n", i);
	return (0);
}

int	main(int ac, char **av)
{
//	t_dll	*dll;
//	t_adm	*adm;
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
