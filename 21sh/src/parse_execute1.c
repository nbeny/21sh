#include "21sh.h"

t_red	*creat_redirection(void)
{
	t_red   *r;

	if (!(r = (t_red *)malloc(sizeof(t_red))))
		return (NULL);
	r->mask = NULL;
	r->file = NULL;
	r->fd1 = -1;
	r->fd2 = -1;
	r->next = NULL;
	return (r);
}

int		check_start_red_file(t_term *term, char *str)
{
	term->i += ft_strlen(str);
	while (term->line[term->i] != '\0' &&\
		   (term->line[term->i] == ' ' || term->line[term->i] == '\t'))
		term->i++;
	term->p[0] = term->i;
	while (ft_isprint(term->line[term->i]) && term->line[term->i] != ' ' &&\
		   term->line[term->i] != '\t' && term->line[term->i] != '\n' &&\
		   term->line[term->i] != '>' && term->line[term->i] != '<' &&\
		   term->line[term->i] != '&' && term->line[term->i] != '|')
		term->i++;
	term->p[1] = term->i;
	if (term->p[0] == term->p[1])
	{
		term->error = ft_strdup("parse error near `\\n`\n");
		return (0);
	}
	return (1);
}

