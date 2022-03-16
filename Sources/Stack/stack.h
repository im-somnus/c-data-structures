/*  stack.h
 *
 *  Created on: 16 Mar 2022
 *  Author: somnus */

#ifndef HEADERS_STACK_H_
#define HEADERS_STACK_H_
#include "../Node/node.h"

void push(T_ptrNode *ptrHead, int element);
void pop(T_ptrNode *ptrHead);
void peek(T_ptrNode ptrHead);
void printStack(T_ptrNode ptrHead);

#endif
