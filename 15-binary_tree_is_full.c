#include "binary_trees.h"

/**
 * full_tree - checks if binary tree is full
 * @tree: pointer to root
 * @is_full: pointer to full status
 *
 * Return: void
 */

void full_tree(const binary_tree_t *tree, int *is_full)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL) ^ (tree->right != NULL))
		{
			if (is_full != NULL)
			{
				*is_full = 0;
			}
		}
		else
		{
			full_tree(tree->left, is_full);
			full_tree(tree->right, is_full);
		}
	}
}

/**
 * binary_tree_is_full - checks if binary tree is full
 * @tree: pointer to root
 *
 * Return: 1 if tree is full else 0
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int is_full = (tree != NULL ? 1 : 0);

	full_tree(tree, &is_full);
	return (is_full);
}
