
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

};


template<typename FDIter, typename N>
FDIter newlist(FDIter iter, N node)noexcept{
    //TO DO
    return iter;
}




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

