/**
 *@Auth beachboy
 *@Date 2017/07/14
 *
 */
#include <stdio.h>
#include <malloc.h>
#include "dlinklist.h"

static pNode head;

static pNode createNode(void * val)
{
    pNode p;
    p = (pNode)malloc(sizeof(Node));
    
    if(!p) {
        printf("memory malloc failed\n");
	return NULL;
    }
    p->val = val;
    return p;    
  
}	

int InitHeadNode(void * val)
{
    head = createNode(val);

    if(head == NULL) return -1;
    head->prev = NULL;
    head->next = NULL; 
    return 0;   

}

int ClearDoubleLinkList()
{
    pNode p,q;
    p = head;

    while(p->next != NULL)
    {
        q = p;
        free(q);
	p = p->next;
    }

    head = NULL;
    return 0;    

}

int AppendElement(int postion, void * val)
{
    if(Size() < postion) {
         return -1;  
     }	    
    int count = 1;
    pNode p,q,j;
    p = head;


    if(postion == 0 || postion == 1)
    {
     AppendElementToHead(val);
     return 0;     
    }	    

    j = createNode(val);

    while(p != NULL)
    {
        count++;
        if(count == postion)
	{
	    pNode temp;
            temp = p->next;
            temp->prev = j;	    
            p->next = j;
	    j->prev = p;
	    j->next = temp;
	    return 0; 
              	    
        }
        p = p->next;	
            
    }

    p->next = j;
    j->prev = p;
    return 0;    
}

int AppendElementToHead(void * val)
{
    pNode p,q;
    p = head;
    q = createNode(val);
    p->prev = q;
    q->next = p;
    head = q;
    return 0;    
}

int AppendElementToTail(void * val)
{
    pNode p,q;
    p = head;

    while(p != NULL)
    {
        p = p->next;
    }

    q = createNode(val);
    p->next = q;
    q->prev = p;
    return 0;       
}

int RemoveElement(int postion)
{
    pNode p;
    int count = 0;
    p = head;

    if(postion == 0 || postion == 1) {
        RemoveElementAtFirst();
	return 0; 
    }	    

    while(p != NULL)
    {
        count++;
	if(count == postion)
        {
            free(p);
	    return 0;    
        }
        p = p->next;	
	 
    }

    return -1;       
}	

int RemoveElementAtFirst()
{
    pNode p,q;
    q = head;
    p = head->next;
    p->prev = NULL;
    head = p;
    free(q);
    return 0;
}

int RemoveElementAtLast()
{
    pNode p,q;
    p = head;
    
    while(p != NULL) p = p->next;
    q = p->prev;
    q = next = NULL;
    free(p);
    return 0;
}

int IsEmptyList()
{
    	
    if(head != NULL){
     return 0;
    }
    return -1;
}

int Size()
{
    pNode p;
    int count = 1;
    p = head;

    while(p != NULL)
    {
        count++;
        p = p->next;	
    }

    return count;    
}	

pNode GetElementByPostion(int postion)
{
    
    if(Size() < postion) {
         return NULL;  
     }
 
     if(postion == 0 || postion == 1){
         return head;
     }
     int count = 1;
     pNode p;
     p = head;
     while(p != NULL)
     {
         count++;
	 if(count == postion) return p;
	 p = p->next;

     }

     return p;         

}

pNode GetElementAtFirst()
{
    return head; 
}	

pNode GetElementAtLast()
{
    pNode p;
    p = head;

    while(p != NULL) p = p->next;

    return p;

}	
