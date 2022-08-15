#include "binary_trees.h"
#include <limits.h>
int find_min(const binary_tree_t *tree);
int find_max(const binary_tree_t *tree);

/**
 * binary_tree_is_bst - checks BST
 * @tree: node root
 * Return: 1 if true 0 if false
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int a, b;

	if (!tree)
		return (0);
	a = find_max(tree->left);
	b = find_min(tree->right);
	if (tree->left)
	{
		if (a >= tree->n)
			return (0);
	}
	if (tree->right)
	{
		if (b <= tree->n)
			return (0);
	}
	return (1);
}

/**
 * find_max - max of the tree
 * @tree: root
 * Return: max
 */

int find_max(const binary_tree_t *tree)
{
	int max, lmax, rmax;

	if (tree == NULL)
		return (INT_MIN);
	max = tree->n;
	lmax = find_max(tree->left);
	rmax = find_max(tree->right);
	if (lmax > max)
		max = lmax;
	if (rmax > max)
		max = rmax;
	return (max);
}

/**
 * find_min - min of the tree
 * @tree: root
 * Return: min
 */

int find_min(const binary_tree_t *tree)
{
	int min, lmin, rmin;

	if (tree == NULL)
		return (INT_MAX);
	min = tree->n;
	lmin = find_min(tree->left);
	rmin = find_min(tree->right);
	if (lmin < min)
		min = lmin;
	if (rmin < min)
		min = rmin;
	return (min);
}
