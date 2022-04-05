/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjasari <rjasari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:59:40 by tkruger           #+#    #+#             */
/*   Updated: 2022/03/30 12:10:09 by rjasari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// for va_list
#include <stdarg.h>
// for INT32_MAX
#include <stdint.h>

int	ft_min(int count, ...)
{
	va_list	numbers;
	int		tmp;
	int		smallest;

	smallest = INT32_MAX;
	va_start(numbers, count);
	while (count-- > 0)
	{
		tmp = va_arg(numbers, int);
		if (smallest > tmp)
			smallest = tmp;
	}
	va_end(numbers);
	return (smallest);
}
