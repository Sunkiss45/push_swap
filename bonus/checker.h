/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 16:53:02 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/22 11:28:04 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

# define BUFFER_SIZE 1024

typedef struct s_dll
{
	int				n;
	struct s_dll	*next;
	struct s_dll	*prev;
}	t_dll;

typedef struct s_adm
{
	int				base;
	struct s_dll	*head;
	struct s_dll	*tail;
}	t_adm;

t_adm	*list_init_a(t_adm *adm, t_dll *dll, int first);
t_adm	*list_init_b(t_adm *adm);
int		list_enter(t_adm *adm, char **str, int i);
int		list_inser(t_adm *adm, int add);

void	list_display(t_adm *adma, t_adm *b);

int		instru(char *s, t_adm *adma, t_adm *admb);

int		count_nb(t_adm *adm);

int		ft_s(t_adm *adm, char *s);
int		ft_r(t_adm *adm, char *s);
int		ft_rr(t_adm *adm, char *s);
int		ft_ds(t_adm *adma, t_adm *admb, char *s);
int		ft_dr(t_adm *adma, t_adm *admb, char *s);
int		ft_drr(t_adm *adma, t_adm *admb, char *s);
int		ft_p(t_adm *admfrom, t_adm *admto, char *s);

void	free_split(char **str);
int		free_strjoin(char *s, int x);
int		list_delete(t_adm *adm, int x);
int		free_all(t_adm **adm, char **str, char *line, int x);

int		ft_check_before(char **str);
int		ft_check(char *s);
int		ft_doub(t_adm *adm);
int		ft_sor(t_adm *adm);

char	*ft_strjoin(int size, char **strs, char *sep);
char	**ft_split(char *str, char *charset);
long	ft_atoi(char *s);
int		ft_strlen(char *s);

int		get_next_line(int fd, char **line);
int		ft_check_n(char *str);
char	*ft_saver(char *str);
char	*ft_strcut_gnl(char *str);
int		ft_strlen(char *s);
int		ft_strn(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif
