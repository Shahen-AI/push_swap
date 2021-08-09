#include "../push_swap.h"

int from_top(t_stacks *stacks, int ch_n)
{
	int res = 0;

	while (!in_chunck(stacks->stack_a[res].index, ch_n, stacks->ch_s))
		++res;
	return (res);
}

int from_bottom(t_stacks *stacks, int ch_n)
{
	int res = stacks->c.c_a - 1;

	while (!in_chunck(stacks->stack_a[res].index, ch_n, stacks->ch_s))
		--res;
	return (res);
}

void push_ind(t_stacks *stacks, int chunk_count)
{
	int top_ind;
	int bottom_ind;
	int i, a = stacks->ch_s;

	while (a && stacks->c.c_a)
	{
		i = -1;
		top_ind = from_top(stacks, chunk_count);
		bottom_ind = from_bottom(stacks, chunk_count);
		if (top_ind > stacks->c.c_a - bottom_ind)
			while (++i < stacks->c.c_a - bottom_ind)
				r_rot('a', stacks->stack_a, stacks->c.c_a);
		else
			while (++i < top_ind)
				rot('a', stacks->stack_a, stacks->c.c_a);
		push('b', stacks);
		--a;
	}
}

int count_median(t_stacks *stacks)
{
	int i = 0;
	int temp = 0;
	while (i < stacks->c.c_a)
	{
		temp += stacks->stack_a[i].index;
		++i;
	}
	return (temp / stacks->c.c_a);
}

void back_fill_2(t_stacks *stacks)
{
	int index;
	int i;

	while (stacks->c.c_b)
	{
		i = 0;
		index = find_high_ind('b', stacks);
		i = index;
		if (i <= stacks->c.c_b / 2)
			while (i > 0)
			{
				rot('b', stacks->stack_b, stacks->c.c_b);
				--i;
			}
		else
			while (stacks->c.c_b - i > 0)
			{
				r_rot('b', stacks->stack_b, stacks->c.c_b);
				++i;
			}
		push('a', stacks);
	}
}

int mad_max(t_stacks *stacks, int ch_s)
{
	int mid_ind;
	int i = 0, x;
	int chuncks_count = stacks->c.c_a / ch_s;

	stacks->ch_s = ch_s;
	if (chuncks_count * stacks->ch_s != stacks->c.c_a)
		chuncks_count += 1;
	indexing(stacks);
	while (i < chuncks_count)
	{
		push_ind(stacks, i);
		++i;
	}
	back_fill_2(stacks);
	return (0);
}
