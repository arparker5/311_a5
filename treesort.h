
// *** Current work is at the bottom ***


// treesort.h  INCOMPLETE
// Glenn G. Chappell
// 15 Nov 2017
//
// For CS 311 Fall 2017
// Header for function template treesort
// There is no associated source file.

/*#ifndef FILE_TREESORT_H_INCLUDED
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

template<typename FDIter>

class node {
private:
    int _key;
    node* _left;
    node* _right;

public:
    node() : _key(0), _left(nullptr), _right(nullptr){}
    node(int key) : _key(key), _left(nullptr), _right(nullptr) {}
    ~node(){

    }
    //node(const node & other) = delete;
	//node(node && other) = delete;
	//node & operator=(const node & other) = delete;
	//node & operator=(node && other) = delete;
    int operator* (node noodle){
        return noodle._key;
    }

    //node operator-> (node noodle){

    //}
    /*friend bool operator== (node & rhs){
        this._key == rhs.key;
    }
    friend bool operator!= (node & rhs){
        return !(*this == rhs);
    }


    void insert(node<int>* &head, int item)
    {
        if(head == nullptr)
        {
            head = &node<int>(item);
        }
    }

};





// treesort
// Sort a given range using Treesort.
// Pre:
//     ???
// Requirements on Types:
//     ???
// Exception safety guarantee:
//     ???
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
    // Get the type that FDIter points to
    using Value = typename remove_reference<decltype(*first)>::type;

    // THE FOLLOWING IS DUMMY CODE. IT WILL PASS ALL TESTS. BUT IT DOES
    // NOT MEET THE REQUIREMENTS OF THE ASSIGNMENT.
    vector<Value> buff(distance(first, last));
    copy(first, last, buff.begin());
    stable_sort(buff.begin(), buff.end());
    copy(buff.begin(), buff.end(), first);

    //auto p = node<int> (6, nullptr, nullptr);
}


#endif //#ifndef FILE_TREESORT_H_INCLUDED
*/
// treesort.h  INCOMPLETE
// Glenn G. Chappell
// 15 Nov 2017
//
// For CS 311 Fall 2017
// Header for function template treesort
// There is no associated source file.

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

template<typename UserType>
struct node {
	// iterator, const_iterator: random-access iterator types
	using iterator = UserType *;
	using const_iterator = const UserType *;



	UserType _value;
	node* _leftChild = nullptr;
	node* _rightChild = nullptr;
	node* _parent = nullptr;

	node() = default;
	node(UserType key, node* parent) : _value(key), _parent(parent) {}

	// Use auto-generated copy/move ctor, dctor, copy/move op=
	node(const node & other) = default;
	node(node && other) = default;
	~node() = default;
	node & operator=(const node & other) = default;
	node & operator=(node && other) = default;

	// begin - non-const & const
	// No-Throw Guarantee
	// Exception neutral
	iterator begin()
	{
		if (_leftChild != nullptr)
			return  _leftChild.begin();
		else
			return this;
	}
	const_iterator begin() const
	{
		if (_leftChild != nullptr)
			return  _leftChild.begin();
		else
			return this;
	}

	// end - non-const & const
	// No-Throw Guarantee
	// Exception neutral
	iterator end()
	{
		if (_rightChild != nullptr)
			return _rightChild.end();
		else
			return this;
	}
	const_iterator end() const
	{
		if (_rightChild != nullptr)
			return _rightChild.end();
		else
			return this;
	}

	// Operator++ - non-const & const
	// No-Throw Guarantee
	// Exception neutral
	iterator & operator++()
	{
		if (_rightChild != nullptr)
			return _rightChild.begin();
		else if (_left_child == nullptr && _parent._rightChild == *this)
			return _parent._parent;
		else
			return _parent;
	}
	const iterator & operator++() const
	{
		if (_rightChild != nullptr)
			return _rightChild.begin();
		else if (_leftChild == nullptr && _parent._rightChild == *this)
			return _parent._parent;
		else
			return _parent;
	}

};

	template<typename UserType>
	// function retrieve
	// given a key, returns the location of the key.
	// if the key is not in the list, returns the location of a parent that has a null left_child.
	node<UserType>* retrieve(UserType key) {

		// *** DO THIS ***

		return nullptr; //Dummy
	}

	template<typename UserType>
	void insert(UserType key) {

		node<UserType>* location = retrieve(key);


		// If the value and the key are not the same
		if (key < location.value) {
			location._leftChild = make_shared <node<UserType> >(key, this);
		}
		else if (location.value < key)
			location._rightChild = make_shared <node<UserType> >(key, this);


		// The keys must be the same
		else {
			// Insert the given key after the location if theres an opening
			if (location._rightChild == nullptr)
				location._rightChild = make_shared <node<UserType> >(key);
			// If not, then make one
			else {
				node<UserType> temp = location.right_child;
				location._rightChild = make_shared <node<UserType> >(key);
			}
		}

		return; // Dummy
	}


// treesort
// Sort a given range using Treesort.
// Pre:
//     ???
// Requirements on Types:
//     ???
// Exception safety guarantee:
//     ???
template<typename FDIter>
void treesort(FDIter first, FDIter last)
{
    // Get the type that FDIter points to
    using Value = typename remove_reference<decltype(*first)>::type;

    // THE FOLLOWING IS DUMMY CODE. IT WILL PASS ALL TESTS. BUT IT DOES
    // NOT MEET THE REQUIREMENTS OF THE ASSIGNMENT.
    vector<Value> buff(distance(first, last));
    copy(first, last, buff.begin());
    stable_sort(buff.begin(), buff.end());
    copy(buff.begin(), buff.end(), first);
}


#endif //#ifndef FILE_TREESORT_H_INCLUDED
