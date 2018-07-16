/*
 *@Auth beachboy
 *@Date 2017/10/12
 *
 */

#ifndef _STACK_H

#define _STACK_H
typedef struct Element {
	int id;
	char *name[];
}*pEle,Ele;

//create a data stack; result success : 0;failed : -1
extern int InitStack(int size);

//add element to stack; successfull return 0 failed return -1
extern int Push(pEle e);
//delete element from stack; successfull return 0; failed returnn -1
extern int Pop(int id);

//rerturn stack element
extern pEle Peek();

//get stack element total member
extern int Size();

#endif
