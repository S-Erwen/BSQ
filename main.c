/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nepage-l <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/23 22:48:03 by nepage-l     #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 21:24:09 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft.h"

void	suite_main(char *map, int i, int argc)
{
	int		col;
	int		row;
	char	**matrix;
	int		**matrixint;
	int		result;

	matrix = ft_split_backline(map);
	matrixint = set(matrix, give_row(matrix), give_col(matrix));
	result = solve(matrixint, give_col(matrix), give_row(matrix));
	col = get_col(matrixint, result, give_col(matrix), give_row(matrix));
	row = get_row(matrixint, result, give_col(matrix), give_row(matrix));
	res_in_tab(col, row, result, matrix);
	free(matrixint);
	free(matrix);
	if (argc != i + 1)
		write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	char	*map;
	int		i;

	i = 0;
	if (argc == 1)
	{
		map = ft_file_to_str(NULL, 0);
		if (ft_check_map(map) == -1)
			write(2, "map error\n", 10);
		else
			suite_main(map, i, argc);
	}
	else
	{
		while (++i < argc)
		{
			map = ft_file_to_str(argv[i], -1);
			if (ft_check_map(map) == -1)
				write(2, "map error\n", 10);
			else
				suite_main(map, i, argc);
		}
	}
	return (0);
}
