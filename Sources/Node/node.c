/* node.c
 *
 *  Created on: 16 Mar 2022
 *      Author: somnus */

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node* init()
{
	return NULL;
}

T_ptrNode allocateMemoryForNewNode()
{
	T_ptrNode allocateNodeInMemory = init();
	allocateNodeInMemory = (struct node*) malloc(sizeof(struct node));

	if (allocateNodeInMemory == NULL)
	{
		printf("ERROR while allocating memory for the Node.\n");
	}

	return allocateNodeInMemory;
}

int findDataStructureElementPosition(T_ptrNode ptrNode, int element)
{
	int position = 0;

	if (ptrNode != NULL)
	{
		while (ptrNode != NULL && ptrNode->data != element)
		{
			ptrNode = ptrNode->ptrNext;
			position++;
		}
	}

	return ptrNode != NULL ? position : -1;
}

void deallocateNodeFromDataStructure(T_ptrNode *ptrNode)
{
	if (*ptrNode != NULL)
	{
		T_ptrNode ptrTemp;
		ptrTemp = (*ptrNode)->ptrNext;
		free(*ptrNode);
		*ptrNode = ptrTemp;
	}
}

// Destroys the entire data structure
// 		returns 0 if operation fails
// 		returns 1 if operation success
int destroyDataStructure(T_ptrNode *ptrNode)
{
	int operationResult = 0;

	while (*ptrNode != NULL)
	{
		deallocateNodeFromDataStructure(&(*ptrNode));
	}

	*ptrNode = NULL;

	operationResult = 1;
	return operationResult;
}

int getDataStructureSize(T_ptrNode ptrNode)
{
	int numElements = 0;

	while (ptrNode != NULL)
	{
		ptrNode = ptrNode->ptrNext;
		numElements++;
	}

	return numElements;
}

void printDataStructure(T_ptrNode ptrNode)
{
	while (ptrNode != NULL)
	{
		printf("[%d]->", ptrNode->data);
		ptrNode = ptrNode->ptrNext;
	}
	printf("\n");
}

int dataStructureIsEmpty(T_ptrNode ptrToNode)
{
	return getDataStructureSize(ptrToNode) == 0 ? 1 : 0;
}

int elementExistsInDataStructure(T_ptrNode ptrToNode, int element)
{
	return findDataStructureElementPosition(ptrToNode, element) >= 0 ? 1 : 0;
}

// Removes first occurrence of the element from the set
// 		returns 0 if operation fails
// 		returns 1 if operation success
int removeElementFromDataStructure(T_ptrNode *ptrNode, int element)
{
	int operationResult = 0;

	if (*ptrNode != NULL && elementExistsInDataStructure(*ptrNode, element))
	{
		if (*ptrNode != NULL && (*ptrNode)->data == element)
		{
			deallocateNodeFromDataStructure(&(*ptrNode));
		}
		else
		{
			T_ptrNode ptrPreviousElement;
			T_ptrNode ptrCurrent = (*ptrNode);

			while (ptrCurrent != NULL && ptrCurrent->data != element)
			{
				ptrPreviousElement = ptrCurrent;
				ptrCurrent = ptrCurrent->ptrNext;
			}

			if (ptrCurrent != NULL)
			{
				ptrPreviousElement->ptrNext = ptrCurrent->ptrNext;
				free(ptrCurrent);
			}
		}
		operationResult = 1;
	}
	return operationResult;
}
