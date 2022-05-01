/*  stack.c
 *
 *  Created on: 16 Mar 2022
 *  Author: somnus */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Inserts an element in the stack
// 		returns 0 if operation fail
// 		returns 1 if operation success
int push(T_ptrNode *ptrHead, int element)
{
	int operationResult = 0;
	T_ptrNode ptrNewElem = allocateMemoryForNewNode();

	if (ptrNewElem != NULL)
	{
		ptrNewElem->data = element;
		ptrNewElem->ptrNext = *ptrHead;
		*ptrHead = ptrNewElem;

		operationResult = 1;
	}

	return operationResult;
}

// Removes the last inserted element from the stack
// 		returns 0 if operation fail
//		returns 1 if operation success
int pop(T_ptrNode *ptrHead)
{
	int operationResult = 0;

	if (*ptrHead != NULL)
	{
		T_ptrNode ptrTemp = *ptrHead;
		*ptrHead = (*ptrHead)->ptrNext;
		free(ptrTemp);

		operationResult = 1;
	}

	return operationResult;
}

// Return last inserted element from the start
// If stack is empty:
// 		prints an error message and returns -1
int peek(T_ptrNode ptrHead)
{
	if (ptrHead == NULL)
	{
		printf("ERROR: empty data stack ");
	}

	return ptrHead != NULL ? ptrHead->data : -1;
}
