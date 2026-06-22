/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 18:36:01 by adraji            #+#    #+#             */
/*   Updated: 2025/12/15 08:41:19 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_line(int i, int x)
{
	ft_putchar('/');
	i++;
	while (i < x)
	{
		ft_putchar('*');
		i++;
	}
	if (i == x)
		ft_putchar('\\');
	ft_putchar('\n');
}

void	last_line(int i, int x)
{
	ft_putchar('\\');
	i++;
	while (i < x)
	{
		ft_putchar('*');
		i++;
	}
	if (i == x)
		ft_putchar('/');
	ft_putchar('\n');
}

void	mid_line(int i, int x)
{
	ft_putchar('*');
	i++;
	while (i < x)
	{
		ft_putchar(' ');
		i++;
	}
	if (i < x)
		ft_putchar('*');
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	j = 1;
	if (x > 0 && y > 0)
	{
		while (j <= y)
		{
			i = 1;
			if (j == 1)
				first_line(i, x);
			else if (j == y)
				last_line(i, x);
			else
				mid_line(i, x);
			j++;
		}
	}
	return ;
}
