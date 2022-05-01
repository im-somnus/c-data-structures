/*  set.c
 *
 *  Created on: 16 Mar 2022
 *  Author: somnus */

#include <stdio.h>
#include <stdlib.h>
#include "../Set/set.h"

// Insert element in the set
//		returns 0 if operation fails
// 		returns 1 if operation success
int insertElementInSet(T_ptrNode *ptrToSet, int element)
{
	int operationResult = 0;

	if (!elementExistsInDataStructure(*ptrToSet, element))
	{
		T_ptrNode ptrNewElement = allocateMemoryForNewNode();

		if (ptrNewElement != NULL)
		{
			ptrNewElement->data = element;

			if (*ptrToSet == NULL)
			{
				ptrNewElement->ptrNext = NULL;
				*ptrToSet = ptrNewElement;
			}
			else
			{
				T_ptrNode ptrCurrent = *ptrToSet;

				while (ptrCurrent->ptrNext != NULL)
				{
					ptrCurrent = ptrCurrent->ptrNext;
				}

				ptrNewElement->ptrNext = ptrCurrent->ptrNext;
				ptrCurrent->ptrNext = ptrNewElement;
			}

			operationResult = 1;
		}
	}

	return operationResult;
}

void copyToTargetSetFromOriginSet(T_ptrNode *ptrToSetA, T_ptrNode ptrToSetB)
{
	T_ptrNode ptrTemp = *ptrToSetA;

	while (ptrToSetB != NULL)
	{
		insertElementInSet(&ptrTemp, ptrToSetB->data);
		ptrToSetB = ptrToSetB->ptrNext;
	}

	*ptrToSetA = ptrTemp;
}

// Returns a Set containing the union of both Sets
T_ptrNode setUnion(T_ptrNode ptrToSetA, T_ptrNode ptrToSetB)
{
	T_ptrNode ptrToUnion = NULL;

	copyToTargetSetFromOriginSet(&ptrToUnion, ptrToSetA);
	copyToTargetSetFromOriginSet(&ptrToUnion, ptrToSetB);

	return ptrToUnion;
}

// Returns a Set containing the intersection of both Sets
T_ptrNode intersection(T_ptrNode ptrToSet1, T_ptrNode ptrToSet2)
{
	T_ptrNode ptrIntersection = NULL;

	while (ptrToSet1 != NULL)
	{
		if (elementExistsInDataStructure(ptrToSet2, ptrToSet1->data))
		{
			insertElementInSet(&ptrIntersection, ptrToSet1->data);
		}

		ptrToSet1 = ptrToSet1->ptrNext;
	}

	return ptrIntersection;
}

//  Returns a Set containing the difference of both Sets
T_ptrNode difference(T_ptrNode ptrToSet1, T_ptrNode ptrToSet2)
{
	T_ptrNode ptrDifference = NULL;

	while (ptrToSet1 != NULL)
	{
		if (!elementExistsInDataStructure(ptrToSet2, ptrToSet1->data))
		{
			insertElementInSet(&ptrDifference, ptrToSet1->data);
		}

		ptrToSet1 = ptrToSet1->ptrNext;
	}

	return ptrDifference;
}

// Checks if Set A is subset of Set B
//		returns 1 if true
// 		returns 0 if false
int setAIsSubsetOfSetB(T_ptrNode ptrToSet1, T_ptrNode ptrToSet2)
{
	int operationResult = 0,
		set1Size = getDataStructureSize(ptrToSet1),
		set2Size = getDataStructureSize(ptrToSet2);

	if (set1Size == 0 && set2Size == 0)
	{
		operationResult = 1;
	}
	else
	{
		int numElements = 0;

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
