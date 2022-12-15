#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a binary tree's node
 * @node: node to find sibing of
 *
 * Return: sibling of the node in question
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *left = NULL;
	binary_tree_t *right = NULL;

	if ((node != NULL) && (node->parent != NULL))
	{
		left = node->parent->left;
		right = node->parent->right;
	}
	return (left == node ? right : left);
}
