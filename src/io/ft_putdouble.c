/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:12:32 by mjuncker          #+#    #+#             */
/*   Updated: 2025/09/08 14:19:11 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ft_putdouble(double d)
{
	float	decimal = (int)d;
	float	fractorial = d - decimal;
	
	printf("%.3f %.3f\n", decimal, fractorial);

	return 1;
}
