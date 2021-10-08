/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2021/10/08 16:41:36 by ebarguil         ###   ########.fr       */
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

void	ft_free(t_adm *adm, char **str)
{
	int	i;

	i = -1;
	if (str)
	{
		while (str[++i])
			free(str[i]);
		free(str);
	}
	list_delete(adm);
	return ;
}

int	ft_free_error(t_adm *adm, char **str, int x)
{
	int	i;

	i = -1;
	if (x)
		ft_free(adm, str);
	else
		if (str)
		{
			while (str[++i])
				free(str[i]);
			free(str);
		}
	return (1);
}

int	one_arg(char *s, t_adm *adm, t_dll *dll)
{
	char	**str;
	long	num;
	int		i;

	if (ft_checker_1(s, 1))
		return (1);
	str = ft_split(s, " ");
	if (str == NULL)
		return (1);
	num = ft_atoi(str[0]);
	if (num > INT_MAX || num < INT_MIN)
		return (ft_free_error(adm, str, 0));
	adm = list_init(adm, dll, num);
	i = 1;
	while (str[i])
	{
		num = ft_atoi(str[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (ft_free_error(adm, str, 1));
		list_inser(adm, num);
		i++;
	}
	list_display(adm);
	ft_free(adm, str);
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
