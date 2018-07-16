/**
 *@Auth beachboy 
 *@Date 2018/07/16
 */

#include <stdio.h>
#include <malloc.h>
#include "stack.h"

static int CAPACITY = 0;
static int COUNT = 0;
static pEle head;


static int freeElement(pEle e)
{
    free(e);
    return 0;
}

int InitStack(int size)
{
    CAPACITY = size;
     return 0;    
}

int Push(pEle e)
{
    if(COUNT > CAPACITY) return -1;	    
    
    if(COUNT == 0){
        head = e;
        COUNT++;
        return 0;	
    }

    pEle p;
    p = head;
    head = e;
    e->next = p;    
    COUNT++;
    return 0;
}

int Pop()
{
    if(COUNT == 0) return -1;

      pEle p;
      p = head;
    if(COUNT == 1) {
      free(p);
      head = NULL;
      COUNT = 0;
      return 0; 
    }

      head = p->next;
      free(p);
      COUNT--;
      return 0; 

}

int Size()
{
    return COUNT;
}	

pEle Peek()
{
    return head;
}	







