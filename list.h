#ifndef LIST_H
#define LIST_H 1

#define ListEntry int

typedef struct listNode {
  ListEntry entry;
  struct listNode* next;
} ListNode;

typedef struct list {
  ListNode* head;
  ListNode* current;

  int currentPos;
  int size;
} List;

void initializeList(List*);
bool listEmpty(List*);
bool listFull(List*);
int listSize(List*);
void destroyList(List*);
void insertList(int, ListEntry, List*);
void deleteList(int, ListEntry*, List*);
void retrieveList(int, ListEntry*, List*);
void replaceList(int, ListEntry, List*);
void traverseList(List*, void (*visit)(ListEntry));

#endif