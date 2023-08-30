#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: 0 if tree is NULL
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, expected_nodes;

	if (tree == NULL)
		return (0);

	height = binary_tree_total_height(tree);

	/* same as: 2^height - 1, pow(2, height) - 1*/
	expected_nodes = (1 << height) - 1;

	return (expected_nodes == binary_tree_size(tree));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the size
 * Return: 0 if tree is NULL
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_total_height - measures the height of a binary tree
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
