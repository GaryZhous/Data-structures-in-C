#ifndef _list_H
#define _list_H
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
  int data;
  struct node* next;
}node_t;

typedef struct list{
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


static node_t* create_node(int data){
    node_t* pnew = malloc(sizeof(node_t));
    pnew->data = data;
    pnew->next = NULL;
    return pnew;
}


void list_init(list_t* list){
    
    list->head = create_node(0);
    
    list->tail = create_node(0);
    
    list->head->next = list->tail;
    list->tail->next = NULL;
}


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


void list_add_first(list_t* list, int data){
  
    node_t* pnew = create_node(data);
    node_t* ptmp = list->head->next;
    list->head->next = pnew;
    pnew->next = ptmp; 
}

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


void list_deinit(list_t* list){
    node_t* pnode = list->head;
    while(pnode){//pnode != NULL
        node_t* ptmp = pnode->next;
        free(pnode); 
        pnode = ptmp;
    }
}
