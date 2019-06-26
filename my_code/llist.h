#ifndef LINKED_H
#define LINKED_H

#include <iostream>


/*
 * The struct `Node`, which is the building block of our linked list code.
 * */
struct Node {
	Node(int d, Node* n = nullptr) : data(d), next(n) {}
	int data;
	Node* next;
};


/*
 * The various functions that can operate on our linked lists:
 * */
std::ostream& operator<<(std::ostream& os, const Node* nd);
void print_list(std::ostream& os, const Node* curr);
Node* last(Node* head);
void add_at_end(Node*& head, int d);
void add_at_front(Node*& head, int d);

/*
 * These are coming:
*/

/*
 * Delete the first node and attach head to the 2nd node:
 * */
bool del_head(Node*& head);

/*
 * Delete the last node and set prev->next to nullptr:
 * */
bool del_tail(Node*& head);

/*
 * Duplicate the entire list -- you must not share memory!
 * */
Node* duplicate(Node* head);

/*
 * Reverse the list: return a brand new list with everything reversed.
 * */
Node* reverse(Node* curr, Node* new_next);

/*
 * Join two lists: tack list 2 onto the end of list 1:
 * Use existing memory.
 * */
Node* join(Node*& list1, Node* list2);

#endif


//TEMPLATE

//#ifndef TEMPL_LL_H
//#define TEMPL_LL_H
//
//#include <iostream>
//
//
///*
// * The class template `Node`, which is the building block of our linked list code.
// * */
//template <typename DATA>
//class Node {
//public:
//	Node(DATA d, Node* n = nullptr) : data(d), next(n) {}
//	DATA data;
//	Node* next;
//};
//
//
///*
// * The various functions that can operate on our linked lists:
// * */
//
//template <typename DATA>
//std::ostream& operator<<(std::ostream& os, const Node<DATA>* nd);
//template <typename DATA>
//void print_list(std::ostream& os, const Node<DATA>* curr);
//template <typename DATA>
//Node<DATA>* last(Node<DATA>* head);
//template <typename DATA>
//void add_at_end(Node<DATA>*& head, int d);
//template <typename DATA>
//void add_at_front(Node<DATA>*& head, int d);
//
///*
// * These are coming:
//*/
//
///*
// * Delete the first node and attach head to the 2nd node:
// * */
//template <typename DATA>
//bool del_head(Node<DATA>*& head);
//
///*
// * Delete the last node and set prev->next to nullptr:
// * */
//template <typename DATA>
//bool del_tail(Node<DATA>*& head);
//
///*
// * Duplicate the entire list -- you must not share memory!
// * */
//template <typename DATA>
//Node<DATA>* duplicate(Node<DATA>* head);
//
///*
// * Reverse the list: return a brand new list with everything reversed.
// * */
//template <typename DATA>
//Node<DATA>* reverse(Node<DATA>* curr, Node<DATA>* new_next);
//
///*
// * Join two lists: tack list 2 onto the end of list 1:
// * Use existing memory.
// * */
//template <typename DATA>
//Node<DATA>* join(Node<DATA>*& list1, Node<DATA>* list2);
//
//
//#endif