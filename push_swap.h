#ifndef PUSH_SWAP_H_
# define PUSH_SWAP_H_

# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

# define CHECK_ALLOWED_CHARS(c) (c != ' ' && !ft_isdigit(c) && c != '-')

typedef struct s_stack
{
    int num;
    struct s_stack *next;
} t_stack;

typedef struct s_c {
	int c_a;
	int c_b;
} t_c;

typedef struct s_stacks {
	t_c c;
    int *stack_a;
    int *stack_b;
} t_stacks;

int 		check_all_num(int *args_count, char *arg);
int 		check_all_num_2d(int *args_count, char **arg);
int 		check_args(int *args_count, char argc, char **args);
int 		ft_error(char *text);
void 		ft_putstr(char *str);
t_stack 	*addToList(t_stack last, int new_num);
void 		fill_stacks(t_stacks *stacks, int pt, int ac, char **argv);
void 		printf_stacks(t_stacks stacks, int args_count);
void 		shift_up(int *stack, int args_count);
void 		shift_down(int *stack, int args_count);

void 		swap(char s, int *stack);
void 		push(char stack, t_stacks *stacks, int ac);
void 		rot(char s, int *stack, int ac);
void		r_rot(char s, int *stack, int ac);
void		ss(t_stacks stacks);
void		rr(t_stacks stacks);
void		rrr(t_stacks stacks);

void		sort(t_stacks stacks);

#endif
