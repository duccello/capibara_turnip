/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:05:34 by duccello          #+#    #+#             */
/*   Updated: 2025/06/02 12:05:39 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	printright(char specifier, va_list ap);

int	ft_printf(const char *smth, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, smth);
	while (*smth)
	{
		if (*smth == '%')
			count += printright(*(++smth), args);
		else
			count += write(1, smth, 1);
		smth++;
	}
	va_end(args);
	return (count);
}

int	printright(char specifier, va_list arg)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_printchar(va_arg(arg, int));
	else if (specifier == 's')
		count += ft_printstring(va_arg(arg, char *));
	else if (specifier == 'p')
		count += ft_printpoint(va_arg(arg, void *));
	else if (specifier == 'd')
		count += ft_printnum(va_arg(arg, int));
	else if (specifier == 'i')
		count += ft_printnum(va_arg(arg, int));
	else if (specifier == 'u')
		count += ft_printuns(va_arg(arg, unsigned int));
	else if (specifier == 'x')
		count += ft_printsmallx(va_arg(arg, unsigned int));
	else if (specifier == 'X')
		count += ft_printbigx(va_arg(arg, unsigned int));
	else if (specifier == '%')
		count += write(1, "%", 1);
	return (count);
}
