/*  tree.h
 *
 *  Created on: 1 Apr 2022
 *      Author: somnus  */

#include <stdlib.h>
#include <stdio.h>

#ifndef TREES_TREE_H_
#define TREES_TREE_H_

typedef struct treenode *T_ptrTreeNode;
struct treenode
{
	int data;
	T_ptrTreeNode childLeft;
	T_ptrTreeNode childRight;
} treenode;


T_ptrTreeNode createTreeNode(int element);
void printTree(T_ptrTreeNode root);

#endif /* TREES_TREE_H_ */
