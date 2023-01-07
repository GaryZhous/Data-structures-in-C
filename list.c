#ifndef _list_H
#define _list_H //header protector let's goooo
#include <stdio.h>
#include <stdlib.h>
typedef struct node{ //simple definition of a node
  int data;
  struct node* next;
}node_t;

typedef struct list{ // hard thing tbh
  struct node* head;
  struct node* tail;
}list_t;

extern void list_init(list_t* list);

extern void list_travel(list_t* list);

extern void list_add(list_t* list, int data);

extern void list_add_last(list_t* list, int data);

extern void list_add_first(list_t* list, int data);

extern void list_del(list_t* list, int data);

extern void list_deinit(list_t* list);
#endif

#include "list.h"

//we create a new node
static node_t* create_node(int data){
    node_t* pnew = malloc(sizeof(node_t));
    pnew->data = data;
    pnew->next = NULL;
    return pnew;
}

//we initiate a list
void list_init(list_t* list){
    
    list->head = create_node(0);
    
    list->tail = create_node(0);
    
    list->head->next = list->tail;
    list->tail->next = NULL;
}

//similar to python we use for loop to go through the list
void list_travel(list_t* list){
    for(node_t* pnode = list->head; pnode != list->tail; pnode = pnode->next){
       
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
       
        if(pmid != list->tail)
            printf("%d ", pmid->data);
    }
    printf("\n");
}
// we add a new node with data at the end of the list
void list_add(list_t* list, int data){
    
    node_t* pnew = create_node(data);

    for(node_t* pnode = list->head; pnode != list->tail; pnode = pnode->next){
        
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        
        if(pmid->data >= pnew->data || pmid == list->tail){
            pfirst->next = pnew;
            pnew->next = pmid;
            break;
        }
    }
}

//we add a node with data between the tail and the last node
void list_add_last(list_t* list, int data){
   
    node_t* pnew = create_node(data);
  
    for(node_t* pnode = list->head; pnode != list->tail; pnode = pnode->next){
       
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        if(pmid == list->tail){
            pfirst->next = pnew;
            pnew->next = pmid;
            break;
        }
    }
}

//we add a node with data between the head and the first node
void list_add_first(list_t* list, int data){
  
    node_t* pnew = create_node(data);
    node_t* ptmp = list->head->next;
    list->head->next = pnew;
    pnew->next = ptmp; 
}
// we delete a node at the end of the list
void list_del(list_t* list, int data){
    for(node_t* pnode = list->head; pnode != list->tail; pnode = pnode->next){
       
        node_t* pfirst = pnode;
        node_t* pmid = pfirst->next;
        node_t* plast = pmid->next;
        if(pmid->data == data && pmid != list->tail){
            pfirst->next = plast;
            free(pmid);
            break;
        }
    }
    
}

//we clean the whole list using free(cuz no dangling pointers can be created)
void list_deinit(list_t* list){
    node_t* pnode = list->head;
    while(pnode){//pnode != NULL
        node_t* ptmp = pnode->next;
        free(pnode); 
        pnode = ptmp;
    }
}
