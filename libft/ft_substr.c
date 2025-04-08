#include "libft.h"

char *ft_substr(char const *s, unsigned int start,size_t len)
{
	char	*sub;

	if(!s)
		return (0);
	
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	
	sub = malloc(sizeof(char) * (len + 1));	
	if(!sub)
		return (NULL);

	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
