/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2021/10/11 17:31:05 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_enter(t_adm *adm, char **str, int i)
{
	long	num;

	while(str[i])
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
	int		i;
	int		k;

	if (adm == NULL)
		return ;
	now = adm->head;
	i = 0;
	k = 0;

	printf(YELLOW"\n--- Liste Chaine simple ---\n\n");
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
	printf(RED"NULL\n\n");

	printf(YELLOW"--- Liste Chaine Double & Circu ---\n\n");
	i = 0;
	printf(CYAN"head:");
	now = adm->head;
	while (i != 3)
	{
		if (now == adm->tail)
			printf(BLUE"tail:");
		printf(GREEN"%d -> ", now->n);
		if (now->next == adm->head)
			i++;
		now = now->next;
		if (now == adm->head)
			printf(CYAN"head:");
	}
	printf(RED"...\n");

	i = 0;
	printf(BLUE"tail:");
	now = adm->tail;
	while (i != 3)
	{
		if (now == adm->head)
			printf(CYAN"head:");
		printf(GREEN"%d -> ", now->n);
		if (now->prev == adm->tail)
			i++;
		now = now->prev;
		if (now == adm->tail)
			printf(BLUE"tail:");
	}
	printf(RED"...\n\n");
	return ;
}
