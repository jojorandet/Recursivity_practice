Assignment name : powerset
Expected files : *.c *.h
Allowed functions : atoi, printf, malloc, calloc, realloc, free.
---------------------------------------------------------------

Write a program that will take as argument an integer n followed by a set of integers,
your program should display all the subsets of whose sum of elements is n.

In case of a malloc error your program will exit with the code 1.
We will not test invalid test(for example '1 1 2')
hint: the empty set is a subset of anyset.


For example this should work:
$> ./powerset 3 1 0 2 4 5 3 | cat -e
3$
0 3$
1 2$
1 0 2$
$> ./powerset 12 5 2 1 8 4 3 7 11 | cat -e
8 4$
1 11$
1 4 7$
1 8 3$
2 3 7$
5 4 3$
5 7$
5 2 1 4$
$> ./powerset 7 3 8 2| cat -e
$