/* node.c
 *
 *  Created on: 16 Mar 2022
 *      Author: somnus */

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

struct node* create()
{
	return NULL;
}

int findDataStructureElementPosition(T_ptrNode ptrNode, int element)
{
	int position = 0;

	while (ptrNode != NULL && ptrNode->data != element)
	{
		ptrNode = ptrNode->ptrNext;
		position++;
	}

	return ptrNode != NULL ? position : -1;
}

// Destroys the entire data structure
	// returns 0 if operation fails
	// returns 1 if operation success
int destroyDataStructure(T_ptrNode *ptrNode)
{
	int operationResult = 0;
	T_ptrNode ptrTemp;

	while (*ptrNode != NULL)
	{
		ptrTemp = (*ptrNode)->ptrNext;
		free(*ptrNode);
		*ptrNode = ptrTemp;
	}

	ptrNode = NULL;

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
		printf("[%d]", ptrNode->data);
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
// returns 0 if operation fails
// returns 1 if operation success
int removeElementFromDataStructure(T_ptrNode *ptrToNode, int element)
{
	int operationResult = 0;
	if (elementExistsInDataStructure(*ptrToNode, element))
	{
		T_ptrNode ptrPreviousElement = create();
		T_ptrNode ptrCurrentElement = (*ptrToNode);

		while (ptrToNode != NULL && (*ptrToNode)->data != element)
		{
			ptrPreviousElement = (*ptrToNode);
			*ptrToNode = (*ptrToNode)->ptrNext;
		}

		if (ptrPreviousElement != NULL)
		{
			ptrPreviousElement->ptrNext = ptrCurrentElement->ptrNext;
			free(ptrCurrentElement);
			operationResult = 1;
		}
	}

	return operationResult;
}

