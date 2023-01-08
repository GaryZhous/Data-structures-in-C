#ifndef _LIST_H
#define _LIST_H
//header protector let's gooo
#include <stdio.h>
#include <stdlib.h>
typedef struct node{ //define the structure of a... node in a double linked list
    int data;
    struct node* next;
    struct node* prev;
}node_t;

typedef struct list{ // define the structure of a double linked list
    struct node head;
    struct node tail;
}list_t;


extern void list_init(list_t* list);
extern int list_empty(list_t* list);

extern int list_size(list_t* list);

extern void list_add(list_t* list, int data);

extern void list_add_head(list_t* list, int data);

extern void list_add_last(list_t* list, int data);

extern void list_del(list_t* list, int data);

extern void list_del_head(list_t* list);

extern void list_del_tail(list_t* list);

extern int list_get(list_t* list, int index);

extern void list_deinit(list_t* list);
#endif
void list_init(list_t* list){ //initialize a double linked list
    //the head node
    list->head.next = &list->tail;
    list->head.prev = NULL;
    list->head.data = 0;
    //and the tail
    list->tail.prev = &list->head;
    list->tail.next = NULL;
    list->tail.data = 0;
}

//to see if the list is empty
int list_empty(list_t* list){
    return list->head.next == &list->tail; //if it is empty a 0 shall be returned
}

//find the number of effective nodes
int list_size(list_t* list){
    int count = 0;//count records the number of nodes
    for(node_t* pnode = &list->head; pnode != &list->tail; pnode = pnode->next){
        //create three signs
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        if(pmid != &list->tail)
            count++;//count++
    }
    return count;
}

//create a new node
static node_t* create_node(int data){
    node_t* pnew = malloc(sizeof(node_t));
    pnew->data = data;
    pnew->next = NULL;
    pnew->prev = NULL;
    return pnew;
}

//function to insert a node
void insert_node(node_t* pfirst, node_t* pmid, node_t* pnew){
    pfirst->next = pnew;
    pnew->prev = pfirst;

    pnew->next = pmid;
    pmid->prev = pnew;
}

//create a node in order of number(ascending or descending)
void list_add(list_t* list, int data){
    node_t* pnew = create_node(data);
    for(node_t* pnode = &list->head; pnode != &list->tail; pnode = pnode->next){
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        if(pmid->data > pnew->data || pmid == &list->tail){
            insert_node(pfirst, pmid, pnew);
            break;
        }
    }
}

//create a node between the head node and the first effective node of the list
void list_add_head(list_t* list, int data){
    node_t* pnew = create_node(data);
    node_t* pfirst = &list->head;
    node_t* pmid = pfirst->next;
    node_t* plast = pmid->next;
    //insert pnew between pfirst and pmid
    insert_node(pfirst, pmid, pnew);
}

//create a node between the tail node and the last effective node of the list
void list_add_last(list_t* list, int data){
    node_t* pnew = create_node(data);
    node_t* pfirst = list->tail.prev;//points to the last effective node
    node_t* pmid = pfirst->next;//pmid points to the tail node
    node_t* plast = pmid->next;
    insert_node(pfirst, pmid, pnew);
}

//delete the node pmid points to
static void del_node(node_t* pfirst, node_t* pmid, node_t* plast){
    pfirst->next = plast;
    plast->prev = pfirst;
    free(pmid);//free malloc()
}
//delete the appointed node
void list_del(list_t* list, int data){
    for(node_t* pnode = &list->head; pnode != &list->tail; pnode = pnode->next){
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        if(pmid->data == data && pmid != &list->tail){
            del_node(pfirst, pmid, plast);
        }
    }    
}
//delete the first effective node
void list_del_head(list_t* list){
    //check if the list is empty
    if(list_empty(list)){
        printf("it is an empty list\n");
        return;
    }
    node_t* pfirst = &list->head;
    node_t* pmid = pfirst->next;
    node_t* plast = pmid->next;
    //delete the node pmid points to
    del_node(pfirst, pmid, plast);
}
//delete the last effective node
void list_del_tail(list_t* list){
    //check if the lsit is empty
    if(list_empty(list)){
        printf("it is an empty list\n");
        return;
    }
    
    node_t* plast = &list->tail;//plast points to the tail node
    node_t* pmid = plast->prev;//pmid points to the last effective node (last effective node->tail node)
    node_t* pfirst = pmid->prev;//pfirst point to the node before the last effective node
    //delete the node pmid points to
    del_node(pfirst, pmid, plast);

}

//retreive value stored in the node with certain index
//index = 5, example
int list_get(list_t* list, int index){
    int count = 0;
    for(node_t* pnode = &list->head; pnode != &list->tail; pnode = pnode->next){
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        if(count == index && pmid != &list->tail)
            return pmid->data;
        count++;
    }
}
//free the double linked list
void list_deinit(list_t* list){
    while(list->head.next != &list->tail){
        node_t* pfirst = &list->head;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        del_node(pfirst, pmid, plast);
    }
}
