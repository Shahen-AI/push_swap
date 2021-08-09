#include "../push_swap.h"

void	swap(char s, t_stack *stack)
{
    t_stack temp;

    temp = stack[1];
    stack[1] = stack[0];
    stack[0] = temp;
	ft_putstr("s");
	ft_putchar_fd(s, 1);
	ft_putchar_fd('\n', 1);
}

void	push(char stack, t_stacks *stacks)
{
    if (stack == 'a')
    {
        shift_down(stacks->stack_a, stacks->c.c_a);
        stacks->stack_a[0] = stacks->stack_b[0];
        shift_up(stacks->stack_b, stacks->c.c_b);
		--stacks->c.c_b;
		++stacks->c.c_a;
    }
    else if (stack == 'b')
    {
        shift_down(stacks->stack_b, stacks->c.c_b);
        stacks->stack_b[0] = stacks->stack_a[0];
        shift_up(stacks->stack_a, stacks->c.c_a);
		--stacks->c.c_a;
		++stacks->c.c_b;
    }
	ft_putstr("p");
	ft_putchar_fd(stack, 1);
	ft_putchar_fd('\n', 1);
}

void	rot(char s, t_stack *stack, int ac)
{
    t_stack temp;

	temp = stack[0];
    shift_up(stack, ac);
    stack[ac - 1] = temp;
	ft_putstr("r");
	ft_putchar_fd(s, 1);
	ft_putchar_fd('\n', 1);
}

void	r_rot(char s, t_stack *stack, int ac)
{
	t_stack temp;

	temp = stack[ac - 1];
    shift_down(stack, ac);
    stack[0] = temp;
	ft_putstr("rr");
	ft_putchar_fd(s, 1);
	ft_putchar_fd('\n', 1);
}
