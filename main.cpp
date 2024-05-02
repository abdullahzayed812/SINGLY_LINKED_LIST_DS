#include <iomanip>
#include <iostream>

#include "list.h"

void print(ListEntry element) { std::cout << element << "\n"; }

int main() {
  List myList;

  initializeList(&myList);

  // Using list as a queue
  insertList(listSize(&myList), 10, &myList);
  insertList(listSize(&myList), 20, &myList);
  insertList(listSize(&myList), 30, &myList);
  insertList(listSize(&myList), 40, &myList);

  // traverseList(&myList, print);

  ListEntry item;
  ListEntry item1;
  ListEntry item2;
  ListEntry item3;

  retrieveList(0, &item, &myList);
  retrieveList(1, &item1, &myList);
  retrieveList(2, &item2, &myList);
  retrieveList(3, &item3, &myList);

  std::cout << item << "\n";   // 10
  std::cout << item1 << "\n";  // 20
  std::cout << item2 << "\n";  // 30
  std::cout << item3 << "\n";  // 40

  destroyList(&myList);

  // Using list as stack
  insertList(listSize(&myList), 10, &myList);
  insertList(listSize(&myList), 20, &myList);
  insertList(listSize(&myList), 30, &myList);
  insertList(listSize(&myList), 40, &myList);

  retrieveList(listSize(&myList) - 1, &item, &myList);

  std::cout << item << "\n";  // 40

  std::cout << std::boolalpha << "List Full: " << listEmpty(&myList) << "\n";
  std::cout << std::boolalpha << "List Empty: " << listFull(&myList) << "\n";
  std::cout << "List Size: " << listSize(&myList) << "\n";

  replaceList(0, 100, &myList);

  traverseList(&myList, print);

  destroyList(&myList);

  // traverseList(&myList, print);

  return 0;
}