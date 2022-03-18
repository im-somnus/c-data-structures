/*  main.c
 *
 *  Created on: 16 Mar 2022
 *  Author: somnus */

#include <stdio.h>
#include <stdlib.h>

/* #include "./Sources/Dictionary/dictionary.h"
 #include "./Sources/Heap/heap.h"
 #include "./Sources/Linked List/Doubly Linked List/doublyLinkedList.h"
 #include "./Sources/Linked List/Singly Linked List/SinglyLinkedList.h"
 #include "./Sources/Priority Queue/priorityQueue.h"
 #include "./Sources/Queue/queue.h"
 #include "./Sources/Search Tree/searchTree.h" */

#include "./Sources/Ordered List/orderedList.h"
#include "./Sources/Set/set.h"
#include "./Sources/Stack/stack.h"

int main()
{
	// Sets
	printf("Sets: \n");
	T_ptrNode mySet = create();
	printDataStructure(mySet);
	insertElementInSet(&mySet, 87);
	insertElementInSet(&mySet, 6);
	insertElementInSet(&mySet, 6);

	printDataStructure(mySet);
	destroyDataStructure(&mySet);

	insertElementInSet(&mySet, 2);
	insertElementInSet(&mySet, 4);

	printDataStructure(mySet);

	int isEmpty = dataStructureIsEmpty(mySet);

	if (isEmpty)
	{
		printf("My set is empty, like my heart\n");
	}
	else
	{
		printf("My set is not empty\n");
	}

	int setSize = getDataStructureSize(mySet);
	printf("My set Size: \n   %d elements\n", setSize);

	int destroyedSetOk = destroyDataStructure(&mySet);

	if (destroyedSetOk >= 0)
	{
		printf("Successfully destroyed the data structure.\n");
	}
	else if (destroyedSetOk == -1)
	{
		printf("!ERROR: couldn't destroy the data structure.\n");
	}

	printDataStructure(mySet);

	printf("\n");

	// OrderedList data structure
	printf("Ordered Lists: \n");
	T_ptrNode myOrderedList = create();
	insertOrdListElement(&myOrderedList, 1);
	insertOrdListElement(&myOrderedList, 12);
	insertOrdListElement(&myOrderedList, 0);
	insertOrdListElement(&myOrderedList, 234);
	insertOrdListElement(&myOrderedList, 636);
	insertOrdListElement(&myOrderedList, 651);
	insertOrdListElement(&myOrderedList, 231);

	printDataStructure(myOrderedList);

	int removedOk = removeOrdListElement(&myOrderedList, 231);

	if (removedOk >= 0)
	{
		printf("Successfully removed the element.\n");
	}
	else if (removedOk == -1)
	{
		printf("!ERROR: couldn't remove that element.\n");
	}

	printDataStructure(myOrderedList);

	int destroyedStackOk = destroyDataStructure(&myOrderedList);

	if (destroyedStackOk >= 0)
	{
		printf("Successfully destroyed the data structure.\n");
	}
	else if (destroyedStackOk == -1)
	{
		printf("!ERROR: couldn't destroy the data structure.\n");
	}

	printDataStructure(myOrderedList);
	printf("\n");

	// Stack data structure
	printf("Stack: \n");
	T_ptrNode myStack = create();
	push(&myStack, 2);
	push(&myStack, 1);
	push(&myStack, 2);
	int tam = getDataStructureSize(myStack);
	printf("Data structure size:\n   %d elements\n", tam);

	// printStack can also be used for a more custom output.
	// printStack(myStack);
	printDataStructure(myStack);

	int destroyOk = destroyDataStructure(&myStack);

	if (destroyOk >= 0)
	{
		printf("Successfully destroyed the data structure.\n");
	}
	else if (destroyOk == -1)
	{
		printf("!ERROR: couldn't destroy the data structure.\n");
	}

	printDataStructure(myStack);
	printf("\n");

	exit(1);
}
