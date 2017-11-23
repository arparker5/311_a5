#ifndef FILE_TREESORT_H_INCLUDED
#define FILE_TREESORT_H_INCLUDED

#include <type_traits>
using std::remove_reference;
#include <algorithm>
using std::stable_sort;
using std::copy;
#include <vector>
using std::vector;
#include <iterator>
using std::distance;
#include <memory>
using std::shared_ptr;
using std::make_shared;

// struct Node
// struct that is used by the Tree function and treesort
// Each node holds a key value and a pointer to both of the node's children
// Requirements on types:
//		dctor, move ctor, and move assignment must not throw
template<typename Valtype>
struct Node{
    Valtype _key;
    shared_ptr<Node<Valtype> > _rightptr;
    shared_ptr<Node<Valtype> > _leftptr;

    explicit Node(Valtype item):_key(item), _rightptr(nullptr), _leftptr(nullptr){}

    ~Node() = default;

};


template<typename Value>
struct Tree{
    shared_ptr<Node<Value> >rootptr = nullptr;


// Sort a given range using Treesort.
// Pre:
//     none
// Requirements on Types:
//     ValType must have a copy ctor and a dctor.
//      ValType dctor must not throw.

// Exception safety guarantee:
//     no throw
    shared_ptr<Node<Value> > insert(Value key)noexcept//The insert function is given a key, and then inserts it in the correct place in the tree
    {
        if(rootptr == nullptr)//If there is no root yet, make this node the root
        {
            rootptr = make_shared<Node<Value> >(key);
            return rootptr;
        }
        shared_ptr<Node<Value> > parent = rootptr;//If the node being entered is not the new root, set the rootptr to be the node's parent.
        while(true)
        {
            if(key < parent->_key)
            {
                if(parent->_leftptr != nullptr)
                {
                    parent = parent->_leftptr;
                }
                else
                {
                    break;
                }
            }else{
                if(parent->_rightptr != nullptr)
                {
                    parent = parent->_rightptr;
                }
                else
                {
                    break;
                }
            }
        }
        auto newNode = make_shared<Node<Value> >(key);
        if(key < parent->_key)
        {
            parent->_leftptr = newNode;
        }else{
            parent->_rightptr = newNode;
        }
        return newNode;
    }
};


// Sort a given range using Treesort.
// Pre:
//     none
// Requirements on Types:
//     ValType must have a copy ctor and a dctor.
//      ValType dctor must not throw.
// Exception safety guarantee:
//     no throw guarantee
template<typename FDIter, typename N>
FDIter newlist(FDIter iter, N node)noexcept{
	if (node->_leftptr != nullptr) {
		iter = newlist(iter, node->_leftptr);
	}
	*iter = node->_key;
	iter++;
	if (node->_rightptr != nullptr) {
		iter = newlist(iter, node->_rightptr);
	}
	return iter;
}



// treesort
// Sort a given range using Treesort.
// Pre:
//     FDIter must be iterator for a node
// Requirements on Types:
//     ValType must have a copy ctor and a dctor.
//      ValType dctor must not throw.
// Exception safety guarantee:
//     exception neutral
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
    // Get the type that FDIter points to
    using Value = typename remove_reference<decltype(*first)>::type;

	if (first == last) {
		return;
	}

	auto aTree = new Tree<Value>;
	for (FDIter iter = first; iter != last; iter++) {
		aTree->insert(*iter);
	}
	newlist(first, aTree->rootptr);
	delete aTree;
}





#endif //#ifndef FILE_TREESORT_H_INCLUDED
