/**
 * 
 *@Auth beachboy
 *@Date 2017/08/24
 *
 */
#ifndef _DOUBLE_LINK_LIST_H

#define _DOUBLE_LINK_LIST_H

typedef struct dnode {
	dnode * prev,*next;
	void * val;
}*pNode,Node;

//init double link list head node success 0 failed -1
extern int InitHeadNode(void * val); 

//clear double link list all node; success 0 failed -1
extern int ClearDoubleLinkList();

//append element to double link list result: success 0 failed -1
extern int AppendElement(int postion,void * val);

//append element to double link list to head result : success 0 failed -1
extern int AppendElementToHead(void * val);

//append element to double link list to tail; result : success 0 failed -1
extern int AppendElementToTail(void * val);

//remove element from double link list result : success 0 failed -1
extern int RemoveElement(int postion);

//remove element of double link list at first;result 0 failed -1
extern int RemoveElementAtFirst();

//remove element of double link list at last; result 0 failed -1
extern int RemoveElementAtLast();

//judge double link list is empty
extern int IsEmptyList();

//get double link list size
extern int Size();

//get double link list by postion
extern pNode GetElementByPostion(int postion);

//get double link list at first
extern pNode GetElementAtFirst();

//get double link list at last
extern pNode GetElementAtLast();

#endif
