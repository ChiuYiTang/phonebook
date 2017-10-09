#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_bstbig.h"

int Length(entry *head)
{
    int count = 0;
    entry *current = head;

    while (current) {
        count++;
        current = current -> pNext;
    }

    return count;
}

treeNode *BuildBST(entry **headRef, int length)
{
    if(length <= 0)
        return NULL;

    treeNode *left = BuildBST(headRef, length/2);
    treeNode *root = (treeNode *) malloc(sizeof(treeNode));
    root->entry[0] = *headRef;
    root->left = left;

    *headRef = (*headRef)->pNext;

    root->right = BuildBST(headRef, length - (length / 2 + 1));

    return root;
}

entry *findName(char lastName[], treeNode *root)
{
    treeNode *current = root;
    int result;

    while (current != NULL && (result = strcasecmp(lastName, current->entry[0]->lastName)) != 0) {
        if (result < 0)
            current = current -> left;
        else
            current = current -> right;
    }

    if (root)
        return (current->entry[0]);
    else
        return NULL;
}
entry *append(char lastName[], entry *e)
{
    /* allocate memory for the new entry and put lastName */
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}
