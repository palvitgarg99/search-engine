#include"header.h"
insert_id(struct id *start,int id)
{
    while(start->node!=NULL)
	{
		start=start->node;
	}	
	start->node=createnode_id();
	start=start->node;
	start->id=id;
	start->node=NULL;
}
