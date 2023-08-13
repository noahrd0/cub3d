/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:17:20 by nradal            #+#    #+#             */
/*   Updated: 2023/08/02 11:27:29 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtok(char **str, char delim)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = NULL;
	while (**str != '\0')
	{
		if (i == 0 && **str != delim)
		{
			i = 1;
			ptr = *str;
		}
		else if (i == 1 && **str == delim)
		{
			**str = '\0';
			(*str)++;
			break ;
		}
		(*str)++;
	}
	return (ptr);
}
