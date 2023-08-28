#include "binary_trees.h"

/**
 * binary_tree_insert_left - a function that inserts a node
 * As the left-child of another node
 * If parent already has a left-child, the new node must take its place,
 * and the old left-child must be set as the left-child of the new node.
 * @parent: is a pointer to the node to insert the left-child in
 * @value: is the value to store in the new node
 * Return: a pointer to the created node
 * Or NULL on failure or if parent is NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}

	parent->left = new_node;

	return (new_node);
}