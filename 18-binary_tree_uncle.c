#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a noe in a tree
 * @node: node in tree to find its uncle
 *
 * Return: the uncle of a given node
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *left = NULL;
	binary_tree_t *right = NULL;
	binary_tree_t *parent = (node != NULL ? node->parent : NULL);

	if ((parent != NULL) && (parent->parent != NULL))
	{
		left = parent->parent->left;
		right = parent->parent->right;
	}
	return (left == parent ? right : left);
}
