/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:16:11 by mjuncker          #+#    #+#             */
/*   Updated: 2025/03/05 11:40:18 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# include <stdlib.h>

int		overflow_check(const char *s, void (*f)(int, void *), void *param);

int		ft_abs(int n);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

#endif