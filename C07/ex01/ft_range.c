/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:08:00 by adraji            #+#    #+#             */
/*   Updated: 2025/12/15 08:37:24 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int mini, int max)
{
	int	*array;
	int	i;

	if (max <= mini)
		return (NULL);
	array = malloc((max - mini) * sizeof(int));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (mini < max)
	{
		array[i] = mini;
		mini++;
		i++;
	}
	return (array);
}
