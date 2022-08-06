#include "binary_trees.h"

/**
 *binary_tree_uncle - finds the uncle of a node
 *@node: is a pointer to the node to find the uncle
 *Return: Your function must return a pointer to the uncle node
 *        If node is NULL, return NULL
 *        If node has no uncle, return NULL
 **/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *a, *b, *c;

	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	a = node->parent;
	b = node->parent->parent->left;
	c = node->parent->parent->right;

	if (a == b)
		return (c);
	else if (a == c)
		return (b);

	return (NULL);
}
