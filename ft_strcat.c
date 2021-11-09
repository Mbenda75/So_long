/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benmoham <benmoham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:34:18 by benmoham          #+#    #+#             */
/*   Updated: 2021/11/09 20:55:47 by benmoham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "so_long.h"

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;
	char			*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(src) + 2));
	if (!tmp)
		return (NULL);
	while (dest[i] != '\0')
	{
		tmp[i] = dest[i];
		i++;
	}
	j = 0;
	tmp[i] = '|';
	i++;
	while (src[j] != '\0')
	{
		tmp[i] = src[j];
		i++;
		j++;
	}
	free(dest);
	tmp[i] = '\0';
	return (tmp);
}
