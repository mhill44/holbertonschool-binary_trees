#include "binary_trees.h"

/**
 *binary_tree_insert_right - inserts a node as the right-child of another node
 *@parent: pointer parent node to insert the right-child in
 *@value: value new node
 *Return: new node
 **/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newN = NULL;

	if (parent == NULL)
		return (NULL);

	newN = binary_tree_node(parent, value);

	if (!parent->right)
	{
		parent->right = newN;
	}
	else
	{
		newN->right = parent->right;
		parent->right = newN;
	}
	return (newN);

}

/**
 *binary_tree_insert_left - insertd node as the left child
 *@parent: pointer to the node to insert left-child
 *@value: value to store in the new node
 *Return: pointer to the created node or NULL if fails or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_child, *original_left_child;

	if (parent == NULL)
		return (NULL);

	left_child = (binary_tree_t *) malloc(sizeof(binary_tree_t));
	if (left_child == NULL)
		return (NULL);

	left_child->n = value;
	left_child->parent = parent;
	left_child->left = NULL;
	left_child->right = NULL;
	if (parent->left != NULL)
	{
		original_left_child = parent->left;
		left_child->left = original_left_child;
		original_left_child->parent = left_child;
	}
	parent->left = left_child;
	return (left_child);

}

/**
 *bst_insert - insert value in bst
 *@tree: double pointer to the root of bst
 *@value: value to store in the new node
 *Return: pointer to the created node or NULL if fails or if parent is NULL
 */
binary_tree_t *bst_insert(bst_t **tree, int value)
{
	binary_tree_t *newN, *tree_n;

	tree_n = (binary_tree_t*) &tree;
	newN = binary_tree_node(tree_n, value);

	if (tree == NULL || *tree == NULL)
		return (newN);

	if (tree_n->n != newN->n || tree_n->right->n != newN->n || tree_n->left->n != newN->n)
	{
		if (value < tree_n->n)
			tree_n->left = binary_tree_insert_left(tree_n, value); 
		else if (value > tree_n->n)
			tree_n->right = binary_tree_insert_right(tree_n, value);
		tree = (bst_t**) &tree_n;
		tree_n = bst_insert(tree, value);
		newN = tree_n;
	}
	return (newN);
}

