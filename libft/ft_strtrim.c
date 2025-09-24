/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:24:22 by duccello          #+#    #+#             */
/*   Updated: 2025/05/15 13:41:14 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_strchrs(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		len;
	int		i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	len = (ft_strlen(s1));
	while (ft_strchrs(set, s1[i]) && s1[i])
		i++;
	while (ft_strchrs(set, s1[len - 1]) && len > i)
		len--;
	new = (char *)malloc((len - i + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, &s1[i], len - i + 1);
	return (new);
}
