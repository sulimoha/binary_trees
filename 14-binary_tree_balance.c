#include "binary_trees.h"

/**
 * height_of_tree - function to count tree height
 * @tree: binary tree to measure
 * @n: accumulated height of current tree
 * @height: pointer to maximum height value
 *
 * Return: void
 */

void height_of_tree(const binary_tree_t *tree, int n, int *height)
{
	if (tree != NULL)
	{
		if ((tree->left == NULL) && (tree->right == NULL))
		{
			if (n > *height)
			{
				*height = n;
			}
		}
		else
		{
			height_of_tree(tree->left, n + 1, height);
			height_of_tree(tree->right, n + 1, height);
		}
	}
}

/**
 * binary_tree_balance - function that measures the
 *balance factor of a binary tree
 * @tree: pointer to the root of the binary tree
 *
 * Return: balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor = 0;
	int l_height = 0;
	int r_height = 0;

	if (tree != NULL)
	{
		height_of_tree(tree->left, 1, &l_height);
		height_of_tree(tree->right, 1, &r_height);
	}
	balance_factor = l_height - r_height;
	return (balance_factor);
}
