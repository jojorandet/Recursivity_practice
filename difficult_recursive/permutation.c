
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, char *src)
{
	while (*src)
	{
		*dst = *src;
		src++;
		dst++;
	}
	return (dst);
}

char	*add_array_element(char *array, char element)
{
	char	*new_array;

	new_array = calloc(ft_strlen(array) + 2, sizeof(char));
	if (!new_array)
		return (NULL);
	char *cursor = ft_strcpy(new_array, array);
	*cursor = element;
	return (new_array);
}

char	*remove_array_element(char *array, char c)
{
	char	*cursor;
	char	*new_smaller_array;

	new_smaller_array = calloc(ft_strlen(array), sizeof(char));
	if (!new_smaller_array)
		return (NULL);
	cursor = new_smaller_array;
	while (*array)
	{
		if (*array == c)
			array++;
		else
		{
			*cursor = *array;
			cursor++;
			array++;
		}
	}
	return (new_smaller_array);
}

void	permutation(char *set_to_explore, char *path, int index) // fonction elle meme est responsable de ses free
{
	char	*new_set_to_explore;
	int	i = 0;

	new_set_to_explore = remove_array_element(set_to_explore, set_to_explore[index]); //calloc here, need to free
	path = add_array_element(path, set_to_explore[index]); //calloc here, need to free
	//printf("path is worth %s\n", path);
	int len = ft_strlen(new_set_to_explore);
	if (len == 0) // bout de ma branche, j'imprime le reste
	{
		while (path[i])
		{
			write(1, &path[i], 1);
			i++;
		}
		write(1, "\n", 1);
		free(new_set_to_explore); //gets freed here
		free(path); //gets freed here 
		return ;
	}
	i = 0;
	while (i < len)
	{
		permutation(new_set_to_explore, path, i);
		i++;
	}
	free(new_set_to_explore); // elle ne peux pas quitter sans avoir libéré les éléments qu'elle a créé
	free(path);
}

int main(int argc, char **argv)
{
	int		i;
	int		len;

	if (argc != 2)
		return (1);
	len = ft_strlen(argv[1]);
	i = 0;
	while (i < len)
	{
		permutation(argv[1], "", i);
		i++;
	}
	return (0);
}
