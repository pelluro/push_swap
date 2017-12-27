//
// Created by pelluro on 27/12/17.
//

int		ft_aschar(const char *s, int c)
{
	char	*src;
	int		i;
	
	src = (char *)s;
	i = 0;
	while (src[i] && src[i] != (char)c)
		i++;
	if (src[i] == (char)c)
		return (1);
	return (0);
	
}