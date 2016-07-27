#include"header.h"
struct id* createnode_id() 
{ 
   struct id *temp;
   temp=(struct id*)malloc(sizeof(struct id)); 
   temp->node=NULL;
   temp->id=0;
   return temp; 
} 
