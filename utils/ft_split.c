/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:13:51 by ebarguil          #+#    #+#             */
/*   Updated: 2021/10/07 11:36:26 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../push_swap.h"

int	ft_is_from_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && ft_is_from_charset(str[i], charset))
			i++;
		while (str[i] && !ft_is_from_charset(str[i], charset))
			i++;
		if (i && !ft_is_from_charset(str[i - 1], charset))
			j++;
	}
	return (j);
}

char	*ft_strcut(char *str, char *charset)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i] && !ft_is_from_charset(str[i], charset))
		i++;
	new_str = malloc(sizeof(new_str) * (i + 1));
	if (new_str == NULL)
		return (0);
	i = 0;
	while (str[i] && !ft_is_from_charset(str[i], charset))
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = ft_count_words(str, charset);
	strs = malloc(sizeof(strs) * (j + 1));
	if (strs == NULL)
		return (0);
	while (str[i])
	{
		while (str[i] && ft_is_from_charset(str[i], charset))
			i++;
		if (k < j)
		{
			strs[k] = ft_strcut(&str[i], charset);
			k++;
		}
		while (str[i] && !ft_is_from_charset(str[i], charset))
			i++;
	}
	strs[k] = 0;
	return (strs);
}
