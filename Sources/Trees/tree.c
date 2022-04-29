/*  tree.c
 *
 *  Created on: 1 Apr 2022
 *      Author: somnus  */

#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

// Create a new node for your treenode.
T_ptrTreeNode createTreeNode(int element)
{
	T_ptrTreeNode result = (struct treenode*) malloc(sizeof(struct treenode));

	if (result != NULL)
	{
		result->data = element;
		result->childLeft = NULL;
		result->childRight = NULL;
	}

	return result;
}

void printTree(T_ptrTreeNode root)
{
	if (root == NULL)
	{
		printf("----<empty tree>----\n");
	}
	else
	{
		printf("value: %d\n", root->data);
		printf("left: \n");
		printTree(root->childLeft);
		printf("right: \n");
		printTree(root->childRight);
	}
}
