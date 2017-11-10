// da6.h
// Duane Shaffer
// 5 Nov 2017
//
// For CS 311 Fall 2017
// Header file for assignment 6, working with linked lists.


#ifndef DA6_H_INCLUDED
#define DA6_H_INCLUDED

#include <cstddef>
using std::size_t;
#include <memory>
using std::shared_ptr;
using std::make_shared;
#include "llnode2.h"


// *** I think that the reverseList is implemented properly but can't check since the program doesn't compile yet ***

template<typename ValType>
void reverseList(shared_ptr<LLNode2<ValType> > & head) {
	// do a 3 pointer rotate on head, newhead, head->_next

	if (isEmpty(head)) {
		return;
	}

	//newhead will be empty of data by default due to shared_ptr
	shared_ptr<LLNode2> tempHead;
	make_shared<LLNode2<ValType> > newhead;

	while (!isEmpty(head)) {
		// Save the next element of the given linked list
		tempHead = head._next;
		// 3 pointer rotate
		head._next = newhead;
		newhead = head;
		head = tempHead;
	}
	head = newhead;
	return;
}
// class LLMap
// Linked List node with client-specified value type. It is expected
// that LLMap objects will be created with make_shared, and always
// held by a shared_ptr. An empty list is represented by an empty
// shared_ptr.
// Invariants:
//     Either _next is empty, or _next points to an empty-ptr-terminated
//      Linked List of LLMap.
// Requirements on Types:
//     ValType must have a copy ctor and a dctor.
//     ValType dctor must not throw.
template<typename KeyType, typename DataType>
class LLMap {
private:

	shared_ptr<LLNode2<KeyType> > _Node;

	// The following simplify creation & destruction
	// 1- & 2-param ctor
	// Pre: None.
	// Post:
	//     _data == data.
	//     If _next passed, then _next == next. Otherwise, _next is
	//      empty.
	// Strong guarantee
	// Throws what & when a ValType operation throws.
	// Exception neutral
public:
	explicit LLMap(KeyType key, DataType data)
		:_Node(shared_ptr<LLNode2<KeyType> > (data))
	{}

	~LLMap() = default;
	LLMap(const LLMap & other) = delete;
	LLMap(LLMap && other) = delete;
	LLMap & operator=(const LLMap & other) = delete;
	LLMap & operator=(LLMap && other) = delete;

	// size *** Change this stuff ***
	// Given shared_ptr to Linked List, return its size (number of nodes).
	// Pre:
	//     head is ptr to empty-ptr-terminated Linked List, or is empty.
	// Post:
	//     Return is size of list (0 if head is empty).
	// Requirements on Types:
	//     ValType must have a copy ctor and a dctor.
	//     ValType dctor must not throw.
	// NOTE: The above are the requirements for LLNode2<ValType>; no member
	// functions of ValType are actually used here.
	// No-Throw Guarantee
	size_t size (void){
		auto p = head;  // Iterates through list
		size_t n = 0;   // Number of nodes so far
		while (p)
		{
			p = p->_next;
			++n;
		}
		return n;
	}

	// empty
	// *** Description ***
	// Pre:
	//     
	// Post:
	//     
	// Requirements on Types: *** Copied from another function. Likely need editing ***
	//     ValType must have a copy ctor and a dctor.
	//     ValType dctor must not throw.
	//     ValType must have operator<< (stream insertion).
	// Strong Guarantee
	// Throws what & when a ValType operation throws.
	// Exception neutral
	bool empty() {


		// *** TO DO ***
		
		return true; // DUMMY RETURN
	}
	// find
	// const and non-const versions
	// *** Description ***
	// Pre:
	//     
	// Post:
	//     
	// Requirements on Types: *** Copied from another function. Likely need editing ***
	//     ValType must have a copy ctor and a dctor.
	//     ValType dctor must not throw.
	//     ValType must have operator<< (stream insertion).
	// Strong Guarantee
	// Throws what & when a ValType operation throws.
	// Exception neutral
	const DataType* find(KeyType key_to_find) const{
		DataType * dummy;
		return dummy;
	}

	DataType* find(KeyType key_to_find) {
		DataType * dummy;
		return dummy;
	}

	// insert
	// *** Description ***
	// Pre:
	//     
	// Post:
	//     
	// Requirements on Types: *** Copied from another function. Likely need editing ***
	//     ValType must have a copy ctor and a dctor.
	//     ValType dctor must not throw.
	//     ValType must have operator<< (stream insertion).
	// Strong Guarantee
	// Throws what & when a ValType operation throws.
	// Exception neutral
	void insert(KeyType key, DataType data) {


		// *** TO DO ***

		return;
	}

	// erase
	// *** Description ***
	// Pre:
	//     
	// Post:
	//     
	// Requirements on Types: *** Copied from another function. Likely need editing ***
	//     ValType must have a copy ctor and a dctor.
	//     ValType dctor must not throw.
	//     ValType must have operator<< (stream insertion).
	// Strong Guarantee
	// Throws what & when a ValType operation throws.
	// Exception neutral
	void erase(KeyType key) {
		

		// *** TO DO ***
		
		return;
	}
	// traverse
	// *** Description ***
	// Pre:
	//     
	// Post:
	//     
	// Requirements on Types: *** Copied from another function. Likely need editing ***
	//     ValType must have a copy ctor and a dctor.
	//     ValType dctor must not throw.
	//     ValType must have operator<< (stream insertion).
	// Strong Guarantee
	// Throws what & when a ValType operation throws.
	// Exception neutral
	template <typename funcType> 
	void traverse(funcType) {
		return;
	}


}; // End class LLMap

#endif // DA6_H_INCLUDED
