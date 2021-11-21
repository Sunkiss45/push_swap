/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:04:01 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/21 18:35:28 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

long	ft_atoi(char *s)
{
	char	n;
	long	res;
	int		i;

	i = 0;
	n = '\0';
	if (s[i] == 43 || s[i] == 45)
		n = s[i++];
	res = 0;
	while (s[i] >= 48 && s[i] <= 57)
		res = res * 10 + (s[i++] - 48);
	if (n == 45)
		res *= -1;
	if (s[i] != '\0')
		return (LONG_MAX);
	return (res);
}

/*int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	neg = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (neg % 2 == 1)
		res *= -1;
	return (res);
}*/
