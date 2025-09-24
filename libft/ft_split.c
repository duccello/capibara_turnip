/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 13:56:03 by duccello          #+#    #+#             */
/*   Updated: 2025/05/15 13:56:06 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_count(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_buffer(const char *s, const char c, int *p)
{
	char	*buffer;
	int		start;
	int		len;

	len = 0;
	while (s[*p] == c)
		(*p)++;
	start = *p;
	while (s[*p] != c && s[*p] != '\0')
	{
		(*p)++;
		len++;
	}
	buffer = malloc((len + 1) * sizeof(char));
	ft_strlcpy(buffer, &s[start], len + 1);
	return (buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	char	*temp;
	int		count;
	int		p;
	int		n;

	temp = NULL;
	count = (ft_count(s, c));
	p = 0;
	n = 0;
	array = (char **)malloc((count + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (n < count)
	{
		temp = ft_buffer(s, c, &p);
		array[n] = temp;
		if (!array[n])
			return (NULL);
		n++;
	}
	array[n] = NULL;
	return (array);
}
