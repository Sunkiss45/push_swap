/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:46:54 by ebarguil          #+#    #+#             */
/*   Updated: 2021/10/11 16:17:33 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **str)
{
	int	i;

	i = -1;
	if (str)
	{
		while (str[++i])
			free(str[i]);
		free(str);
	}
	return ;
}

int	free_all(t_adm *adm, char **str, int x)
{
	free_split(str);
	list_delete(adm);
	if (x)
		return (1);
	return (0);
}

int	free_error(t_adm *adm, char **str, int x)
{
	if (x)
		free_all(adm, str, 1);
	else
		free_split(str);
	return (1);
}
