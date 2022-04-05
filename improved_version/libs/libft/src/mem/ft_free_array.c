/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjasari <rjasari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:56:01 by tkruger           #+#    #+#             */
/*   Updated: 2022/03/30 13:25:46 by rjasari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
// for size_t
#include <stddef.h>

void	ft_free_array(char ***arr)
{
	char	**parser;
	size_t	i;

	parser = *arr;
	i = 0;
	while (arr != NULL && parser != NULL && parser[i] != NULL)
	{
		ft_free((void **)&parser[i++]);
	}
	ft_free((void **)arr);
}
