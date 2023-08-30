#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: is a ptr to the root node of the tree to measure the balance factor
 * Return: 0 if tree is NULL
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = (int)binary_tree_total_height(tree->left);
	right_height = (int)binary_tree_total_height(tree->right);

	return (left_height - right_height);
}

/**
 * binary_tree_total_height - measures the full height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height.
 * Return: 0 if tree is NULL
*/
size_t binary_tree_total_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_total_height(tree->left);
	right_height = binary_tree_total_height(tree->right);

	if (left_height > right_height)
		return (1 + left_height);
	return (1 + right_height);
}
