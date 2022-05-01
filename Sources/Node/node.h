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

struct node* init();
T_ptrNode allocateMemoryForNewNode();
int findDataStructureElementPosition(T_ptrNode ptrToNode, int element);
T_ptrNode getPtrNodeFromDataStructureByElementValue(T_ptrNode ptrNode, int element);
void deallocateNodeFromDataStructure(T_ptrNode *ptrNode);
int destroyDataStructure(T_ptrNode *ptrNode);
int getDataStructureSize(T_ptrNode ptrNode);
void printDataStructure(T_ptrNode ptrToNode);
int dataStructureIsEmpty(T_ptrNode ptrToNode);
int elementExistsInDataStructure(T_ptrNode ptrToNode, int element);
int removeElementFromDataStructure(T_ptrNode *ptrToNode, int element);

#endif
