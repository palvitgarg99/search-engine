#include"instruction.c"
#include "createnode.c"
#include "createnode_id.c"
#include "insert_id.c"
#include "get_file.c"
#include "file_read.c"
#include "search_trie.c"
#include "getNode.c"
#include"header.h"
int main()
{
	 instruction();
     extern int i;
     	//setting up trie to store keywords......
		 initialize(&trie);
	
     int j;	
     struct name *temp;
     name=createnode();
     name_next=name;
     for(j=1;j<=i;j++)
	 {
	 	get_file(name_next->file);
	 	name_next->frequency=1;
	 	name_next->id=j;
	 	
	 if(j<i)
	 	 {
		    temp=createnode();
	 	    name_next->node=temp;
	 	    name_next=temp;
	     }
	 }
	 name_next->node=NULL;
	 name_next=name;
	 for(j=1;j<=i;j++)
	 {
	 	file_read(name_next->file,name_next->id);
	 	printf("yes it one");
	 	system("cls");
	 	printf("loading....");
		name_next=name_next->node;
	 	
	 }
	 system("cls");
	 int pal=1;
	 char take[100];
	 while(take[0]!='0')
	 { printf("\nEnter word to search:");
	 scanf("%s",take);
	 pal=search(&trie, take);
	 if(pal==0)
	 {
	 	printf("not exist");
	 }
	 
	
     }
	 
}



// Initializes trie (root is dummy node)
 void initialize(trie_t *pTrie)
{
    pTrie->root = getNode();
    pTrie->count = 0;
}
