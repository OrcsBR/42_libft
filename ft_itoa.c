/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peduardo < peduardo@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:39:56 by peduardo          #+#    #+#             */
/*   Updated: 2021/08/13 01:41:34 by peduardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_decimals(int n)
{
	int	decpos;

	decpos = 0;
	while ((n / 10) >= 10)
	{
		decpos++;
		n = n / 10;
	}
	return (decpos);
}

static int	find_isneg(int n)
{
	if (n >= 0)
		return (0);
	else
		return (1);
}

char	*ft_itoa(int n)
{
	int		decplaces;
	int		bufsize;
	int		i;
	int		isneg;
	char	*ascii;

	decplaces = find_decimals(n);
	isneg = find_isneg(n);
	bufsize = decplaces + isneg + 2;
	ascii = (char *) malloc(bufsize * sizeof(char));
	if (!ascii)
		return (NULL);
	if (isneg > 0)
		ascii[0] = '-';
	i = bufsize - 1;
	ascii[i] = '\0';
	i--;
	while (n > 9)
	{
		ascii[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	ascii[i] = n + 48;
	return (ascii);
}
