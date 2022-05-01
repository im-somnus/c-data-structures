/* orderedList.c
 *
 *  Created on: 16 Mar 2022
 *  Author: somnus  */

#include <stdio.h>
#include <stdlib.h>
#include "orderedList.h"

// Insert an element in its ordered position inside the ordered list
// 		returns 0 if operation failed
// 		returns 1 if operation success
int insertOrdListElement(T_ptrNode *ptrToList, int element)
{
	int operationResult = 0;
	T_ptrNode ptrNewElement = allocateMemoryForNewNode();

	if (ptrNewElement != NULL)
	{
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
				T_ptrNode ptrPreviousElement;
				ptrPreviousElement = *ptrToList;

				while ((ptrPreviousElement->ptrNext != NULL) &&
						(ptrNewElement->data > ptrPreviousElement->ptrNext->data))
				{
					ptrPreviousElement = ptrPreviousElement->ptrNext;
				}

				ptrNewElement->ptrNext = ptrPreviousElement->ptrNext;
				ptrPreviousElement->ptrNext = ptrNewElement;
			}
		}

		operationResult = 1;
	}

	return operationResult;
}

