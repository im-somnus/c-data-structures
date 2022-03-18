/* node.h
 *
 *  Created on: 16 Mar 2022
 *  Author: somnus  */

#ifndef NODE_NODE_H_
#define NODE_NODE_H_

typedef struct node *T_ptrNode;
struct node
{
    int data;
    T_ptrNode ptrNext;
};

struct node* create();

int findDataStructureElementPosition(T_ptrNode ptrToNode, int element);
int destroyDataStructure(T_ptrNode *ptrNode);
int getDataStructureSize(T_ptrNode ptrNode);
void printDataStructure(T_ptrNode ptrToNode);
int dataStructureIsEmpty(T_ptrNode ptrToNode);

#endif /* NODE_NODE_H_ */
