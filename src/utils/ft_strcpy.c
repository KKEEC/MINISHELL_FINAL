char	*ft_strcpy(char *dst, const char *src)
{
	char	*ret;

	if (!dst || !src)
		return (dst);
	ret = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (ret);
}