#include "binary_trees.h"
#include "101-binary_tree_levelorder.c"
/**
 * binary_tree_is_complete - Check if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int flag;

	if (!tree)
	{
		return (0);
	}

	flag = 0;

	/* Queue for level-order traversal */
	queue_node_t *front = NULL, *rear = NULL;

	enqueue(&front, &rear, tree);

	while (front != NULL)
	{
		const binary_tree_t *current = front->node;

		/* Check for the flag and return 0 if a NULL node is encountered */
		if (flag && current != NULL)
		{
			return (0);
		}

		if (!current)
		{
			flag = 1;
		}
		else
		{
			enqueue(&front, &rear, current->left);
			enqueue(&front, &rear, current->right);
		}

		dequeue(&front);
	}

	return (1);
}
