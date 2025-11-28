/** ft_strlcpy.c - Jami Juhola **/
#include "libft.h"

size_t ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < (dstsize))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';

	return (ft_strlen(src));
}
