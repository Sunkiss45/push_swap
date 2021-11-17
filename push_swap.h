/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:53:02 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/17 15:09:00 by ebarguil         ###   ########.fr       */
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
	int				i;
	int				c;
	int				r;
	struct s_dll	*next;
	struct s_dll	*prev;
}	t_dll;

typedef struct s_adm
{
	struct s_dll	*head;
	struct s_dll	*tail;
}	t_adm;

t_adm	*list_init_a(t_adm *adm, t_dll *dll, int first);
t_adm	*list_init_b(t_adm *adm);
int		list_enter(t_adm *adm, char **str, int i);
void	list_inser(t_adm *adm, int add);
int		list_delete(t_adm *adm, int x);
void	list_display(t_adm *adma, t_adm *b);

void	algo_main(t_adm *adma, t_adm *admb);
void	ft_index(t_adm *adm);
int		is_rot(t_adm *adm);
int		is_sorr(t_adm *adma, t_adm *admb);
int		pre_algo(t_adm *adma, t_adm *admb, char **str);

int		count_nb(t_adm *adm);
void	algo_3(t_adm *adm);
void	algo_4(t_adm *adma, t_adm *admb);
void	algo_5(t_adm *adma, t_adm *admb);
void	mort(t_adm *adma, t_adm *admb);

void	ft_s(t_adm *adm, char *s);
void	ft_r(t_adm *adm, char *s);
void	ft_rr(t_adm *adm, char *s);
void	ft_p(t_adm *admfrom, t_adm *admto, char *s);

void	free_split(char **str);
int		free_all(t_adm *adma, t_adm *admb, char **str, int x);

int		ft_check_one(char *s, int x);
int		ft_check_more(char **s);
int		ft_doub(t_adm *adm);
int		ft_sor(t_adm *adm);
int		ft_sorr(t_adm *adm);

char	**ft_split(char *str, char *charset);
long	ft_atoi(char *s);
int		ft_strlen(char *s);

#endif
