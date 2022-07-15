#include <cub3D.h>

char	*ft_rmt_chr(const char *s, char c)
{
	char	*res;
	size_t	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!len || c == 0 || s[len - 1] != c)
	{
		res = ft_strdup(s);
		if (!res)
			return (NULL);
		return (res);
	}
	res = ft_calloc(len, sizeof(char));	
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, len);
	return (res);
}
