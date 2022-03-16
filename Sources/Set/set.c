/*  set.c
 *
 *  Created on: 16 Mar 2022
 *  Author: somnus */

#include <stdio.h>
#include <stdlib.h>
#include "../Set/set.h"

// Insert element in the array
	// returns 0 if operation failed
	// returns 1 if operation success
int insertElementInSet(T_ptrNode *ptrToSet, int element)
{
	int operationResult = 1;
	int foundPosition = findDataStructureElementPosition(*ptrToSet, element);

	T_ptrNode ptrPreviousElement;
	T_ptrNode ptrNewElement = (struct node*) malloc(sizeof(struct node));
	ptrNewElement->data = element;

	if (*ptrToSet == NULL)
	{
		ptrNewElement->ptrNext = NULL;
		*ptrToSet = ptrNewElement;
	}
	else
	{
		if (foundPosition >= 0)
		{
			operationResult = 0;
		}
		else if (foundPosition == -1)
		{
			ptrPreviousElement = *ptrToSet;

			while (ptrPreviousElement->ptrNext != NULL)
			{
				ptrPreviousElement = ptrPreviousElement->ptrNext;
			}

			ptrNewElement->ptrNext = ptrPreviousElement->ptrNext;
			ptrPreviousElement->ptrNext = ptrNewElement;
		}
	}

	return operationResult;
}

