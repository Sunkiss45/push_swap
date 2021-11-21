/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/21 23:13:10 by ebarguil         ###   ########.fr       */
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

int	cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 && s2)
		while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
			i++;
	return (s1[i] - s2[i]);
}

int	instru(char *s, t_adm *adma, t_adm *admb)
{
	if (!cmp(s, "\0"))
		return (0);
	else if (!cmp(s, "ss"))
		return (ft_ds(adma, admb, NULL));
	else if (!cmp(s, "sa"))
		return (ft_s(adma, NULL));
	else if (!cmp(s, "sb"))
		return (ft_s(admb, NULL));
	else if (!cmp(s, "rr"))
		return (ft_dr(adma, admb, NULL));
	else if (!cmp(s, "ra"))
		return (ft_r(adma, NULL));
	else if (!cmp(s, "rb"))
		return (ft_r(admb, NULL));
	else if (!cmp(s, "rrr"))
		return (ft_drr(adma, admb, NULL));
	else if (!cmp(s, "rra"))
		return (ft_rr(adma, NULL));
	else if (!cmp(s, "rrb"))
		return (ft_rr(admb, NULL));
	else if (!cmp(s, "pa"))
		return (ft_p(admb, adma, NULL));
	else if (!cmp(s, "pb"))
		return (ft_p(adma, admb, NULL));
	return (1);
}

int	pre_inst(t_adm *adma, t_adm *admb, char **str)
{
	char	*line;
	int		ret;

	ret = 0;
	if (count_nb(adma) == 1)
		return (free_all(adma, admb, str, 0));
	ret = get_next_line(1, &line);
	printf(GREEN"[%s]"RESET"\n", line);
	if (instru(line, adma, admb) || (ret == 0 && line[0] != '\0'))
		return (free_all(adma, admb, str, 1));
	list_display(adma, admb);
	free(line);
	while (ret == 1)
	{
		ret = get_next_line(1, &line);
		printf(GREEN"[%s]"RESET"\n", line);
		if (instru(line, adma, admb) || (ret == 0 && line[0] != '\0'))
			return (free_all(adma, admb, str, 1));
		list_display(adma, admb);
		free(line);
	}
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
	return (pre_inst(adma, admb, str));
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
