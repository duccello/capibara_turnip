/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:28:54 by duccello          #+#    #+#             */
/*   Updated: 2025/06/02 14:28:57 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_printnum(int n)
{
	char	temp;
	int		count;

	count = 0;
	if (n == -2147483648)
		count += write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", sizeof(char));
			n = n * -1;
			count += 1;
		}
		count += ft_intlen((unsigned int)n, 10);
		if (n >= 10)
			ft_printnum((n / 10));
		temp = (n % 10) + '0';
		write(1, &temp, sizeof(char));
	}
	return (count);
}
