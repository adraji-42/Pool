/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:39:19 by adraji            #+#    #+#             */
/*   Updated: 2025/12/15 08:21:55 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *big, int *smoll)
{
	int	swaper;

	swaper = *big;
	*big = *smoll;
	*smoll = swaper;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}
