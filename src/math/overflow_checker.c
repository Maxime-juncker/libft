/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overflow_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:25:03 by mjuncker          #+#    #+#             */
/*   Updated: 2025/03/05 11:27:41 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/math.h"
#include <limits.h>

static int	call_func(int n, void (*f)(int, void *), void *param)
{
	if (f == NULL)
		return (n);
	f(n, param);
	return (n);
}

static int	get_sign(const char *s, int *i)
{
	int	sign;

	sign = 1;
	while (s[*i] == ' ' || (s[*i] >= '\t' && s[*i] <= '\r'))
		(*i)++;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

/*
 * @brief overflow_check will run like ft_atoi, however in case of an
 * @brief overflow, a f will be call with the MAX_INT (overflow) or
 * @brief MIN_INT (underflow) along with a void* param
 * @param s the string to convert
 * @param f the function to call in case an overflow or underflow happen
 * @param param the param to pass to f
 * @return the converted int, or MAX_INT / MIN_INT (overflow / underflow)
*/
int	overflow_check(const char *s, void (*f)(int, void *), void *param)
{
	int	result;
	int	sign;
	int	i;

	i = 0;
	result = 0;
	sign = get_sign(s, &i);
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (result > INT_MAX / 10)
			return (call_func(INT_MAX, f, param));
		if (result < INT_MIN / 10)
			return (call_func(INT_MIN, f, param));
		result *= 10;
		if (result > INT_MAX - (s[i] - '0'))
			return (call_func(INT_MAX, f, param));
		if (result < INT_MIN + (s[i] - '0'))
			return (call_func(INT_MIN, f, param));
		if (sign < 0)
			result -= s[i] - '0';
		else
			result += s[i] - '0';
		i++;
	}
	return (result);
}
