#include "libft.h"

char *ft_strstr(const char *haystack, const char *needle)
{
    size_t  i;
    size_t needle_len;

    if (*needle == '\0')
		return ((char *)haystack);

    needle_len = ft_strlen(needle);
    i = 0;
    
    while(haystack[i])
    {
        if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
			return ((char *)&haystack[i]);
		i++;
    }

    return ((char*)NULL);
}