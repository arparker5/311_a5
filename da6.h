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


template<typename ValType>
void reverseList(shared_ptr<LLNode2<ValType> > & head) {
	// do a 3 pointer rotate on hea, newhead, head->_next

	LLNode2<ValType> newhead;
	while (!head->empty()) {

	}
	head = newhead;

}
// *** skeleton for LLMap was based off LLNode2. Likely need to delete the associated functions that came from it. ***
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
	// *** Members need to be changed. Requirements are for one and only one data member ***
	DataType             _data;  // Data for this node
	shared_ptr<LLMap> _next;  // Ptr to next node, or empty if none

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
	explicit LLMap(const ValType & data,
		shared_ptr<LLMap> next = nullptr)
		:_data(data),
		_next(next)
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
	const DataType* find(KeyType key_to_find) {
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
	// void traverse( *** Not sure on how to declare this one ***


}; // End class LLMap

#endif // DA6_H_INCLUDED
