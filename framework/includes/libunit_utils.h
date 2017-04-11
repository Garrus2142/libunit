/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thugo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:17:10 by thugo             #+#    #+#             */
/*   Updated: 2017/04/11 19:29:19 by thugo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_UTILS_H
# define LIBUNIT_UTILS_H

int		utils_getline(const int fd, char **line);
void	utils_purgefd(const int fd);

#endif
