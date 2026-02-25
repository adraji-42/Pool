/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 22:12:15 by adraji            #+#    #+#             */
/*   Updated: 2025/07/30 13:48:22 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || (base[i] > 8 && base[i] < 14))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_skip_spaces_and_signs(char *str, int *sign)
{
	int	i;

	i = 0;
	*sign = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			(*sign)++;
		i++;
	}
	return (i);
}

int	ft_convert_number(char *str, char *base, int i, int base_len)
{
	int	num;
	int	j;

	num = 0;
	while (str[i])
	{
		j = 0;
		while (base[j] && str[i] != base[j])
			j++;
		if (!base[j])
			break ;
		num = num * base_len + j;
		i++;
	}
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	num;
	int	base_len;

	if (!is_valid_base(base))
		return (0);
	base_len = ft_strlen(base);
	i = ft_skip_spaces_and_signs(str, &sign);
	num = ft_convert_number(str, base, i, base_len);
	if (sign % 2)
		num = -num;
	return (num);
}
