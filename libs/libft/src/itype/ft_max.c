/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjasari <rjasari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 20:11:55 by tkruger           #+#    #+#             */
/*   Updated: 2022/03/30 12:09:51 by rjasari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// for va_list
#include <stdarg.h>
// for INT32_MAX
#include <stdint.h>

int	ft_max(int count, ...)
{
	va_list	numbers;
	int		tmp;
	int		largest;

	largest = INT32_MIN;
	va_start(numbers, count);
	while (count-- > 0)
	{
		tmp = va_arg(numbers, int);
		if (largest < tmp)
			largest = tmp;
	}
	va_end(numbers);
	return (largest);
}
