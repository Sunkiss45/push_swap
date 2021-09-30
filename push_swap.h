/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:53:02 by ebarguil          #+#    #+#             */
/*   Updated: 2021/09/30 11:29:09 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_dll
{
	int				n;
	struct s_dll	*next;
	struct s_dll	*prev;
}	t_dll;

typedef struct s_head
{
	struct s_dll	*head;
}	t_head;

t_head	*list_init(t_dll *dll, int first);
void	list_inser(t_head *head, int add);
void	list_display(t_head *head);

#endif
