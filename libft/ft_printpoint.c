/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpoint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:49:12 by duccello          #+#    #+#             */
/*   Updated: 2025/05/19 13:49:14 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_longlen(unsigned long n, int base)
{
	int	len;

	len = 0;
	if (n < 0)
		len = 1;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

static int	ft_printlongx(unsigned long n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n >= 16)
		ft_printlongx(n / 16);
	write(1, &base[n % 16], 1);
	count += ft_longlen(n, 16);
	return (count);
}

int	ft_printpoint(void *n)
{
	int				count;
	unsigned long	num;

	num = (unsigned long)n;
	count = 0;
	if (n == NULL)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	count += write(1, "0x", 2);
	count += ft_printlongx(num);
	return (count);
}
