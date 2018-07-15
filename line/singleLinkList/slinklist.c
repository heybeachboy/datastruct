#include <stdio.h>
#include <malloc.h>
#include "slinklist.h"
/**
 * c langauge for single link list 
 *
 */
static Node head;

static Node init_node(void * v)
{
    Node p;
    p = (Node)malloc(sizeof(struct node));
    if(!p) return NULL;
    p->val = v;  
    return p;    
}	


int init_single_link(void * v)
{
    	
    head = init_node(v);
    head->next = NULL;
    return -1;    

}

int free_single_link()
{
   Node p = head;
   
   while(p != NULL)
   {
       Node q;
       q = p;
       p = p->next;
       free(q); 
   }
   head = NULL;
   return 0;    

}

int slink_is_empty()
{
    if(head == NULL)
    {
        return 0;
    }	    
    
    return -1;
}

int slink_size()
{
    int count = 0;	
    Node p = head;
    while(p != NULL)
    {
        count++;
	p = p->next;
    }
    
    return count;    

}

Node slink_get_index(int index)
{
    int count = 0;	
    Node p = head;

    while(p != NULL)
    {   
	count++;    
        if(count == index) return p;
        p = p->next;	
    }
    printf("overflower max index \n");
    return;    

}

Node slink_get_first()
{
   return head;
}

Node slink_get_last()
{
    Node p = head;

    while(p != NULL)
    {
        p = p->next;
    }

    return p;     
}

int slink_insert(int index,void *val)
{
    int count = 1;
    Node p,q;
    p = head;
    q = init_node(val);

    while(p != NULL)
    {
         count++;
	 if(count == index)
         {
             Node temp = p->next;
	     p->next = q;
	     q->next = temp;
	     return 0;

         }
         p = p->next;	 
	 
        }	    
     p->next = q;
     q->next = NULL;
     return 0;    

    
}

int slink_insert_head(void * val)
{
    Node p = init_node(val);
    p->next = head;
    head = p;
    return 0;
}

int slink_insert_tail(void * val)
{
    Node p = head;
    Node q = init_node(val);

    while(p != NULL)
    {
        p = p->next; 
    }

    p->next = q;
    q->next = NULL;
    return 0;

}

int slink_delete(int index)
{
    Node p,q;
    p = head;
    int count = 1;

    if(index == 1)
    {
	slink_delete_first();    
        return 0;	
    }	    

    while(p != NULL) 
    {
        count++;
        if(count == index)
	{
            q = p->next;
	    p->next = q->next;
            free(q);
            return 0;	    
	}	

    }
    q->next = NULL;
    free(p);
    return 0;
}

int slink_delete_first()
{
    Node p = head;
    head = p->next;
    free(p);
}

int slink_delete_tail()
{
    Node p,q;
    p = head;
    while(p != NULL)
    {
    q = p;
    p = p->next;
    }
    free(p);
    q->next = NULL;
    return 0;    
        
}	








