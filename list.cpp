#include "list.h"

#include <stdlib.h>

void initializeList(List* list) {
  list->head = nullptr;
  list->current = nullptr;

  list->currentPos = 0;
  list->size = 0;
}

bool listEmpty(List* list) { return !list->head; }

bool listFull(List* list) { return false; }

int listSize(List* list) { return list->size; }

void insertList(int pos, ListEntry element, List* list) {
  ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
  newNode->entry = element;
  newNode->next = nullptr;

  if (pos == 0) {
    newNode->next = list->head;
    list->head = newNode;
    list->current = list->head;
    list->currentPos = 0;
  } else {
    if (pos >= list->currentPos) {
      list->current = list->head;
      list->currentPos = 0;
    }

    for (; list->currentPos != pos - 1; list->currentPos++) {
      list->current = list->current->next;
    }

    newNode->next = list->current->next;
    list->current->next = newNode;
  }
}