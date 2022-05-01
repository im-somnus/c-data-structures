/* priorityQueue.c
 *
 *  Created on: 31 Mar 2022
 *  Author: somnus  */

#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"

// Insert an element by priority order (higher > first)
// 		returns 0 if operation failed
// 		returns 1 if operation success
int insertPriorityQueue(T_ptrNode *ptrToPQueue, int priority)
{
	int operationResult = 0;
	T_ptrNode ptrNewElement = allocateMemoryForNewNode();

	if (ptrNewElement != NULL)
	{
		ptrNewElement->data = priority;

		if (*ptrToPQueue == NULL)
		{
			ptrNewElement->ptrNext = NULL;
			*ptrToPQueue = ptrNewElement;
		}
		else
		{
			if (ptrNewElement->data > (*ptrToPQueue)->data)
			{
				ptrNewElement->ptrNext = (*ptrToPQueue);
				*ptrToPQueue = ptrNewElement;
			}
			else
			{
				T_ptrNode ptrCurrentElement = *ptrToPQueue;

				while ( (ptrCurrentElement->ptrNext != NULL)
								&& (ptrNewElement->data <= ptrCurrentElement->ptrNext->data))
				{
					ptrCurrentElement = ptrCurrentElement->ptrNext;
				}

				ptrNewElement->ptrNext = ptrCurrentElement->ptrNext;
				ptrCurrentElement->ptrNext = ptrNewElement;
			}
		}

		operationResult = 1;
	}
	return operationResult;
}

// Removes the first element (pop) from the queue
// 		returns 0 if operation failed
// 		returns 1 if operation success
int dePQueue(T_ptrNode *ptrToQueue)
{
	int operationResult = 0;

	if (*ptrToQueue != NULL)
	{
		T_ptrNode ptrAux = *ptrToQueue;
		*ptrToQueue = ptrAux->ptrNext;
		free(ptrAux);

		operationResult = 1;
	}

	return operationResult;
}
