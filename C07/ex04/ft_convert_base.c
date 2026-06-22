/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 11:02:19 by adraji            #+#    #+#             */
/*   Updated: 2025/07/30 11:02:21 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	is_valid_base(char *base);
int	ft_atoi_base(char *str, char *base);
int	ft_strlen(char *str);

int	get_nbr_len(long nb, int base_len)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		nb /= base_len;
		len++;
	}
	return (len);
}

char	*ft_rev_str(char *str, int size)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return (str);
}

char	*ft_itoa_base(int nbr, char *base)
{
	long		n;
	int			i;
	int			base_len;
	int			sign;
	char		*num;

	n = nbr;
	i = 0;
	base_len = ft_strlen(base);
	sign = (nbr < 0);
	num = malloc((get_nbr_len(nbr, base_len) + sign + 1) * sizeof(char));
	if (sign)
		n = -n;
	while (n > 0)
	{
		num[i++] = base[n % base_len];
		n /= base_len;
	}
	if (sign)
		num[i++] = '-';
	num[i] = '\0';
	return (ft_rev_str(num, i));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		decimal;
	char	*zero;

	if (!is_valid_base(base_from) || !is_valid_base(base_to))
		return (NULL);
	decimal = ft_atoi_base(nbr, base_from);
	if (!decimal)
	{
		zero = malloc(2 * sizeof(char));
		if (zero == NULL)
			return (NULL);
		zero[0] = base_to[0];
		zero[1] = '\0';
		return (zero);
	}
	return (ft_itoa_base(decimal, base_to));
}
