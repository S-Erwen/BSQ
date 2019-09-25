/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_map.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/23 15:17:09 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 17:15:28 by nepage-l    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

char	char_plein(char **map)
{
	int i;

	i = 0;
	while (map[0][i] != '\0')
		i++;
	i -= 1;
	return (map[0][i]);
}

void	res_in_tab(int col, int row, int result, char **map)
{
	int		i;
	int		j;
	int		temp;
	char	c;

	c = char_plein(map);
	i = 1;
	temp = row;
	while (i <= result)
	{
		row = temp;
		j = 0;
		while (j < result)
		{
			map[row][col] = c;
			row--;
			j++;
		}
		col--;
		i++;
	}
	imprim_res(map);
}

void	imprim_res(char **map)
{
	int i;
	int j;

	i = 1;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
