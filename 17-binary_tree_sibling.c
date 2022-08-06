#include "binary_trees.h"

/**
 *binary_tree_sibling - finds the sibling of a node
 *@node: is a pointer to the node to find the sibling
 *Return: Your function must return a pointer to the sibling node
 *        If node is NULL, return NULL
 *        If node has no sibling, return NULL
 **/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling, *a, *b;

	if (!node || !node->parent)
		return (NULL);

	a = node->parent->right;
	b = node->parent->left;

	if (b || a)
	{
		if (b == node)
			sibling = a;
		if (a == node)
			sibling = b;
	}
	return (sibling);

}
