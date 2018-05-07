/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:34:36 by sshiling          #+#    #+#             */
/*   Updated: 2018/01/29 13:34:38 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/ft_printf.h"

typedef struct		s_stack
{
	int				num;
	int				diff;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_com
{
	int				rotator;
	char			*final;
}					t_com;

t_stack				*create_new_node(void);
t_stack				*copy_args_in_stack(int argc, char **argv);
void				ft_swap(int *a, int *b);
int					partition(int *stack1, int start, int end);
void				quick_sort(int *stack1, int start, int end);
void				print_final_result(char *origin);
int					sab(t_stack **head);
int					pab(t_stack **head_to, t_stack **head_from);
int					rab(t_stack **head);
int					rrab(t_stack **head);
int					ss(t_stack **stack1, t_stack **stack2);
int					rr(t_stack **stack1, t_stack **stack2);
int					rrr(t_stack **stack1, t_stack **stack2);
int					s_len(t_stack *stack);
int					*create_array_from_list(t_stack *stack, int len);
int					find_mid_value(t_stack *stack, int len);
t_com				*new_result(void);
char				*add_to_string(char *to, char *add);
int					div_stack_a(t_stack **stack1, t_stack **stack2,
	t_com **result, int len);
int					div_stack_b(t_stack **stack1, t_stack **stack2,
	t_com **result, int len);
void				comb_1(t_stack **stack, t_com **result);
void				comb_2(t_stack **stack, t_com **result);
void				comb_3(t_stack **stack, t_com **result);
void				comb_4(t_stack **stack, t_com **result);
void				comb_5(t_stack **stack, t_com **result);
void				comb_6(t_stack **stack, t_com **result);
void				comb_7(t_stack **stack, t_com **result);
void				comb_8(t_stack **stack, t_com **result);
void				comb_9(t_stack **stack, t_com **result);
void				swap_three_a(t_stack **stack, t_com **result);
void				swap_three_b(t_stack **stack, t_com **result);
void				swap_three(t_stack **stack, t_com **result);
void				swap_two(t_stack **stack, t_com **result);
void				push_back(t_stack **stack1, t_stack **stack2,
	t_com **result, int half);
void				rotate_back(t_stack **stack, t_com **result, int back);
void				swap_elements(t_stack **stack1, t_stack **stack2,
	t_com **result, int len);
void				stack_del(t_stack **stack);
void				doubles_checker(t_stack **stack);
int					check_int_overflow(char *str);
int					check_argv(char *str);
int					add_pa_pb(char **origin, char **res, int i);
int					add_ra_rra(char **origin, char **res, int i);
int					add_rb_rrb(char **origin, char **res, int i);
int					add_others(char **tmp, char **res, int i);

#endif
