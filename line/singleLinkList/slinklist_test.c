#include <stdio.h>
#include <string.h>
#include "slinklist.h"

int main() {
    Node h;	
    int arr[4] = {11111,22,33,44};
    int *v1 = 3333;
    int *v2 = 566;    
    init_single_link(&arr[3]);
    h = slink_get_first();
    slink_insert(2,v1);
    slink_insert(3,v2);
    h = slink_get_index(3);
    printf("this first value:%d\n",h->val);
}    
