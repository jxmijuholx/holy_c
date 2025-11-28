/** ft_strlcat.c - Jami Juhola **/

#include "libft.h"

/*
@param i = the part of the source string that is appended
*/

size_t	ft_strlcat(char * restrict dst, const char * restrict src, size_t dst_size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);

	if (dst_size <= dst_len)
		return (dst_size + src_len);

	i = dst_size - dst_len - 1;

	while (*src && i)
	{
		dst[dst_len] = *src;
		dst_len++;
		src++;
		i--;

	}
	dst[dst_len] = '\0';

	return (dst_len + ft_strlen(src));
}
