#include "binary_trees.h"

/**
 * count_parent - function that counts
 *nodes in a binary tree with at least 1 child
 * @tree: pointer to the root node
 * @n: pointer to the tree's parent value
 *
 * Return: pointer to tree's parent value
 */

void count_parent(const binary_tree_t *tree, size_t *n)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL) || (tree->right != NULL))
		{
			if (n != NULL)
			{
				(*n)++;
				count_parent(tree->left, n);
				count_parent(tree->right, n);
			}
		}
	}
}

/**
* binary_tree_nodes - function that outputs the number
* nodes in a binary tree with at least 1 child
* @tree: pointer to the root node
*
* Return: number of nodes, 0 if tree is NULL
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t n = 0;

	count_parent(tree, &n);
	return (n);
}
