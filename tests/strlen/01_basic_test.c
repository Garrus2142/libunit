/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 22:06:45 by thugo             #+#    #+#             */
/*   Updated: 2017/03/29 22:27:37 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	strlen_basic_test(void)
{
	if (ft_strlen("") != strlen(""))
		return (-1);
	if (ft_strlen("lfklwoGO") != strlen("lfklwoGO"))
		return (-1);
	if (ft_strlen("salut\0ignore") != strlen("salut\0ignore"))
		return (-1);
	return (0);
}
