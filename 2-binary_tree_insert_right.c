#include "binary_trees.h"

/**
 *binary_tree_insert_right - inserts a node as the right-child of another node
 *@parent: pointer parent node to insert the right-child in
 *@value: value new node
 *Return: new node
 **/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode = NULL;

	if (parent == NULL)
		return (NULL);

	newNode = binary_tree_node(parent, value);

	if (parent->right != NULL)
	{
		newNode->right = parent->right;
		newNode->right->parent = newNode;
	}
	parent->right = newNode;
	return (newNode);

}
