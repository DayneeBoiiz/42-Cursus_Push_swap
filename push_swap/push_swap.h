/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:09:10 by sayar             #+#    #+#             */
/*   Updated: 2022/03/10 14:50:44 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./bonus/get_next_line_bonus.h"
# include <stdio.h>
# include "libft/libft.h"
# include <errno.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}		t_stack;

typedef struct s_com
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*insta;
}		t_com;

t_stack	*ft_swap_stack(t_stack **begin);
t_stack	*ft_reverse_rotate(t_stack **begin);
t_stack	*ft_rotate_stack(t_stack **begin);
void	ft_rr(t_stack **stack);
void	ft_sort_three(t_com *begin);
void	ft_sort_two(t_com *begin);
void	ft_inst(t_stack **inst, int i);
t_stack	*ft_new_stack(int n);
t_stack	*ft_build_stack(int ac, char **av);
t_stack	*ft_build_stack_one(char *av);
int		ft_count(char *av);
int		ft_get_len(t_stack	**begin);
int		ft_is_sort(t_stack **begin, int stack);
int		ft_algo(t_com *begin);
void	ft_print_insta(t_com *begin);
void	ft_lstdel1(t_stack	**begin);
void	ft_putstr(char *str);
void	ft_sort_min(t_com *begin);
void	ft_algo_a(t_com *begin, int n);
void	ft_sort_tab(int *tab, int len);
int		ft_median(t_stack **begin, int stack, int n);
int		ft_compare_med(t_com *begin, int n, int median, int stack);
t_stack	*ft_push_stack(t_stack **b, t_stack **a);
void	ft_sort_min_b(t_com *begin);
void	ft_algo_b(t_com *begin, int n);
int		atoi_check(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);
void	ft_bzero(void	*s, size_t	n);
size_t	ft_strlcpy(char *dest, const char *src, size_t len);
void	str_check(char *str);
char	**ft_split(char const *s, char c);
t_stack	*parse_argv(int argc, char **argv);

#endif