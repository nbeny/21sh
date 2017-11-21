#include "21sh.h"

void	ft_tabulation(t_term *term)
{
	int	pull;
	int	i;

	i = 0;
	pull = 0;
	while (i != 3)
	{
		ft_update_window(term);
		ft_edit_line(term);
		ft_update_window(term);
		if (term->x == term->ws_x && term->pos != term->mlen)
			pull = 1;
		ft_putchar(' ');
		if (pull == 1)
		{
			tputs(tgetstr("do", NULL), 1, ft_putchar);
			pull = 0;
		}
		if (term->pos != term->mlen)
			ft_insert_char(term, ' ');
		else
			ft_strjoin_v2(term, ' ');
		term->pos++;
		term->mlen++;
		i++;
	}
}
