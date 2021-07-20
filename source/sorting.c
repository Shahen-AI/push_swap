#include "../push_swap.h"

int		find_min_nu_ind(char s_t, t_stacks *stacks)
{
	int count = (s_t == 'a') ? stacks->c.c_a : stacks->c.c_b;
	int *stack = (s_t == 'a') ? stacks->stack_a : stacks->stack_b;
	int i = 0;
	int temp = 0;

	while (i < count)
	{
		if (stack[temp] > stack[i])
			temp = i;
		++i;
	}
	return (temp);
}

int a_checker(t_stacks *stacks, int index, int a)
{
	// printf("a- %d adsadadsad\n", a);
	int i = index;
	int j = 0;
	a++;
	if (a > 2)
		return 0;
	// printf("entered here!!!\n");
	while (i < stacks->c.c_a - 1)
	{
		if (stacks->stack_a[i] > stacks->stack_a[i + 1]){
			a_checker(stacks, i + 1, a);}
		++i;
	}
		// printf("HEY a- %d\n", a);
	if (stacks->stack_a[i] < stacks->stack_a[0])
	{
		i = index;
		j = 0;
		if (stacks->c.c_a / 2 >= i)
		{
			while (j < i + 1)
			{
				rot('a', stacks->stack_a, stacks->c.c_a);
				j++;
			}
		}
		else
		{
			while (j < stacks->c.c_a - i + 1)
			{
				r_rot('a', stacks->stack_a, stacks->c.c_a);
				j++;
			}
		}
		return (1);
	}
	else if (stacks->stack_a[i] > stacks->stack_a[0])
		return (1);

	return (0);
}


int back_fill(t_stacks *stacks)
{
	while (stacks->c.c_b > 0)
		push('a', stacks, stacks->c.c_b);
	return (0);
}

int to_b(t_stacks *stacks)
{
	int min_ind = find_min_nu_ind('a', stacks);
	int i = 0;
	// printf("--------- %d %d -- %d\n", stacks->c.c_a, stacks->c.c_b, min_ind);

	if ((stacks->c.c_a / 2) > min_ind)
	{
		while (i < min_ind)
		{
			rot('a', stacks->stack_a, stacks->c.c_a);
			++i;
		}
	}
	else
	{
		while (i < stacks->c.c_a - min_ind)
		{
			r_rot('a', stacks->stack_a, stacks->c.c_a);
			++i;
		}
	}
	push('b', stacks, stacks->c.c_a);
	// if (!a_checker(stacks, 0, 0))
	// 	to_b(stacks);
	// printf_stacks(*stacks, (stacks->c.c_a + stacks->c.c_b));
	if (stacks->c.c_a > 1)
		to_b(stacks);
	return (1);
}

void	sort(t_stacks stacks)
{
	// check a stack
	// int ret;
	
	// ret = a_checker(&stacks, 0, 0);
	// printf("am I joke to you? %d\n", ret);
	// if (!ret){
		to_b(&stacks);//}
	back_fill(&stacks);
}
