typedef struct node * Node;
Node head;

struct node {
     void * val;
     Node next; 
};

//create a single link list 
extern int init_single_link();

//free a single link list
extern int free_single_link();

//judge single link list is empty
extern int slink_is_empty();

//get single link list size
extern int slink_size();


//get single link of element by index
extern Node slink_get_index(int index);

//get single link of element  first
extern Node slink_get_first();

//get single link og element last
extern Node slink_get_last();

//insert a element into single link by index success return 0 failed return -1
extern int slink_insert(int index, void *val);

//insert a element into single link at first success return 0 failed return -1
extern int slink_insert_head(void *val); 

//insert a element into single link at last success return 0 failed return -1
extern int slink_append_tail(void *val);

//delete an element from single link list by index; success 0 failed return -1
extern int  slink_delete(int index);

//delete an element from single link list at first; success 0 failed return -1
extern int slink_delete_first();

//delete an element from single link list at last; success 0 failed return -1
extern int slink_delete_last();



