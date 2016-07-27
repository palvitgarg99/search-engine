#include"header.h"
// Returns non zero, if key presents in trie
int search(trie_t *pTrie, char *key)
{
    int level;
    int length = strlen(key);
    int index;
    int flag=0;
    trie_node_t *pCrawl;
 
    pCrawl = pTrie->root;
 
    for( level = 0; level < length; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);
 
        if( !pCrawl->children[index] )
        {
            return 0;
        }
 
        pCrawl = pCrawl->children[index];
    }
   struct id *temp=pCrawl->mode;
  // printf("%d",temp);
   if(temp!=NULL)
   {
    while(temp!=NULL)
    {
    flag=1;
	printf("%d ",temp->id);
	temp=temp->node;
   } }
   if(flag==0)
   return 0;
    return (0 != pCrawl&&pCrawl->value);
}
