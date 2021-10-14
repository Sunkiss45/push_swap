/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <ebarguil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:46:54 by ebarguil          #+#    #+#             */
/*   Updated: 2021/10/14 15:57:34 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_delete(t_adm *adm, int x)
{
	t_dll	*now;

	if (!adm)
		return (x);
	now = adm->head;
	while (now != adm->tail)
	{
		now = now->next;
		free(now->prev);
	}
	free(now);
	free(adm);
	return (x);
}
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
	list_delete(adm, 0);
	return (x);
}
