#include "../push_swap.h"

int		find_high_ind(char s_t, t_stacks *stacks)
{
	int count = (s_t == 'a') ? stacks->c.c_a : stacks->c.c_b;
	t_stack *stack = (s_t == 'a') ? stacks->stack_a : stacks->stack_b;
	int i = 0;
	int temp = 0;

	while (i < count)
	{
		if (stack[temp].num < stack[i].num)
			temp = i;
		++i;
	}
	return (temp);
}

int max_five(t_stacks *stacks)
{
	int index;
	int i = 0;
	int j = 0;
	int min, mid = 0, max;

	if (stacks->c.c_a == 2)
	{
		if (stacks->stack_a[0].num > stacks->stack_a[1].num)
			swap('a', stacks->stack_a);
		return (0);
	}
	while (stacks->c.c_a > 3)
	{
		min = find_min_nu_ind('a', stacks);
		if (stacks->c.c_a / 2 >= min)
			while (i < min)
			{
				rot('a', stacks->stack_a, stacks->c.c_a);
				++i;
			}
		else
			while (i < stacks->c.c_a - min)
			{
				r_rot('a', stacks->stack_a, stacks->c.c_a);
				++i;
			}
		push('b', stacks);
		i = 0;
	}
	min = find_min_nu_ind('a', stacks);
	max = find_high_ind('a', stacks);
	while (min == mid || max == mid)
		++mid;
	if (min == 1 && mid == 0)
		swap('a', stacks->stack_a);
	else if (max == 1 && min == 2)
		r_rot('a', stacks->stack_a, stacks->c.c_a);
	else if (max == 1 && min == 0)
	{
		swap('a', stacks->stack_a);
		rot('a', stacks->stack_a, stacks->c.c_a);
	}
	else if (max == 0 && min == 1)
		rot('a', stacks->stack_a, stacks->c.c_a);
	else if (max == 0 && min == 2)
	{
		swap('a', stacks->stack_a);
		r_rot('a', stacks->stack_a, stacks->c.c_a);
	}
	back_fill(stacks);
	return (0);
}
