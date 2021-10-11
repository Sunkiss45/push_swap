/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:53:02 by ebarguil          #+#    #+#             */
/*   Updated: 2021/10/11 16:48:53 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"

typedef struct s_dll
{
	int				n;
	struct s_dll	*next;
	struct s_dll	*prev;
}	t_dll;

typedef struct s_adm
{
	struct s_dll	*head;
	struct s_dll	*tail;
}	t_adm;

t_adm	*list_init(t_adm *adm, t_dll *dll, int first);
int		list_enter(t_adm *adm, char **str);
void	list_inser(t_adm *head, int add);
void	list_delete(t_adm *adm);
void	list_display(t_adm *head);

void	free_split(char **str);
int		free_all(t_adm *adm, char **str, int x);
int		free_error(t_adm *adm, char **str, int x);

int		ft_check(char *s, int x);
int		ft_doub(t_adm *adm);
int		ft_sor(t_adm *adm);
int		ft_sor_rev(t_adm *adm);

char	**ft_split(char *str, char *charset);
long	ft_atoi(char *s);

#endif
