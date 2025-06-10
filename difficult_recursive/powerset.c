#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_int_array
{
	int	len;
	int	*int_array;
}				t_int_array;

void	print_int_array(t_int_array *s)
{
	int i = 0;

	while (i < s->len)
	{
		printf("%d", s->int_array[i]);
		i++;
	}
	printf("\n");
}

int	get_sum(t_int_array *s)
{
	int	i = 0;
	int	result = 0;

	while (i < s->len)
	{
		result += s->int_array[i];
		i++;
	}
	return (result);
}

t_int_array	add_to_array(t_int_array *s_array_to_add_to, int element_to_add)
{
	t_int_array	s_array_with_new_element;
	int			i = 0;

	s_array_with_new_element.int_array = calloc(s_array_to_add_to->len + 1, sizeof(int));
	if (!s_array_with_new_element.int_array)
	{
		s_array_with_new_element.int_array = NULL;
		s_array_with_new_element.len = 0;
	}
	s_array_with_new_element.len = s_array_to_add_to->len + 1;
	while (i < s_array_to_add_to->len)
	{
		s_array_with_new_element.int_array[i] = s_array_to_add_to->int_array[i];
		i++;
	}
	s_array_with_new_element.int_array[i] = element_to_add;
	return (s_array_with_new_element);
}

void powerset(int sum, t_int_array *s_search_array, t_int_array *s_path, int index, int *has_solution)
{
	if (index >= s_search_array->len)
	{
		if (get_sum(s_path) == sum)
		{
			print_int_array(s_path);  // Print s_path, not s_new_path$
			*has_solution = 1;
		}
		return;
	}
	powerset(sum, s_search_array, s_path, index + 1, has_solution);
	t_int_array s_new_path = add_to_array(s_path, s_search_array->int_array[index]);
	powerset(sum, s_search_array, &s_new_path, index + 1, has_solution);
	free(s_new_path.int_array);
}

int main(int argc, char **argv)
{
	int			sum;
	t_int_array	s_search_array;
	t_int_array	s_path_array;
	int			i;
	int			j;
	int			has_solution = 0;

	if (argc <= 2)
		return (1);
	sum = atoi(argv[1]);
	if (sum == 0)
	{
		printf("\n");
		return (0);
	}
	s_search_array.len = argc - 2;
	s_search_array.int_array = calloc(s_search_array.len, sizeof(int)); //no back slash 0 :)
	i = 2;
	j = 0;
	while (i < argc)
	{
		s_search_array.int_array[j] = atoi(argv[i]);
		i++;
		j++;
	}
	s_path_array.int_array = NULL;
	s_path_array.len = 0;
	i = 2;
	powerset(sum, &s_search_array, &s_path_array, 0, &has_solution);
	if (!has_solution)
		printf("\n");
	return (0);
}
