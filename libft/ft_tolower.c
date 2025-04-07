/** ft_tolower.c - Jami Juhola **/
int ft_tolower(int c)
{
	if((c >= 'A' && c <= 'Z'))
		return (c + 32);
	else
		return (c);
}
