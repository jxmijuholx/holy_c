/** ft_strncpy.c - Jami Juhola **/
#include "libft.h"

char *ft_strncpy(char * dst, const char * src, size_t len)
{
    size_t  i;

    i = 0;
    while( i < len)
    {
        if(!src){
            dst[i] = '\0';
        }
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}