/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/25 13:26:17 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	list_enter(t_adm *adm, char **str, int i)
{
	long	num;

	while (str[i])
	{
		num = ft_atoi(str[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (1);
		if (list_inser(adm, num))
			return (1);
		i++;
	}
	return (0);
}

t_adm	*list_init_b(t_adm *adm)
{
	adm = malloc(sizeof(*adm));
	if (adm == NULL)
		return (NULL);
	adm->head = NULL;
	adm->tail = NULL;
	return (adm);
}

t_adm	*list_init_a(t_adm *adm, t_dll *dll, int first)
{
	adm = malloc(sizeof(*adm));
	dll = malloc(sizeof(*dll));
	if (adm == NULL || dll == NULL)
	{
		if (dll != NULL)
			free(dll);
		if (adm != NULL)
			free(adm);
		return (NULL);
	}
	adm->head = dll;
	adm->tail = dll;
	dll->n = first;
	dll->next = adm->head;
	dll->prev = adm->tail;
	return (adm);
}

int	list_inser(t_adm *adm, int add)
{
	t_dll	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (1);
	new->n = add;
	new->next = adm->head;
	new->prev = adm->tail;
	adm->head->prev = new;
	adm->tail->next = new;
	adm->tail = new;
	return (0);
}

/* ===== Test Zone =====

void	list_display(t_adm *adma, t_adm *admb)
{
	t_dll	*now;
	int		i;

	if (adma == NULL)
		return ;

	printf(YELLOW"\n--- Stack A ---\n");
	i = -1;
	now = adma->head;
	if (now)
	{
		while (i != 1)
		{
			if (now == adma->tail)
				printf(BLUE"t:");
			if (now == adma->head)
				printf(CYAN"h:");
			printf(GREEN"%d -> ", now->n);
			if (now == adma->head)
				i++;
			now = now->next;
		}
		printf(RED"...\n");
	}
	else
		printf(RED"NULL\n");
	i = -1;
	now = adma->tail;
	if (now)
	{
		while (i != 1)
		{
			if (now == adma->head)
				printf(CYAN"h:");
			if (now == adma->tail)
				printf(BLUE"t:");
			printf(GREEN"%d -> ", now->n);
			if (now == adma->tail)
				i++;
			now = now->prev;
		}
		printf(RED"...\n\n");
	}
	else
		printf(RED"NULL\n\n");

	printf(YELLOW"--- Stack B ---\n");
	i = -1;
	now = admb->head;
	if (now)
	{
		while (i != 1)
		{
			if (now == admb->tail)
				printf(BLUE"t:");
			if (now == admb->head)
				printf(CYAN"h:");
			printf(GREEN"%d -> ", now->n);
			if (now == admb->head)
				i++;
			now = now->next;
		}
		printf(RED"...\n");
	}
	else
		printf(RED"NULL\n");
	i = -1;
	now = admb->tail;
	if (now)
	{
		while (i != 1)
		{
			if (now == admb->head)
				printf(CYAN"h:");
			if (now == admb->tail)
				printf(BLUE"t:");
			printf(GREEN"%d -> ", now->n);
			if (now == admb->tail)
				i++;
			now = now->prev;
		}
		printf(RED"...\n");
	}
	else
		printf(RED"NULL\n");

	printf(PURPLE"\n");
	return ;
}*/
