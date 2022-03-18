/*  set.h
 *
 *  Created on: 16 Mar 2022
 *  Author: somnus */

#ifndef SET_SET_H_
#define SET_SET_H_
#include "../Node/node.h"

int insertElementInSet(T_ptrNode *ptrToSet, int element);
T_ptrNode setUnion(T_ptrNode ptrToSet1, T_ptrNode ptrToSet2);
T_ptrNode intersection(T_ptrNode ptrToSet1, T_ptrNode ptrToSet2);
T_ptrNode difference(T_ptrNode ptrToSet1, T_ptrNode ptrToSet2);
int subset(T_ptrNode ptrToSet1, T_ptrNode ptrToSet2);

#endif
