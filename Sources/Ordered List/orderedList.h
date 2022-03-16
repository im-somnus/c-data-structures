/* orderedList.h
 *
 *  Created on: 15 Mar 2022
 *  Author: somnus  */

#ifndef ORDERED_LIST_ORDEREDLIST_H_
#define ORDERED_LIST_ORDEREDLIST_H_
#include "../Node/node.h"

// commented in case the node search function
// doesnt work like i want and i have to revert.
//int searchOrdListElement(T_ptrNode ptrToList, int element);

int insertOrdListElement(T_ptrNode *ptrToList, int element);
int removeOrdListElement(T_ptrNode *ptrToList, int element);



#endif
