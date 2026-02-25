/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adraji <adraji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:20:26 by adraji            #+#    #+#             */
/*   Updated: 2025/12/15 08:34:29 by adraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	j = --argc;
	while (j > 0)
	{
		i = 0;
		while (argv[j][i])
			ft_putchar(argv[j][i++]);
		ft_putchar('\n');
		j--;
	}
}
