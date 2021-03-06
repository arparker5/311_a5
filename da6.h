// da6.h
// Duane Shaffer, Andrew Parker, Eric Cater
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
#include <functional>
using std::function;



template<typename ValType>
// pre: none
void reverseList(shared_ptr<LLNode2<ValType> > & head) {
	// do a 3 pointer rotate on head, newhead, head->_next

	if (isEmpty(head)) {
		return;
	}

	//newhead will be empty of data by default due to shared_ptr
	shared_ptr<LLNode2<ValType> > tempHead; 
	shared_ptr<LLNode2<ValType> > newhead;

	while (!isEmpty(head)) {
		// Save the next element of the given linked list
		tempHead = head->_next;
		// 3 pointer rotate
		head->_next = newhead;
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
//     ValType must have operator<< (stream insertion).
//     Throws what & when a ValType operation throws.
template<typename KeyType, typename DataType>
//class invariants: none
class LLMap {
private:
	using KDTYPE = std::pair<KeyType, DataType>;

    shared_ptr<LLNode2<KDTYPE> > _head;



	// Pre: none
    // no throw Guarantee
	// Exception neutral
public:
	explicit LLMap()
	{}

	~LLMap() {
		while (_head != 0) {
			_head = _head->_next;
		}
	}
	LLMap(const LLMap & other) = delete;
	LLMap(LLMap && other) = delete;
	LLMap & operator=(const LLMap & other) = delete;
	LLMap & operator=(LLMap && other) = delete;


	// Based on llnode.h's size function
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
	size_t size () const{
		auto p = _head;  // Iterates through list
		size_t n = 0;   // Number of nodes so far
		while (p)
		{
			p = p->_next;
			++n;
		}
		return n;
	}

	// Pre: none
	// no throw Guarantee
	// Exception neutral
	bool empty() {
        return !(_head);
	}

    // Pre: none
	// no throw Guarantee
	// Exception neutral
	const bool empty() const {
		return !(_head);
	}


	// Pre: none
    // no throw Guarantee
	// Exception neutral
	const DataType* find(KeyType key_to_find) const{
        auto p = _head;  // Iterates through list
		while (p)
		{
		  if(p->_data.first == key_to_find){
                return &p->_data.second;
		    }
			p = p->_next;
		}
		return nullptr;
	}

	// Pre: none
	// no throw guarantee
	// Exception neutral
	DataType* find(KeyType key_to_find) {
        auto p = _head;  // Iterates through list
		while (p)
		{
		  if(p->_data.first == key_to_find){
                return &p->_data.second;
		    }
			p = p->_next;
		}
		return nullptr;
	}

	// Pre: none
	// strong guarantee
	// Exception neutral
	void insert(KeyType key, DataType data) {
        DataType * place =  find(key);

		if(place){
            *place = data;
		}
		else{
            _head = make_shared<LLNode2<KDTYPE> >(std::make_pair(key,data), _head);
		}
	}

	// Pre: none
	// no throw guarantee
	// Exception neutral
	void erase(KeyType key) {

        if(_head->_data.first == key){
            _head=_head->_next;
        }
        else{
            auto p = _head;  // Iterates through list
            auto o = _head;
            while (p)
            {
                o = p;
                p = p->_next;
                if(p && p->_data.first == key){
                    o->_next = p->_next;
                    return;
                }
            }
        }

		return;
	}

	// Pre: none
	// basic guarantee
	// Exception neutral
	void traverse(function<void(KeyType, DataType)> func) {
	    auto p = _head;
        while (p)
		{
		    func(p->_data.first, p->_data.second);
			p = p->_next;
		}
	}
}; // End class LLMap

#endif // DA6_H_INCLUDED
