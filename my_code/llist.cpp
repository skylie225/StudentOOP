#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
	os << nd->data;
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
	if (!head) {
		head = new Node(d, nullptr);
	}
	else {
		add_at_end(head->next, d);
	}
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* head) {
	if (!head) {
		os << "nullptr" << endl;
	}
	else {
		os << head << " --> ";
		print_list(os, head->next);
	}
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
	head = new Node(d, head);
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
	if (!head) return nullptr;
	else if (!head->next) return head;
	else return last(head->next);
}

bool del_head(Node*& head) {
	if (!head) return false;
	else {
		Node* temp = head;
		head = head->next;
		delete temp;
		return true;

	}
}


bool del_tail(Node*& curr) {
	if (!curr) return false;
	else {
		if (curr->next == nullptr) {
			curr = nullptr;
			return true;
		}
		else {
			return del_tail(curr->next);
		}
	}
}


Node* duplicate(Node* head) {
	if (!head) {
		return nullptr;
	}
	else {
		return new Node(head->data, duplicate(head->next));
	
	}
}


Node* reverse(Node* curr, Node* new_next) {
	if (!curr) return new_next;
	else {
		return reverse(curr->next, new Node(curr->data, new_next));
	}
}

Node* join(Node*& list1, Node* list2) {
	if (!list1) {
		list1 = list2;
		return list1;
	}
	else if (!list2) {
		return list1;
	}
	else {
		last(list1)->next = list2;
		return list1;
	}
}


// TEMPLATE
//
//#include <iostream>
//#include "llist.h"
//
//using namespace std;
//
//
//
///*
// * Output a Node pointer.
// * */
//template <typename DATA>
//ostream& operator<<(ostream& os, const Node<DATA>* nd) {
//	os << nd->data;
//	return os;
//}
//
//
///*
// * Add a node to the end of a list.
// * */
//template <typename DATA>
//void add_at_end(Node<DATA>*& head, int d) {
//	if (!head) {
//		head = new Node<DATA>(d, nullptr);
//	}
//	else {
//		add_at_end(head->next, d);
//	}
//}
//
//
///*
// * Given the head of a list, print the whole thing.
// * Let's do this recursively!
// * */
//
//template <typename DATA>
//void print_list(ostream& os, const Node<DATA>* head) {
//	if (!head) {
//		os << "nullptr" << endl;
//	}
//	else {
//		os << head << " --> ";
//		print_list(os, head->next);
//	}
//}
//
///*
// * Add a node at the front of a linked list.
// * */
//template <typename DATA>
//void add_at_front(Node<DATA>*& head, int d) {
//	head = new Node<DATA>(d, head);
//}
//
//
///*
// * Get the last node of a list.
// * */
//template <typename DATA>
//Node<DATA>* last(Node<DATA>* head) {
//	if (!head) return nullptr;
//	else if (!head->next) return head;
//	else return last(head->next);
//}
//
//
//template <typename DATA>
//bool del_head(Node<DATA>*& head) {
//	if (!head) return false;
//	else {
//		Node<DATA>* temp = head;
//		head = head->next;
//		delete temp;
//		return true;
//
//	}
//}
//
//template <typename DATA>
//bool del_tail(Node<DATA>*& curr) {
//	if (!curr) return false;
//	else {
//		if (curr->next == nullptr) {
//			curr = nullptr;
//			return true;
//		}
//		else {
//			return del_tail(curr->next);
//		}
//	}
//}
//
//template <typename DATA>
//Node<DATA>* duplicate(Node<DATA>* head) {
//	if (!head) {
//		return nullptr;
//	}
//	else {
//		return new Node<DATA>(head->data, duplicate(head->next));
//
//	}
//}
//
//template <typename DATA>
//Node<DATA>* reverse(Node<DATA>* curr, Node<DATA>* new_next) {
//	if (!curr) return new_next;
//	else {
//		return reverse(curr->next, new Node<DATA>(curr->data, new_next));
//	}
//}
//
//template <typename DATA>
//Node<DATA>* join(Node<DATA>*& list1, Node<DATA>* list2) {
//	if (!list1) {
//		list1 = list2;
//		return list1;
//	}
//	else if (!list2) {
//		return list1;
//	}
//	else {
//		last(list1)->next = list2;
//		return list1;
//	}
//}