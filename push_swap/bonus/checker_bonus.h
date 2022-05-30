/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:50:42 by sayar             #+#    #+#             */
/*   Updated: 2022/03/10 14:49:59 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../push_swap.h"

int		ft_strcmp(char *s1, char *s2);
void	ft_check_stack(t_stack **a, t_stack **b);
void	ft_comp_moves(char *str, t_com *begin);
void	ft_comp_moves_2(char *str, t_com *begin);

#endif