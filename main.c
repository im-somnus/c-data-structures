/*  main.c
 *
 *  Created on: 16 Mar 2022
 *  Author: somnus */

#include <stdio.h>
#include <stdlib.h>

/* #include "./Sources/Dictionary/dictionary.h"
 #include "./Sources/Heap/heap.h"
 #include "./Sources/Linked List/Doubly Linked List/doublyLinkedList.h"
 #include "./Sources/Linked List/Singly Linked List/SinglyLinkedList.h" */

#include "./Sources/Ordered List/orderedList.h"
#include "./Sources/Set/set.h"
#include "./Sources/Stack/stack.h"
#include "./Sources/Queue/queue.h"
#include "./Sources/Queue/Priority Queue/priorityQueue.h"
#include "./Sources/Trees/tree.h"

int main()
{
	T_ptrTreeNode n1 = createTreeNode(1);
	T_ptrTreeNode n2 = createTreeNode(2);
	T_ptrTreeNode n3 = createTreeNode(3);
	T_ptrTreeNode n4 = createTreeNode(4);
	T_ptrTreeNode n5 = createTreeNode(5);
	T_ptrTreeNode n6 = createTreeNode(6);
	T_ptrTreeNode n7 = createTreeNode(7);

	n1->childLeft = n2;
	n1->childRight = n3;

	n2->childLeft = n4;
	n2->childRight = n5;

	n3->childLeft = n6;
	n3->childRight = n7;

	printTree(n1);

	printf("Priority Queues: \n");
	T_ptrNode pqueue = init();

	insertPriorityQueue(&pqueue, 1);
	insertPriorityQueue(&pqueue, 2);
	insertPriorityQueue(&pqueue, 5);
	insertPriorityQueue(&pqueue, 3);
	insertPriorityQueue(&pqueue, 4);
	insertPriorityQueue(&pqueue, 4);

	printf("\tPrinting data structure: \t");
	printDataStructure(pqueue);


	dePQueue(&pqueue);
	printf("\tDequeing..\n");
	printf("\tPrinting data structure: \t");
	printDataStructure(pqueue);

	printf("\n");

	printf("Queues: \n\t");
	T_ptrNode queue = init();
	int d = enqueue(&queue, 1);
	enqueue(&queue, 2);
	enqueue(&queue, 3);
	enqueue(&queue, 4);
	enqueue(&queue, 6);
	enqueue(&queue, 0);
	dequeue(&queue);

	printf("\tPrinting data structure: ");
	if (d)
	{
		printDataStructure(queue);
	}
	else
	{
		printDataStructure(queue);
	}
	printf("\n");

	// Sets
	printf("Sets: \n");
	T_ptrNode mySet = init();
	insertElementInSet(&mySet, 87);
	insertElementInSet(&mySet, 6);
	insertElementInSet(&mySet, 6);
	insertElementInSet(&mySet, 7);
	insertElementInSet(&mySet, 3);

	removeElementFromDataStructure(&mySet, 3);

	printf("\tMy Set:		");
	printDataStructure(mySet);
	destroyDataStructure(&mySet);
	insertElementInSet(&mySet, 87);
	insertElementInSet(&mySet, 6);
	insertElementInSet(&mySet, 2);
	insertElementInSet(&mySet, 4);

	printf("\tMy new set: 	");
	printDataStructure(mySet);

	int isEmpty = dataStructureIsEmpty(mySet);

	if (isEmpty)
	{
		printf("\tMy set is empty, like my heart\n");
	}
	else
	{
		printf("\tMy set is not empty\n");
	}

	int setSize = getDataStructureSize(mySet);
	printf("\tMy set Size: \n   \t\t%d elements\n", setSize);

	int destroyedSetOk = destroyDataStructure(&mySet);

	if (destroyedSetOk >= 0)
	{
		printf("\tSuccessfully destroyed the data structure.\n");
	}
	else if (destroyedSetOk == -1)
	{
		printf("\t!ERROR: couldn't destroy the data structure.\n");
	}

	printDataStructure(mySet);

	T_ptrNode setA = init();
	insertElementInSet(&setA, 1);
	insertElementInSet(&setA, 2);
	insertElementInSet(&setA, 3);

	T_ptrNode setB = init();
	insertElementInSet(&setB, 1);
	insertElementInSet(&setB, 2);
	insertElementInSet(&setB, 5);
	insertElementInSet(&setB, 4);


	printf("\tSet A:                  	");
	printDataStructure(setA);
	printf("\tSet B:                 	 	");
	printDataStructure(setB);

	T_ptrNode setUnionAB = setUnion(setA, setB);
	printf("\tSet union AB:           	");
	printDataStructure(setUnionAB);

	printf("\tSet intersection AB:   		");
	T_ptrNode setIntersectionAB = intersection(setA, setB);
	printDataStructure(setIntersectionAB);

	printf("\tSet difference AB:      	");
	T_ptrNode setDiffAB = difference(setA, setB);
	printDataStructure(setDiffAB);

	int isSet1ASubsetOf2 = setAIsSubsetOfSetB(setA, setB);

	if (isSet1ASubsetOf2)
	{
		printf("\t\tSet A is a subset of B");
	}
	else
	{
		printf("\t\tSet A is NOT a subset of B\n");
	}

	// OrderedList data structure
	printf("Ordered Lists: \n");
	T_ptrNode myOrderedList = init();
	insertOrdListElement(&myOrderedList, 1);
	insertOrdListElement(&myOrderedList, 12);
	insertOrdListElement(&myOrderedList, 0);
	insertOrdListElement(&myOrderedList, 234);
	insertOrdListElement(&myOrderedList, 636);
	insertOrdListElement(&myOrderedList, 651);
	insertOrdListElement(&myOrderedList, 231);

	printf("\tMy list:     ");
	printDataStructure(myOrderedList);
	int removedOk = removeElementFromDataStructure(&myOrderedList, 231);

	if (removedOk >= 0)
	{
		printf("\tSuccessfully removed the element.\n");
	}
	else if (removedOk == -1)
	{
		printf("\t!ERROR: couldn't remove that element.\n");
	}
	printf("\tMy new list: ");
	printDataStructure(myOrderedList);

	int destroyedStackOk = destroyDataStructure(&myOrderedList);

	if (destroyedStackOk >= 0)
	{
		printf("\tSuccessfully destroyed the data structure.\n");
	}
	else if (destroyedStackOk == -1)
	{
		printf("\t!ERROR: couldn't destroy the data structure.\n");
	}

	printf("\tMy destroyed list: ");
	printDataStructure(myOrderedList);
	printf("\n");

	// Stack data structure
	printf("Stack: \n");

	T_ptrNode myStack = init();

	push(&myStack, 2);
	push(&myStack, 1);
	push(&myStack, 2);

	int tam = getDataStructureSize(myStack);
	printf("\tData structure size:\n   \t\t%d elements\n", tam);

	printf("\tMy stack: ");
	printDataStructure(myStack);

	int destroyOk = destroyDataStructure(&myStack);

	if (destroyOk >= 0)
	{
		printf("\tSuccessfully destroyed the data structure.\n");
	}
	else if (destroyOk == -1)
	{
		printf("\t!ERROR: couldn't destroy the data structure.\n");
	}

	printf("\tMy new stack: ");
	printDataStructure(myStack);

	exit(1);
}
