#include "21sh.h"
/*
  t_term	*ft_write_and_position(t_term *term, char buff[6])
  {
  term->x += 1;
  if (term->x == term->ws_x)
  {
  term->x = 0;
  term->pos_y -= 1;
  }
  return (term);
  }
*/

void	ft_left_arrow(t_term *term)
{
	ft_update_window(term);
//	ft_printf(0, "[%i][%i]", term->x, term->y);
	if (term->pos > 0)
	{
		if (term->x == 1)
		{
			tputs(tgetstr("up", NULL), 1, ft_putchar);
			tputs(tgoto(tgetstr("ch", NULL), 0, term->ws_x - 1), 1, ft_putchar);
		}
		else
		{
			if (term->line[term->pos - 1] == '\t')
				tputs(tgetstr("bt", NULL), 1, ft_putchar);
			else
				tputs(tgetstr("le", NULL), 1, ft_putchar);
		}
		term->pos--;
	}
}

void	ft_right_arrow(t_term *term)
{
	ft_update_window(term);
	if (term->pos < term->mlen)
	{
		if (term->x == term->ws_x)
			tputs(tgetstr("do", NULL), 1, ft_putchar);
		else
		{
			if (term->line[term->pos] == '\t')
				tputs(tgetstr("ta", NULL), 1, ft_putchar);
			else
				tputs(tgetstr("nd", NULL), 1, ft_putchar);
		}
		term->pos++;
	}
}

void	ft_delete(t_term *term)
{
	int		i;
	int		c;
	int		add;
	int		end;
	int		count;

	tputs(tgetstr("ei", NULL), 1, ft_putchar);
	count = 0;
	ft_update_window(term);
	if (term->pos > 0)
	{
		if (term->pos == term->mlen)
		{
			if (term->x == 1)
			{
				tputs(tgetstr("up", NULL), 1, ft_putchar);
				tputs(tgoto(tgetstr("ch", NULL), 0, term->ws_x - 1), 1, ft_putchar);
				ft_putchar(' ');
				tputs(tgoto(tgetstr("ch", NULL), 0, term->ws_x - 1), 1, ft_putchar);
			}
			else
			{
				tputs(tgetstr("le", NULL), 1, ft_putchar);
				tputs(tgetstr("dc", NULL), 1, ft_putchar);
//				if (term->line[term->pos] == '\t')
//				{
//					tputs(tgetstr("", NULL), 1, ft_putchar);
//				}
			}
		}
		else
		{
			end = term->mlen - term->pos;
			i = term->ws_x - term->x;
			if ((term->x + end) >= term->ws_x)
			{
				if (term->x == 1)
				{
					tputs(tgetstr("up", NULL), 1, ft_putchar);
					tputs(tgoto(tgetstr("ch", NULL), 0, term->ws_x - 1), 1, ft_putchar);
					
				}
				else
				{
					tputs(tgetstr("le", NULL), 1, ft_putchar);
					tputs(tgetstr("dc", NULL), 1, ft_putchar);
				}
				end = end - i;
				add = i;
				while (end > 0)
				{
					c = term->line[term->pos + add + 1];
					tputs(tgoto(tgetstr("ch", NULL), 0, term->ws_x - 1), 1, ft_putchar);
					ft_putchar(c);
					tputs(tgetstr("do", NULL), 1, ft_putchar);
					tputs(tgetstr("dc", NULL), 1, ft_putchar);
					add += term->ws_x;
					i = term->ws_x;
					end = end - i;
					count++;
				}
				while (count > 0)
				{
					count--;
					tputs(tgetstr("up", NULL), 1, ft_putchar);
					tputs(tgoto(tgetstr("ch", NULL), 0, term->x - 2), 1, ft_putchar);
				}
			}
			else
			{
				if (term->x == 1)
				{
					tputs(tgetstr("up", NULL), 1, ft_putchar);
					tputs(tgoto(tgetstr("ch", NULL), 0, term->ws_x - 1), 1, ft_putchar);
					ft_putchar(' ');
					tputs(tgoto(tgetstr("ch", NULL), 0, term->ws_x - 1), 1, ft_putchar);
				}
				else
				{
					tputs(tgetstr("le", NULL), 1, ft_putchar);
					tputs(tgetstr("dc", NULL), 1, ft_putchar);
				}
			}
		}
		term->pos--;
		term->mlen--;
		ft_rotchar(term);
	}
}
void	ft_supp(t_term *term)
{
	int		i;
	int		c;
	int		add;
	int		end;
	int		count;

	tputs(tgetstr("ei", NULL), 1, ft_putchar);
	count = 0;
	ft_update_window(term);
	if (term->pos != term->mlen)
	{
		end = term->mlen - term->pos;
		i = term->ws_x - term->x;
		add = i;
		if (term->x + end > term->ws_x)
		{
			tputs(tgetstr("dc", NULL), 1, ft_putchar);
			end -= i;
			while (end > 1)
			{
				i = term->ws_x;
				end -= i;
				c = term->line[term->pos + add + 1];
				tputs(tgoto(tgetstr("ch", NULL), 0, term->ws_x - 1), 1, ft_putchar);
				ft_putchar(c);
				tputs(tgetstr("do", NULL), 1, ft_putchar);
				tputs(tgetstr("cr", NULL), 1, ft_putchar);
				tputs(tgetstr("dc", NULL), 1, ft_putchar);
				add += i;
				count++;
			}
			while (count != 0)
			{
				tputs(tgetstr("up", NULL), 1, ft_putchar);
				tputs(tgoto(tgetstr("ch", NULL), 0, term->x - 1), 1, ft_putchar);
				count--;
			}
		}
		else
			tputs(tgetstr("dc", NULL), 1, ft_putchar);
		term->mlen--;
		ft_rotchar(term);
	}
}

void	ft_move_home(t_term *term)
{
	ft_update_window(term);
	while (term->pos != 0)
		ft_left_arrow(term);
}

void	ft_move_end(t_term *term)
{
	ft_update_window(term);
	while (term->pos != term->mlen)
		ft_right_arrow(term);
}
/*
  t_term	*ft_up_arrow(t_term *term, t_hty *hty)
  {
  if ()
  }

  t_term	*ft_down_arrow(t_term *term, t_hty *hty)
  {
	
  }
*/
