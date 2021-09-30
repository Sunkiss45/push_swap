/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2021/09/30 11:35:35 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_head	*list_init(t_dll *dll, int first)
{
	t_head	*head;

	head = malloc(sizeof(*head));
	if (head == NULL)
		 return (0);
	dll->n = first;
	dll->next = NULL;
	dll->prev = NULL;
	head->head = dll;
	return (head);
}

void	list_inser(t_head *head, int add)
{
	t_dll	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return ;
	new->n = add;
	new->next = head->head;
	new->prev = NULL;
	head->head->prev = new;
	head->head = new;
}

/* ===== Test Zone ===== */

void	list_display(t_head *head)
{
	t_dll	*last;
	t_dll	*save;
	t_dll	*now;

	if (head == NULL)
		return ;
	now = head->head;
	save = head->head;

	printf("\n--- Liste Chaine simple ---\n\n");
	while (now != NULL)
	{
		printf("%d -> ", now->n);
		now = now->next;
	}
	printf("NULL\n\n");

	printf("--- Liste Chaine double ---\n\n");
	printf("NULL -> ");
	now = save;
	while (now != NULL)
	{
		printf("%d -> ", now->n);
		last = now;
		now = now->next;
	}
	printf("NULL\n");

	printf("NULL -> ");
	while (last != NULL)
	{
		printf("%d -> ", last->n);
		last = last->prev;
	}
	printf("NULL\n\n");

	return ;
}
