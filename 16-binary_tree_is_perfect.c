#include "binary_trees.h"

/**
 * tree_stats - checks leaes in binary tree
 * @tree: pointer to root
 * @n: accumulation of node count
 * @height: pointer to max height value
 * @leaves: number of nodes with no children
 *
 * Return: void
 */

void tree_stats(const binary_tree_t *tree, size_t n,
		size_t *leaves, size_t *height)
{
	if (tree != NULL)
	{
		if ((tree->left == NULL) && (tree->right == NULL))
		{
			if (leaves != NULL)
			{
				(*leaves)++;
			}
			if ((height != NULL) && (n > *height))
			{
				*height = n;
			}
		}
		else
		{
			tree_stats(tree->left, n + 1, leaves, height);
			tree_stats(tree->right, n + 1, leaves, height);
		}
	}
}

/**
 * binary_tree_is_perfect - checks if tree is perfect
 * @tree: pointer to root
 *
 * Return: 1 if perfect, else 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t leaf_count = 0;
	size_t tree_height = 0;

	tree_stats(tree, 0, &leaf_count, &tree_height);
	return ((int) leaf_count == (1 << tree_height) ? 1 : 0);
}
