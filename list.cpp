#include "list.h"

#include <cstdlib>

void initializeList(List* list) {
  list->head = nullptr;
  list->current = nullptr;

  list->currentPos = 0;
  list->size = 0;
}

bool listEmpty(List* list) { return !list->head; }

bool listFull(List* list) { return false; }

int listSize(List* list) { return list->size; }

void destroyList(List* list) {
  while (list->head) {
    list->current = list->head->next;
    std::free(list->head);
    list->head = list->current;
  }

  list->size = 0;
  list->currentPos = 0;
}

void insertList(int pos, ListEntry element, List* list) {
  ListNode* newNode = (ListNode*)std::malloc(sizeof(ListNode));
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

  list->size++;
}

void deleteList(int pos, ListEntry* element, List* list) {
  ListNode* temp;

  if (pos == 0) {
    *element = list->head->entry;
    list->current = list->head->next;
    std::free(list->head);
    list->head = list->current;
    list->currentPos = 0;
  } else {
    if (list->currentPos <= pos) {
      list->current = list->head;
      list->currentPos = 0;
    }

    for (; list->currentPos != pos - 1; list->currentPos++) {
      list->current = list->current->next;
    }

    *element = list->current->next->entry;
    temp = list->current->next->next;
    std::free(list->current->next);
    list->current->next = temp;
  }

  list->size--;
}

void retrieveList(int pos, ListEntry* element, List* list) {
  if (pos == 0) {
    *element = list->head->entry;
    list->current = list->head;
    list->currentPos = 0;
  } else {
    if (list->currentPos <= pos) {
      list->current = list->head;
      list->currentPos = 0;
    }

    for (; list->currentPos < pos; list->currentPos++) {
      list->current = list->current->next;
    }

    *element = list->current->entry;
  }
}

void replaceList(int pos, ListEntry element, List* list) {
  if (pos == 0) {
    list->head->entry = element;
    list->current = list->head;
    list->currentPos = 0;
  } else {
    if (list->currentPos <= pos) {
      list->current = list->head;
      list->currentPos = 0;
    }

    for (; list->currentPos < pos; list->currentPos++) {
      list->current = list->current->next;
    }

    list->current->entry = element;
  }
}

void traverseList(List* list, void (*visit)(ListEntry)) {
  ListNode* visitor = list->head;

  while (visitor) {
    (*visit)(visitor->entry);

    visitor = visitor->next;
  }
}
