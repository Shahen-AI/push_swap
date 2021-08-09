#include "../push_swap.h"

void fill_from_2d(t_stack *stack, int ac, char **args)
{
    int i = 0;
    while (i < ac)
    {
        stack[i].num = ft_atoi(args[i]);
        ++i;
    }
}

int double_check(t_stacks *stacks)
{
	int i;
	int j;

	i = 0;
	while (i < stacks->c.c_a)
	{
		j = i + 1;
		while (j < stacks->c.c_a)
		{
			if (stacks->stack_a[i].num == stacks->stack_a[j].num)
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

void fill_stacks(t_stacks *stacks, int pt, int ac, char **argv)
{
    if (pt == 1)
        fill_from_2d(stacks->stack_a, ac, ft_split((const char *)argv[1], ' '));
    else if (pt == 2)
        fill_from_2d(stacks->stack_a, ac, ++argv);
	if (!double_check(stacks))
		ft_error("There are doublicates in stack!\n");
}
