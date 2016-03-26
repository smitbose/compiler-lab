#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    int type;
    char *tok;
    struct Node *next;
}; 

struct Node *hashMap[255];

void insert(char tok[],int type)
{
    int l = strlen(tok);
    int hash = (tok[0]+tok[l-1])/2;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->tok = (char *)malloc(l*sizeof(char));
    strcpy(newnode->tok,tok);
    newnode->type = type;
    newnode->next = hashMap[hash];
    hashMap[hash] = newnode;
}
int loopup()
{
    return -1;
}


