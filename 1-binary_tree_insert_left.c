#include "binary_trees.h"

/**
 * binary_tree_insert_left - a function
 * that inserts a node as the left-child of another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 *
 * Return: pointer to the created node,
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *temp;

	if (!parent)
	{
		return (NULL);
	}

	temp = binary_tree_node(parent, value);
	if (!temp)
	{
		return (NULL);
	}

	/* if the parent already has a left child reorganize */
	if (parent->left != NULL)
	{
		temp->left = parent->left;
		parent->left->parent = temp;
	}

	parent->left = temp;
	return (temp);
}
