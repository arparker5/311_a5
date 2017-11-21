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



	UserType value;
	node* left_child = null;
	node* right_child = null;
	node* parent = null;

	node() = default;
	node(UserType key): value(key) {}

	// Use auto-generated copy/move ctor, dctor, copy/move op=
	Product(const Product & other) = default;
	Product(Product && other) = default;
	~Product() = default;
	Product & operator=(const Product & other) = default;
	Product & operator=(Product && other) = default;

	// begin - non-const & const
	// No-Throw Guarantee
	// Exception neutral
	iterator begin()
	{
		if (left_child != null)
			return left_child.begin();
		else
			return this;
	}
	const_iterator begin() const
	{
		if (left_child != null)
			return left_child.begin();
		else
			return this;
	}

	// end - non-const & const
	// No-Throw Guarantee
	// Exception neutral
	iterator end()
	{
		if (right_child != null)
			return right_child.end();
		else
			return this;
	}
	const_iterator end() const
	{
		if (right_child != null)
			return right_child.end();
		else
			return this;
	}

	// Operator++ - non-const & const
	// No-Throw Guarantee
	// Exception neutral
	iterator & operator++()
	{
		if (right_child != null)
			return right_child.begin();
		else if (left_child == null && parent.right_child == *this)
			return parent.parent;
		else
			return parent;
	}
	const iterator & operator++() const
	{
		if (right_child != null)
			return right_child.begin();
		else if (left_child == null && parent.right_child == *this)
			return parent.parent;
		else
			return parent;
	}

	// function retrieve
	// given a key, returns the location of the key.
	// if the key is not in the list, returns the location of a parent that has a null left_child.
	node* retrieve(UserType key) {

		// *** DO THIS ***

		return null; //Dummy
	}

	void insert(UserType key) {

		node* location = retrieve(key);


		// If the value and the key are not the same
		if ((location.value < key) || (key < location.value)) {
			if (location.left_child == null)
				location.left_child = make_shared <node<UserType> >(key);
		}
		// If the value and the key are the same
		if (!(location.value < key) && !(key < location.value)) {
			// Insert the given key after the location if theres an opening
			if (location.right_child == null)
				location.right_child = make_shared <node<UserType> >(key);
			// If not, then make one
			else {
				node<UserType> temp = location.right_child;
				location.right_child = make_shared <node<UserType> >(key);
			}
		}
		// If the value and the key are not the same
		else {
			if (location.left_child == null)
				location.left_child = make_shared <node<UserType> >(key);
		}

		return; // Dummy
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
}


#endif //#ifndef FILE_TREESORT_H_INCLUDED

