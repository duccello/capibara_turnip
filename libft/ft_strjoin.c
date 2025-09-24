/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:48:12 by duccello          #+#    #+#             */
/*   Updated: 2025/05/15 13:31:18 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)malloc(len + 1 * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, (ft_strlen(s1) + 1));
	ft_strlcat(new, s2, len);
	return (new);
}
