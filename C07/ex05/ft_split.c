/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:20:26 by adraji            #+#    #+#             */
/*   Updated: 2025/08/04 10:20:28 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_tab
{
	int	count;
	int	*len;
}t_t;

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_wordlen(char *str, char *charset, t_t *t)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
		if (str[i] && !ft_is_charset(str[i], charset))
			t->count++;
		while (str[i] && !ft_is_charset(str[i], charset))
			i++;
	}
	return (0);
}

t_t	*ft_strlen(char *str, char *charset, t_t *t)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	while (j < t->count)
	{
		x = 0;
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
		while (str[i] && !ft_is_charset(str[i], charset))
		{
			x++;
			i++;
		}
		t->len[j] = x;
		j++;
	}
	return (t);
}

t_t	*ft_lign_nb(char *str, char *charset, t_t *t)
{
	int	i;

	i = 0;
	t->count = 0;
	while (str[i])
	{
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
		if (str[i] && !ft_is_charset(str[i], charset))
			t->count++;
		while (str[i] && !ft_is_charset(str[i], charset))
			i++;
	}
	t->len = malloc(sizeof(int) * t->count);
	if (!t->len)
		return (NULL);
	return (ft_strlen(str, charset, t));
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	t_t		t;
	char	**res;

	i = 0;
	ft_lign_nb(str, charset, &t);
	res = malloc((t.count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (i < t.count)
	{
		j = 0;
		res[i] = malloc((t.len[i] + 1) * sizeof(char));
		if (!res[i])
			return (NULL);
		while (*str && ft_is_charset(*str, charset))
			str++;
		while (*str && !ft_is_charset(*str, charset))
			res[i][j++] = *(str++);
		res[i][j] = '\0';
		i++;
	}
	res[i] = NULL;
	return (res);
}
