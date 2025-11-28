/** ft_strjoin.c - Jami Juhola **/
#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);

	if(!s1||!s2)
		return (NULL);
	
	new = malloc(sizeof(char) * len1 + len2 + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, len1);
	ft_memcpy(new + len1, s2, len2);
	new[len1 + len2] = '\0';

	return (new);
}
