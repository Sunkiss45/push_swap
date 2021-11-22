/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/22 14:10:43 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	count_nb(t_adm *adm)
{
	t_dll	*now;
	int		i;

	now = adm->head;
	if (!now)
		return (0);
	i = 1;
	while (now->next != adm->head)
	{
		i++;
		now = now->next;
	}
	return (i);
}

int	pre_inst(t_adm **adm, char **str)
{
	char	*line;
	int		ret;

	ret = 0;
	ret = get_next_line(0, &line);
	if (instru(line, adm[0], adm[1]) || (ret == 0 && line[0] != '\0'))
		return (free_all(adm, str, line, 1));
	free(line);
	while (ret == 1)
	{
		ret = get_next_line(0, &line);
		if (instru(line, adm[0], adm[1]) || (ret == 0 && line[0] != '\0'))
			return (free_all(adm, str, line, 1));
		free(line);
	}
	if (count_nb(adm[0]) != adm[0]->base || count_nb(adm[1])
		|| !ft_sor(adm[0]))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	return (free_all(adm, str, NULL, 0));
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

int	start_sort(char *s, t_adm **adm, t_dll *dll)
{
	char	**str;
	long	num;

	if (ft_check(s))
		return (1);
	str = ft_split(s, " ");
	if (ft_tolong(str, 0))
		return (free_all(adm, str, NULL, 1));
	num = ft_atoi(str[0]);
	if (num > INT_MAX || num < INT_MIN)
		return (free_all(adm, str, NULL, 1));
	adm[0] = list_init_a(adm[0], dll, num);
	adm[1] = list_init_b(adm[0]);
	if (adm[0] == NULL || adm[1] == NULL || list_enter(adm[0], str, 1)
		|| ft_doub(adm[0]))
		return (free_all(adm, str, NULL, 1));
	adm[0]->base = count_nb(adm[0]);
	return (pre_inst(adm, str));
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
		e = start_sort(s, adm, dll);
		free_strjoin(s, 0);
	}
	if (e)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
