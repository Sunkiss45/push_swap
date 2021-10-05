/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2021/10/05 16:46:59 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_adm	*list_init(t_dll *dll, int first)
{
	t_adm	*adm;

	adm = malloc(sizeof(*adm));
	if (adm == NULL)
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
	adm->head = new;
}

/* ===== Test Zone ===== 

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

	printf("\n--- Liste Chaine simple ---\n\n");
	while (i != 1)
	{
		printf("%d -> ", now->n);
		if (now->next == adm->head)
			i = 1;
		now = now->next;
		k++;
	}
	printf("NULL\n\n");

	printf("--- Liste Chaine double ---\n\n");
	i = 0;
	printf("NULL -> ");
	now = adm->head;
	while (i != 1)
	{
		printf("%d -> ", now->n);
		if (now->next == adm->head)
			i = 1;
		now = now->next;
	}
	printf("NULL\n");

	i = 0;
	printf("NULL -> ");
	now = adm->tail;
	while (i != 1)
	{
		printf("%d -> ", now->n);
		if (now->prev == adm->tail)
			i = 1;
		now = now->prev;
	}
	printf("NULL\n\n");

	printf("--- Liste Chaine double & circu ---\n\n");
	i = 0;
	printf("head/");
	now = adm->head;
	while (i != 3)
	{
		if (now == adm->tail)
			printf("tail/");
		printf("%d -> ", now->n);
		if (now->next == adm->head)
			i++;
		now = now->next;
		if (now == adm->head)
			printf("head/");
	}
	printf("...\n");

	i = 0;
	printf("tail/");
	now = adm->tail;
	while (i != 3)
	{
		if (now == adm->head)
			printf("head/");
		printf("%d -> ", now->n);
		if (now->prev == adm->tail)
			i++;
		now = now->prev;
		if (now == adm->tail)
			printf("tail/");
	}
	printf("...\n\n");
	return ;
}*/
