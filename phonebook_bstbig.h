#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 3

typedef struct __PHONE_BOOK_ENTRY {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} DetailEntry;

typedef struct __LAST_NAME_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    DetailEntry *detail;
    struct __LAST_NAME_ENTRY *pNext;
} entry;

typedef struct __TREE_NODE {
    entry *entry[6];
    struct __TREE_NODE *right;
    struct __TREE_NODE *left;
} treeNode;

int Length(entry *head);
treeNode *BuildBST(entry **headRef, int length);
entry *findName(char lastName[], treeNode *root);
entry *append(char lastName[], entry *e);


#endif