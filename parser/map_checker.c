/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <lpeeters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:41:12 by lpeeters          #+#    #+#             */
/*   Updated: 2024/03/27 15:04:00 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// Map file name validation
int	map_extension_checker(char *file_name)
{
	char	*file_type;

	file_type = ft_strchr(file_name, '.');
	if (!file_type || ft_strcmp(file_type, ".cub"))
		return (0);
	return (1);
}

// Master map handler
int	map_handler(char *file_name)
{
	if (!file_name)
		return (prnt_err("Error: file"), 0);
	if (!map_extension_checker(file_name))
		return (prnt_err("Error: invalid file type"), 0);
	return (1);
}
