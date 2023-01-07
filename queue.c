#ifndef _QUEUE_H
#define _QUEUE_H
#include <stdio.h>
#include <stdlib.h>//malloc
//define type
typedef struct queue{
    int* arr;
    int cap;
    int size;
    int rear;
    int front;
}queue_t;
extern void queue_init(queue_t* queue, int cap);//initialize queue
extern void queue_deinit(queue_t* queue);//free queue



int queue_full(queue_t* queue);

int queue_empty(queue_t* queue);

int queue_size(queue_t* queue);

int queue_push(queue_t* queue, int data);

int queue_pop(queue_t* queue);
#endif
void queue_init(queue_t* queue, int cap){
    queue->arr = (int *)malloc(sizeof(int)*cap);
    queue->cap = cap;
    queue->size = 0;
    queue->rear = 0;
    queue->front = 0;
}

void queue_deinit(queue_t* queue){
    free(queue->arr);
    queue->arr = NULL;
    queue->cap = 0;
    queue->size = 0;
    queue->rear = 0;
    queue->front = 0;
}


int queue_full(queue_t* queue){
    return queue->size >= queue->cap;
}

int queue_empty(queue_t* queue){
    //return queue->size == 0;
    return !queue->size;//size=0, !size=!0=1
}

int queue_size(queue_t* queue){
    return queue->size;
}

int queue_push(queue_t* queue, int data){
    if(queue->rear >= queue->cap)
        queue->rear = 0;
    queue->arr[queue->rear++] = data;
    //queue->rear++;
    queue->size++;
}

int queue_pop(queue_t* queue){
  
    if(queue->front >= queue->cap)
        queue->front = 0;
    queue->size--;
    return queue->arr[queue->front++];
}
