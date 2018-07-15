#include <stdio.h>
#include <string.h>
#include "slinklist.h"

typedef struct value {
        int id;
	char var[2]; 

}*Val;

int main() {
    int arr[4] = {11,22,33,44};    	
    init_single_link(&arr[0]);
    slink_insert(2,&arr[1]);
    slink_insert(3,&arr[2]);
    slink_insert(4,&arr[3]);
}    
