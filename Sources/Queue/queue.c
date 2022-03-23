/*  queue.c
 *
 *  Created on: 23 Mar 2022
 *      Author: somnus  */

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

// Enqueues an element in the queue
	// returns 0 if operation fail
	// returns 1 if operation success
int enqueue(T_ptrNode *ptrToQueue, int element)
{
	int operationResult = 0;

	T_ptrNode ptrPreviousElement;
	T_ptrNode ptrNewElement = (struct node*) malloc(sizeof(struct node));
	ptrNewElement->data = element;

	if (*ptrToQueue == NULL)
	{
		*ptrToQueue = ptrNewElement;
		ptrNewElement->ptrNext = NULL;
	}
	else
	{
		ptrPreviousElement = *ptrToQueue;

		while (ptrPreviousElement->ptrNext != NULL)
		{
			ptrPreviousElement = ptrPreviousElement->ptrNext;
		}

		ptrNewElement->ptrNext = ptrPreviousElement->ptrNext;
		ptrPreviousElement->ptrNext = ptrNewElement;
	}

	operationResult = 1;
	return operationResult;
}

// Dequeues an element in the queue
	// returns 0 if operation fail
	// returns 1 if operation success
int dequeue(T_ptrNode *ptrToQueue)
{
	int operationResult = 0;

	if (ptrToQueue != NULL)
	{
		T_ptrNode ptrFirst = (*ptrToQueue);
		*ptrToQueue = (*ptrToQueue)->ptrNext;
		free(ptrFirst);

		operationResult = 1;
	}


    return operationResult;
}

