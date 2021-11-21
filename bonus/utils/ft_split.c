/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:13:51 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/21 18:35:43 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

static void	*ft_free(char **strs)
{
	int	i;

	i = -1;
	if (strs)
	{
		while (strs[++i])
			free(strs[i]);
		free(strs);
	}
	return (0);
}

static int	ft_is_from_charset(char c, char *charset)
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

static int	ft_count_words(char *str, char *charset)
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

static char	*ft_strcut(char *str, char *charset)
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
	int		i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = ft_count_words(str, charset);
	strs = malloc(sizeof(strs) * (i[2] + 1));
	if (strs == NULL)
		return (0);
	while (str[i[0]])
	{
		while (str[i[0]] && ft_is_from_charset(str[i[0]], charset))
			i[0]++;
		if (i[1] < i[2])
		{
			strs[i[1]] = ft_strcut(&str[i[0]], charset);
			if (strs == NULL)
				return (ft_free(strs));
			i[1]++;
		}
		while (str[i[0]] && !ft_is_from_charset(str[i[0]], charset))
			i[0]++;
	}
	strs[i[1]] = 0;
	return (strs);
}
