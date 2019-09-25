/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_map.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/23 22:58:56 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 21:19:05 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

int			ft_atoi_param(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i + 3] != '\n')
	{
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	return (result);
}

int			ft_check_line_length(char *map)
{
	int i;
	int size;
	int size_temp;

	size = 0;
	i = 0;
	while (map[i] != '\n')
		i++;
	i++;
	while (map[i++] != '\n')
		size++;
	while (map[i] != '\0')
	{
		size_temp = 0;
		while (map[i] != '\n')
		{
			size_temp++;
			i++;
		}
		if (size_temp != size)
			return (-1);
		i++;
	}
	return (0);
}

int			ft_check_map_symbols(char *buff)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	if (!(str = malloc(sizeof(char) * 4)))
		return (-1);
	while (buff[len] >= '0' && buff[len] <= '9' && buff[len + 3] != '\n')
		len++;
	i = 0;
	while (i < 3)
	{
		if (buff[len] == '\0')
			return (-1);
		str[i++] = buff[len++];
	}
	str[i] = '\0';
	len++;
	while (buff[len] != '\0')
	{
		if (buff[len] != '\n' && buff[len] != str[0] && buff[len] != str[1])
			return (-1);
		len++;
	}
	return (1);
}

int			ft_check_map(char *map)
{
	int i;
	int nb_lines;

	i = 0;
	nb_lines = -1;
	while (map[i] != '\n')
	{
		if (map[i++] == '\0' || map[i + 1] == '\0')
			return (-1);
	}
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
		{
			nb_lines++;
			if (map[i - 1] == '\n')
				return (-1);
		}
		i++;
	}
	if (nb_lines != ft_atoi_param(map) || ft_check_map_symbols(map) == -1 ||
			ft_check_line_length(map) == -1 || ft_atoi_param(map) == 0)
		return (-1);
	return (1);
}
