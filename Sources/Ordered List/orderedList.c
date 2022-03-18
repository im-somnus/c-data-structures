/* orderedList.c
 *
 *  Created on: 16 Mar 2022
 *  Author: somnus  */

#include <stdio.h>
#include <stdlib.h>
#include "orderedList.h"

// Insert an element in its ordered position inside the ordered list
// returns 0 if operation failed
// returns 1 if operation success
int insertOrdListElement(T_ptrNode *ptrToList, int element)
{
	int operationResult = 0;

	T_ptrNode ptrPreviousElement;
	T_ptrNode ptrNewElement = (struct node*) malloc(sizeof(struct node));
	ptrNewElement->data = element;

	if (*ptrToList == NULL)
	{
		ptrNewElement->ptrNext = NULL;
		*ptrToList = ptrNewElement;
	}
	else
	{
		if (ptrNewElement->data <= (*ptrToList)->data)
		{
			ptrNewElement->ptrNext = (*ptrToList);
			*ptrToList = ptrNewElement;
		}
		else
		{

			ptrPreviousElement = *ptrToList;

			while ((ptrPreviousElement->ptrNext != NULL)
					&& (ptrNewElement->data > ptrPreviousElement->ptrNext->data))
			{
				ptrPreviousElement = ptrPreviousElement->ptrNext;
			}

			ptrNewElement->ptrNext = ptrPreviousElement->ptrNext;
			ptrPreviousElement->ptrNext = ptrNewElement;
		}
	}

	operationResult = 1;
	return operationResult;
}

// Deletes the first occurrence of the element passed as parameter
// returns 0 if operation failed
// returns 1 if operation success
int removeOrdListElement(T_ptrNode *ptrToList, int element)
{
	int operationResult = 0;

	if (*ptrToList != NULL && (*ptrToList)->data == element)
	{
		T_ptrNode ptrTemp = *ptrToList;
		*ptrToList = (*ptrToList)->ptrNext;
		free(ptrTemp);
	}
	else
	{
		T_ptrNode ptrPreviousElement;
		T_ptrNode ptrCurrent = (*ptrToList);

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
	return operationResult;
}
