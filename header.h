#ifndef pal_o
#define pal_o
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define CHAR_TO_INDEX1(c) ((int)c - (int)'A')

typedef struct trie trie_t;
typedef struct trie_node trie_node_t;
struct name* createnode();
struct trie_node *getNode(void);
struct id* createnode_id(); 
 void initialize(trie_t *);
 void insert(trie_t *, char*,int);
 
struct name 
{
  char file[100]; 
  int frequency;
  int id;
  struct name *node; 
} *name,*name_next;

int i;
trie_t trie;
struct id
{
	int id;
	struct id* node;
};


struct trie_node
{
    int value;
    trie_node_t *children[ALPHABET_SIZE];
    struct id *mode;
    
};
 

struct trie
{
    trie_node_t *root;
    int count;
};
#endif 
