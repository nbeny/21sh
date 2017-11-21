#include "21sh.h"

char	*ft_multi_strchr(const char *line)
{
	while (!ft_isalnum(*line) && *line != '\0')
		line++;
	if (ft_isalnum(*line))
		return ((char *)line);
	return (NULL);
}
