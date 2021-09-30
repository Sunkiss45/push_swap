/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:44:31 by ebarguil          #+#    #+#             */
/*   Updated: 2021/09/30 11:29:10 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_dll	*dll;
	t_head	*head;

	if (ac !=1)
	{
		printf("Erreur\n");
		return (0);
	}

	dll = malloc(sizeof(*dll));
	if (dll == NULL)
		return (0);

	head = list_init(dll, 20);
	list_inser(head, 15);
	list_inser(head, 10);
	list_inser(head, 5);

	list_display(head);

	return (0);
}
