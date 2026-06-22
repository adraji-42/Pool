/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 20:24:55 by adraji            #+#    #+#             */
/*   Updated: 2025/12/15 08:40:14 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strsize(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int			src_size;
	char		*dup;

	src_size = ft_strsize(src) + 1;
	dup = malloc(src_size * sizeof (char));
	if (dup == NULL)
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}

struct s_stock_str	*ft_fill_2d(int ac, char **av, struct s_stock_str *string)
{
	int	i;
	int	str_size;

	i = 0;
	while (i < ac)
	{
		str_size = ft_strsize(av[i]);
		string[i].str = ft_strdup(av[i]);
		if (string[i].str == NULL)
		{
			free(string[i].str);
			return (NULL);
		}
		string[i].copy = ft_strdup(av[i]);
		if (string[i].copy == NULL)
		{
			free(string[i].copy);
			return (NULL);
		}
		string[i].size = str_size;
		i++;
	}
	return (string);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*string;

	string = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (string == NULL)
		return (NULL);
	string = ft_fill_2d(ac, av, string);
	string[ac].str = 0;
	return (string);
}
