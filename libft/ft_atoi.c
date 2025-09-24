/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:17:55 by duccello          #+#    #+#             */
/*   Updated: 2025/05/15 13:27:07 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *p)
{
	int	charge;
	int	num;
	int	temp;

	charge = 1;
	num = 0;
	temp = 0;
	while (*p == ' ' || (*p >= '\t' && *p <= '\r'))
		p++;
	if (*p == '+' || *p == '-')
	{
		if (*p == '-')
			charge = charge * -1;
		p++;
	}
	while (*p >= '0' && *p <= '9')
	{
		temp = (*p - '0');
		num = temp + (num * 10);
		p++;
	}
	return (num * charge);
}
