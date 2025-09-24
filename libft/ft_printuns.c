/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:49:12 by duccello          #+#    #+#             */
/*   Updated: 2025/05/19 13:49:14 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_printuns(unsigned int n)
{
	char	temp;
	int		count;

	count = 0;
	if (n >= 10)
		ft_printuns(n / 10);
	temp = (n % 10) + '0';
	write(1, &temp, sizeof(char));
	count += ft_intlen((unsigned int)n, 10);
	return (count);
}
