#include "../push_swap.h"

void fill_from_2d(int *stack, int ac, char **args)
{
    int i = 0;
    while (i < ac)
    {
        stack[i] = ft_atoi(args[i]);
        ++i;
    }
}

void fill_stacks(t_stacks *stacks, int pt, int ac, char **argv)
{
    if (pt == 1)
        fill_from_2d(stacks->stack_a, ac, ft_split((const char *)argv[1], ' '));
    else if (pt == 2)
        fill_from_2d(stacks->stack_a, ac, ++argv);
}