/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 08:55:05 by adraji            #+#    #+#             */
/*   Updated: 2025/12/15 08:37:37 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (max <= min)
		return (0);
	*range = malloc((max - min) * sizeof(int));
	if (*range == NULL)
		return (0);
	while (min < max)
	{
		range[0][i] = min;
		min++;
		i++;
	}
	return (max -= min - i);
}
