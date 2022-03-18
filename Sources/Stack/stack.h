/*  stack.h
 *
 *  Created on: 16 Mar 2022
 *  Author: somnus */

#ifndef HEADERS_STACK_H_
#define HEADERS_STACK_H_
#include "../Node/node.h"

int push(T_ptrNode *ptrHead, int element);
int pop(T_ptrNode *ptrHead);
int peek(T_ptrNode ptrHead);

#endif
