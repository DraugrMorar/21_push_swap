/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:41:52 by dmorar            #+#    #+#             */
/*   Updated: 2019/04/16 16:54:16 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"
# define WID 1300

typedef struct	s_mv
{
	int			a;
	int			b;
	int			wa;
	int			wb;
	int			res;
}				t_mv;
typedef struct	s_swap
{
	int			*ara;
	int			*arb;
	int			lenar;
	int			lenb;
	int			len;
	int			maxa;
	int			mina;
	int			midara;
	int			midarb;
	t_mv		*mv;
}				t_swap;
typedef struct	s_check
{
	int			*ara;
	int			*arb;
	char		**com;
	int			lenar;
	int			lenb;
	int			len;
	int			lencom;
	int			v;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
	int			bpp;
	int			line_size;
	int			endian;
	int			max;
	int			y;
}				t_check;
void			count_move2(t_swap *fo, int i);
void			only_maxa_and_mina(t_swap *fo);
void			find_maxa_and_mina(t_swap *fo);
void			maxa_mina_ordering(t_swap *fo);
int				checkorder(int *tab, int len);
void			top_two_el(int *ar);
void			minus_one_pos(int *a, int len);
void			plus_one_pos(int *a, int len);
void			movedown(int *str, int len);
void			swap_el(t_swap *fo, int arr);
void			checkarr(int *ar, int len);
int				*fillarr(int ac, char **str);
void			checknum(int ac, char **str);
void			count_move(t_swap *fo, int i);
void			checker(t_check *fo);
void			make_min_moves(t_swap *fo);
void			ordermin(t_swap *fo, t_mv *mv, int i, int value);
void			ordermin2(t_swap *fo, int value, int i);
void			ordermin3(t_swap *fo, int value, int i);
void			ordermin4(t_swap *fo, int value, int i);
void			ordermin5(t_swap *fo, int i);
void			newdata(t_swap *fo);
void			makecomands(t_check *fo);
void			makecomands2(t_check *fo, int i);
void			checkcomands(t_check *fo, char *str);
void			validcomands(char **com, int len);
void			swap_el_check(t_check *fo, int arr);
void			visualit(t_check *fo);
void			justdraw(t_check *fo, char *str);
int				closemap(void *fo);
int				key_release(int key, t_check *fo);
void			make_vis_comands(t_check *fo);
char			**fill_str(char **str, int *len);
#endif
