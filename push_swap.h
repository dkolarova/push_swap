/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkolarov <dkolarov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 00:00:00 by dkolarov          #+#    #+#             */
/*   Updated: 2025/09/23 11:32:43 by dkolarov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>

// Structure

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	bool			above_median;
	bool			cheapest;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target;
}	t_node;

typedef struct s_stacks
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
}	t_stacks;

// Input parsing
char		**parse_arguments(int argc, char **argv);
bool		validate_input(char **args);
bool		is_valid_number(const char *str);
bool		has_duplicates(char **args);
void		free_args(char **args);

// Stack creation and management
t_stacks	*init_stacks(char **args);
t_node		*create_node(int value);
void		add_node_back(t_node **stack, t_node *new_node);
void		free_stack(t_node **stack);
void		free_stacks(t_stacks *stacks);

// Stack utilities
int			get_stack_size(t_node *stack);
t_node		*get_last_node(t_node *stack);
t_node		*find_min(t_node *stack);
t_node		*find_max(t_node *stack);
bool		is_sorted(t_node *stack);

// Swap operations
void		sa(t_stacks *stacks, bool silent);
void		sb(t_stacks *stacks, bool silent);
void		ss(t_stacks *stacks, bool silent);

// Push operations
void		pa(t_stacks *stacks, bool silent);
void		pb(t_stacks *stacks, bool silent);

// Rotate operations
void		ra(t_stacks *stacks, bool silent);
void		rb(t_stacks *stacks, bool silent);
void		rr(t_stacks *stacks, bool silent);

// Reverse rotate operations
void		rra(t_stacks *stacks, bool silent);
void		rrb(t_stacks *stacks, bool silent);
void		rrr(t_stacks *stacks, bool silent);

// Main sorting functions
void		sort_stack(t_stacks *stacks);
void		sort_three(t_stacks *stacks);
void		turk_sort(t_stacks *stacks);

// Node analysis and positioning
void		analyze_nodes_a(t_stacks *stacks);
void		analyze_nodes_b(t_stacks *stacks);
void		set_positions(t_node *stack);
void		set_targets_a_to_b(t_stacks *stacks);
void		set_targets_b_to_a(t_stacks *stacks);
void		calculate_costs(t_stacks *stacks);
void		mark_cheapest(t_node *stack);

// Movement optimization
t_node		*get_cheapest_node(t_node *stack);
void		move_to_top(t_stacks *stacks, t_node *node, char stack_name);
void		rotate_both(t_stacks *stacks, t_node *cheapest);
void		rev_rotate_both(t_stacks *stacks, t_node *cheapest);
void		finish_rotation_a(t_stacks *stacks, t_node *cheapest);
void		finish_rotation_b(t_stacks *stacks, t_node *cheapest);

// Final positioning
void		move_min_to_top(t_stacks *stacks);

// Error handling
void		error_exit(const char *message);
void		cleanup_and_exit(t_stacks *stacks, char **args);

#endif