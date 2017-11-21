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

template<typename FDIter>

class node {
private:
    int _key;
    node* _left;
    node* _right;

public:
    node() : _key(0), _left(nullptr), _right(nullptr){}
    node(int key, node* left, node* right) : _key(key), _left(left), _right(right) {}
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
    }*/


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

    auto p = node<int> (6, nullptr, nullptr);
}


#endif //#ifndef FILE_TREESORT_H_INCLUDED

