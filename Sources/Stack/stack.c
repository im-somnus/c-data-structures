/*  stack.c
 *
 *  Created on: 16 Mar 2022
 *  Author: somnus */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(T_ptrNode *ptrHead, int element)
{
	T_ptrNode ptrNewElem = (struct node *) malloc(sizeof(struct node));

    ptrNewElem->data = element;
    ptrNewElem->ptrNext = *ptrHead;
    *ptrHead = ptrNewElem;
}

void pop(T_ptrNode *ptrHead)
{
	T_ptrNode ptrTemp = *ptrHead;
    *ptrHead = (*ptrHead)->ptrNext;
    free(ptrTemp);
}

void peek(T_ptrNode ptrHead)
{
	printf("[%d]", ptrHead->data);
}

// printStructure can also be used.
void printStack(T_ptrNode ptrHead)
{
    printf("head-> ");
    while (ptrHead != NULL)
    {
        peek(ptrHead);
        if (ptrHead->ptrNext != NULL)
        {
        	printf("->");
        }
        ptrHead = ptrHead->ptrNext;
    }
    printf("\n");
}
