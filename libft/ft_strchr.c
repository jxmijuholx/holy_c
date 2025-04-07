/** ft_strchr.c - Jami Juhola **/
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while(*s)
	{
		if(*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *) s);
	
	return ((char*)NULL);
}
