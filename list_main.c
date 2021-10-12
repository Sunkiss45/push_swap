/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2021/10/12 15:18:11 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_enter(t_adm *adm, char **str, int i)
{
	long	num;

	while (str[i])
	{
		num = ft_atoi(str[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (1);
		list_inser(adm, num);
		i++;
	}
	return (0);
}

int	list_delete(t_adm *adm, int x)
{
	t_dll	*now;

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

t_adm	*list_init(t_adm *adm, t_dll *dll, int first)
{
	adm = malloc(sizeof(*adm));
	dll = malloc(sizeof(*dll));
	if (adm == NULL || dll == NULL)
		 return (0);
	adm->head = dll;
	adm->tail = dll;
	dll->n = first;
	dll->next = adm->head;
	dll->prev = adm->tail;
	return (adm);
}

void	list_inser(t_adm *adm, int add)
{
	t_dll	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return ;
	new->n = add;
	new->next = adm->head;
	new->prev = adm->tail;
	adm->head->prev = new;
	adm->tail->next = new;
	adm->tail = new;
}

/* ===== Test Zone ===== */

void	list_display(t_adm *adm)
{
	t_dll	*now;
//	char	buf[1024];
	int		i;

	if (adm == NULL)
		return ;

/*	printf(YELLOW"\n--- Liste Chaine simple ---\n\n");
	while (i != 1)
	{
		printf(GREEN"%d -> ", now->n);
		if (now->next == adm->head)
			i = 1;
		now = now->next;
		k++;
	}
	printf(RED"NULL\n\n");

	printf(YELLOW"--- Liste Chaine Double ---\n\n");
	i = 0;
	printf(RED"NULL -> ");
	now = adm->head;
	while (i != 1)
	{
		printf(GREEN"%d -> ", now->n);
		if (now->next == adm->head)
			i = 1;
		now = now->next;
	}
	printf(RED"NULL\n");

	i = 0;
	printf(RED"NULL -> ");
	now = adm->tail;
	while (i != 1)
	{
		printf(GREEN"%d -> ", now->n);
		if (now->prev == adm->tail)
			i = 1;
		now = now->prev;
	}
	printf(RED"NULL\n\n");*/

	printf(YELLOW"\n--- Liste ---\n\n");
	i = -1;
	now = adm->head;
	while (i != 1)
	{
		if (now == adm->tail)
			printf(BLUE"t:");
		if (now == adm->head)
			printf(CYAN"h:");
		printf(GREEN"%d -> ", now->n);
		if (now == adm->head)
			i++;
		now = now->next;
	}
	printf(RED"...\n");

	i = -1;
	now = adm->tail;
	while (i != 1)
	{
		if (now == adm->head)
			printf(CYAN"h:");
		if (now == adm->tail)
			printf(BLUE"t:");
		printf(GREEN"%d -> ", now->n);
		if (now == adm->tail)
			i++;
		now = now->prev;
	}
	printf(RED"...\n\n");
//	read(0, buf, 10);
	return ;
}
