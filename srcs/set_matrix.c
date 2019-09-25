/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_matrix.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/22 14:45:23 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 22:06:48 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

int		**ft_fil_map(int **map, char **matrix, char vide)
{
	int		i;
	int		j;

	i = 1;
	while (matrix[i] != 0)
	{
		j = 0;
		while (matrix[i][j] != '\0')
		{
			if (matrix[i][j] == vide)
				map[i][j] = 1;
			else
				map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}

char	set_vide(char **matrix)
{
	int i;

	i = 0;
	while (matrix[0][i] != '\0')
		i++;
	i -= 3;
	return (matrix[0][i]);
}

int		**set(char **matrix, int row, int col)
{
	int		**map;
	int		i;
	char	vide;

	i = 0;
	vide = set_vide(matrix);
	if (!(map = (int **)malloc(sizeof(int *) * (col * row))))
		return (NULL);
	while (matrix[i] != 0)
	{
		if (!(map[i] = (int *)malloc(sizeof(int) * col * row)))
			return (NULL);
		i++;
	}
	map = ft_fil_map(map, matrix, vide);
	return (map);
}
