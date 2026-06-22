/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:06:26 by adraji            #+#    #+#             */
/*   Updated: 2025/12/15 08:38:22 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_full_size(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	size_strs;
	int	size_sep;
	int	full_size;

	j = 0;
	size_strs = 0;
	size_sep = 0;
	full_size = 0;
	while (j < size)
	{
		i = 0;
		while (strs[j][i])
			i++;
		size_strs += i;
		j++;
	}
	while (sep[size_sep])
		size_sep++;
	full_size = size_strs + (size_sep * (size - 1));
	return (full_size);
}

int	ft_copy_str(char *dest, char *src, int r)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[r] = src[i];
		i++;
		r++;
	}
	return (r);
}

char	*ft_fill_in(int size, char **strs, char *sep, char *result)
{
	int	j;
	int	r;

	j = 0;
	r = 0;
	while (j < size)
	{
		r = ft_copy_str(result, strs[j], r);
		if (j < size - 1)
			r = ft_copy_str(result, sep, r);
		j++;
	}
	result[r] = '\0';
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char		*result;

	if (size == 0)
	{
		result = malloc(1);
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	result = malloc((ft_full_size(size, strs, sep) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result = ft_fill_in(size, strs, sep, result);
	return (result);
}
