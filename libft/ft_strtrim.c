/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:34:05 by mlecherb          #+#    #+#             */
/*   Updated: 2022/04/24 14:10:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check5(const char c, char const *set)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

int	ft_attribute_end(char *src, char *set)
{
	int	end;

	end = ft_strlen(src) - 1;
	while (src && ft_check5(src[end], (char *)set))
		end--;
	return (end);
}

int	ft_attribute_start(char *src, char *set)
{
	int	start;

	start = 0;
	while (src && ft_check5(src[start], (char *)set))
		start++;
	return (start);
}

int	ft_ultimate_check(char *s1, char const *set)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (set[j] == s1[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*dest;
	char	*src;

	if (!s1 || !set)
		return (NULL);
	src = (char *)s1;
	i = 0;
	start = ft_attribute_start(src, (char *)set);
	end = ft_attribute_end(src, (char *)set);
	if (start > end)
		dest = malloc(sizeof(char) * 1);
	else
		dest = malloc(sizeof(char) * (end - start + 1));
	if (dest == NULL)
		return (NULL);
	while (end >= start)
		dest[i++] = src[start++];
	dest[i] = '\0';
	return (dest);
}
