#include"header.h"


file_read(char *file,int id)
{
    
	

	FILE *fp;
	char ch,buf[7],st[]={'s','t','y','l','e'},st1[]={'s','c','r','i','p','t'},word[100];
	int a,t=99999,m=0;
	int pick=1;//0 means dont pick now & 1 means pick it.....used in case of script and style tag.....
	int angul=0;//0 means no angular bracket going on.....& 1 means pointer is in between angular bracket
 	fp=fopen(file,"r");
 	 
 	
	 while(ch!=EOF)
 	{
 		ch=fgetc(fp);
 		//printf("%c",ch);
 		
 	     if(ch=='<')
		 {
		 	angul=1;
		 	for(a=1;a<=7;a++)
		    {
			   ch=fgetc(fp);
			   buf[a-1]=ch;
		    }
		    //printf("%c\n",ch);
		    
			for(a=1;a<=7;a++)
			{
				fseek( fp, -1, SEEK_CUR);
			}
		    
			for(a=0;a<=4;a++)
			{
				if(st[a]==buf[a])
				continue;
				else
				break;
			}
			if(a==5)
			pick=0;
			
			
		    for(a=0;a<=5;a++)
			{
				if(st1[a]==buf[a])
				continue;
				else
				break;
			}
			if(a==6)
			pick=0;	
			
			
		    if(buf[0]=='/')
			{	
			for(a=0;a<=4;a++)
			{
				if(st[a]==buf[a+1])
				continue;
				else
				break;
			}
			if(a==5)
			pick=1;
			
			
		    for(a=0;a<=5;a++)
			{
				if(st1[a]==buf[a+1])
				continue;
				else
				break;
			}
			if(a==6)
			pick=1;	
		    }
		    continue;
		 }
		 
		 if(ch=='>')
		 {angul=0;
		 continue;
		 }
		 
		 int p=ch;
		 if((p>=65&&p<=90)||(p>=97&&p<=122))
		 {
		 	
		    if(angul==0&&pick==1)
		     {
		 	     word[m++]=ch;
		 	     //printf("%c",ch);
		 	    
		     }
		     ch=fgetc(fp);
		  if(m!=0)
		  {
		     if(ch=='\n'||ch==' '||ch=='.'||ch==','||ch=='-'||ch=='<'||ch=='"')
		      { word[m]='\0';
		      insert(&trie,word,id);
		      //printf("%s ",word); 
		        m=0;
		        //pass the word to set in trie
		      }   
		  }
		  fseek( fp, -1, SEEK_CUR);
		     
                  		     
	     }
	    
	     
			  	
 	}
 	fclose(fp);
     
 	
}




 


 
// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct trie *pTrie, char *key,int id)
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;
    pTrie->count++;
    pCrawl = pTrie->root;
 
    for( level = 0; level < length; level++)
    {
        if(key[level]>=97&&key[level]<=122)
		index = CHAR_TO_INDEX(key[level]);
		else
		index = CHAR_TO_INDEX1(key[level]);
        if( !pCrawl->children[index] )
        {
            pCrawl->children[index] = getNode();
            
        }
 
        pCrawl = pCrawl->children[index];
    }
    struct id *temp;

	if(pCrawl->mode==NULL)
    {
    pCrawl->mode=createnode_id();
    temp=pCrawl->mode;
    temp->id=id;
    
	}
    else
    {
    temp=pCrawl->mode;
    insert_id(temp,id);
    }
	
    // mark last node as leaf
    pCrawl->value = pTrie->count;
}

