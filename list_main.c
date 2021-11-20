/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:49:08 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/20 18:38:19 by ebarguil         ###   ########.fr       */
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
		return (NULL);
	adm->head = dll;
	adm->tail = dll;
	dll->n = first;
	dll->i = 0;
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
	new->i = 0;
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
	char	buf[1024];
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
	read(0, buf, 4);
	i = 0;
	if (buf[0] == 's')
	{
		if (buf[1] == 't')
		{
			if (buf[2] == 'o')
				if (buf[3] == 'p')
					return ;
		}
		else if (buf[1] == 'a')
			ft_s(adma, "sa\n");
		else if (buf[1] == 'b')
			ft_s(admb, "sb\n");
	}
	else if (buf[0] == 'r')
	{
		if (buf[1] == 'a')
			ft_r(adma, "ra\n");
		else if (buf[1] == 'b')
			ft_r(admb, "rb\n");
		else if (buf[1] == 'r')
		{
			if (buf[2] == 'a')
				ft_rr(adma, "rra\n");
			else if (buf[2] == 'b')
				ft_rr(admb, "rrb\n");
		}
	}
	else if (buf[0] == 'p')
	{
		if (buf[1] == 'a')
			ft_p(admb, adma, "pa\n");
		else if (buf[1] == 'b')
			ft_p(adma, admb, "pb\n");
	}
	list_display(adma, admb);
	return ;
}*/
