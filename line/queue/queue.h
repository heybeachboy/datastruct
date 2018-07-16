/**
 *@Auth beachboy
 *@Date 2018/07/16
 */
typedef struct node {
	int val;
	pNode next,prev;
}*pNode,Node;

//init queue capacity
extern int  InitQueue(int size);

//add element to queue
extern int Add(int val);
//delete queue element
extern int Pop();

//destory queue all element
extern int DestroyQueue();

//get queue of capacity
extern int Capacity();
