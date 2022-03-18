/*  set.c
 *
 *  Created on: 16 Mar 2022
 *  Author: somnus */

#include <stdio.h>
#include <stdlib.h>
#include "../Set/set.h"

// Insert element in the array
	// returns 0 if operation fails
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

// Returns a Set containing the union of both Sets
T_ptrNode setUnion(T_ptrNode ptrToSet1, T_ptrNode ptrToSet2)
{
	T_ptrNode ptrToUnion = NULL;

	if (ptrToSet1 != NULL && ptrToSet2 != NULL)
	{
		T_ptrNode ptrCopyToSet1 = ptrToSet1;
		T_ptrNode ptrCopyToSet2 = ptrToSet2;

		int set1Size = getDataStructureSize(ptrCopyToSet1);

		int counter = 0;
		while (ptrCopyToSet1 != NULL && counter < set1Size)
		{
			insertElementInSet(&ptrToUnion, ptrCopyToSet1->data);

			if (!elementExistsInDataStructure(ptrToUnion, ptrCopyToSet1->data))
			{
				removeElementFromDataStructure(&ptrCopyToSet2,
						ptrCopyToSet1->data);
			}

			ptrCopyToSet1 = ptrCopyToSet1->ptrNext;
			counter++;
		}

		int set2Size = getDataStructureSize(ptrCopyToSet2);

		counter = 0;
		while (ptrCopyToSet2 != NULL && counter < set2Size)
		{
			insertElementInSet(&ptrToUnion, ptrCopyToSet2->data);
			ptrCopyToSet2 = ptrCopyToSet2->ptrNext;
			counter++;
		}
	}

	return ptrToUnion;
}

// Returns a Set containing the intersection of both Sets
T_ptrNode intersection(T_ptrNode ptrToSet1, T_ptrNode ptrToSet2)
{
	T_ptrNode ptrIntersection = NULL;

	if (ptrToSet1 != NULL && ptrToSet2 != NULL)
	{
		T_ptrNode ptrCopyToSet1 = ptrToSet1;
		T_ptrNode ptrCopyToSet2 = ptrToSet2;

		int set2Size = getDataStructureSize(ptrCopyToSet2);
		int counter = 0;

		while (ptrCopyToSet2 != NULL && counter < set2Size)
		{
			if (elementExistsInDataStructure(ptrCopyToSet1,
					ptrCopyToSet2->data))
			{
				insertElementInSet(&ptrIntersection, ptrCopyToSet2->data);
			}

			counter++;
			ptrCopyToSet2 = ptrCopyToSet2->ptrNext;
		}
	}

	return ptrIntersection;
}

//  Returns a Set containing the difference of both Sets
T_ptrNode difference(T_ptrNode ptrToSet1, T_ptrNode ptrToSet2)
{
	T_ptrNode ptrDifference = NULL;

	if (ptrToSet1 != NULL && ptrToSet2 != NULL)
	{
		T_ptrNode ptrCopyToSet1 = ptrToSet1;
		T_ptrNode ptrCopyToSet2 = ptrToSet2;

		int set1Size = getDataStructureSize(ptrCopyToSet1);
		int counter = 0;

		while (ptrCopyToSet1 != NULL && counter < set1Size)
		{
			if (!elementExistsInDataStructure(ptrCopyToSet2,
					ptrCopyToSet1->data))
			{
				insertElementInSet(&ptrDifference, ptrCopyToSet1->data);
			}

			counter++;
			ptrCopyToSet1 = ptrCopyToSet1->ptrNext;
		}
	}

	return ptrDifference;
}

// Checks if Set A is subset of Set B
	//		returns 1 if true
	// 		returns 0 if false
int subset(T_ptrNode ptrToSet1, T_ptrNode ptrToSet2)
{
	int operationResult = 0;
	int set1Size = getDataStructureSize(ptrToSet1), set2Size =
			getDataStructureSize(ptrToSet2);
	int numElements = 0;

	if (ptrToSet1 != NULL && ptrToSet2 != NULL && set1Size <= set2Size)
	{

		while (ptrToSet1 != NULL)
		{
			if (elementExistsInDataStructure(ptrToSet2, ptrToSet1->data))
			{
				numElements++;
			}

			ptrToSet1 = ptrToSet1->ptrNext;
		}

		if (ptrToSet1 == NULL && numElements == set1Size)
		{
			operationResult = 1;
		}
	}

	return operationResult;
}
