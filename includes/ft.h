/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fatilly <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/07/23 14:07:36 by fatilly      #+#   ##    ##    #+#       */
/*   Updated: 2019/07/24 19:33:29 by fatilly     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUF_SIZE 1

int			give_row(char **matrix);
int			give_col(char **matrix);
int			min(int a, int b, int c);
int			solve(int **map, int row, int col);
int			get_col(int **map, int result, int row, int col);
int			get_row(int **map, int result, int row, int col);
char		*ft_read_map(int fd, long long size);
void		ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_strlen(char *str);
void		ft_putnbr(int nb);
int			is_in_backline(char c);
int			count(char *str);
void		write_res(char *res, char *str);
void		malloc_res(char **res, char *str);
char		**ft_split_backline(char *str);
void		res_in_tab(int col, int row, int result, char **map);
void		imprim_res(char **map);
int			ft_check_line_length(char *map);
int			ft_atoi_param(char *str);
int			ft_check_map_symbols(char *buff);
char		*ft_file_to_str(char *file, int fd);
long long	ft_get_file_size(int fd);
int			ft_check_map(char *map);
int			**set(char **matrix, int row, int col);
void		ft_strcpy(char *src, char *dest);
void		ft_strcpy_double(char *src_start, char *src_end, char *dest);

#endif
