/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_null_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 22:14:25 by thugo             #+#    #+#             */
/*   Updated: 2017/03/29 22:27:48 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		strlen_null_test(void)
{
	if (ft_strlen(NULL) != ft_strlen(NULL))
		return (-1);
	return (0);
}
