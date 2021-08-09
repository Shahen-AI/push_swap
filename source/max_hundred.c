#include "../push_swap.h"

int find_min_nu_ind_new(t_stacks *stacks)
{
	int i = 0;
	int temp = 0;
	while (stacks->stack_a[temp].check != 0)
		++temp;		

	while (i < stacks->c.c_a)
	{
		if (stacks->stack_a[i].check == 0)
		{
			if (stacks->stack_a[temp].num > stacks->stack_a[i].num
				&& stacks->stack_a[i].check != 1)
				temp = i;
		}
			++i;
	}
	return (temp);
}

void indexing(t_stacks *stacks)
{
	int i = -1;
	int index = 0;

	while (++i < stacks->c.c_a)
		stacks->stack_a[i].check = 0;
	i = 0;
	while (i < stacks->c.c_a)
	{
		index = find_min_nu_ind_new(stacks);
		stacks->stack_a[index].index = i;
		stacks->stack_a[index].check = 1;
		++i;
	}
}

int in_chunck(int index, int chunck_num, int ch_s)
{
	return (index >= chunck_num * ch_s 
			&& index < chunck_num * ch_s + ch_s);
}
