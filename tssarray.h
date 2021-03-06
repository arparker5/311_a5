// tssarray.h
// Duane Shaffer
// Andrew Parker
// Eric Cater
// 25 Oct 2017
//
// For CS 311 Fall 2017
// Header for class TSSArray
// Templated Stunningly Smart Array
// Based off an integer array file from Dr. Glen Chappell


#ifndef FILE_TSSARRAY_H_INCLUDED
#define FILE_TSSARRAY_H_INCLUDED

// To get rid of compiler warning related to using std::copy
#pragma warning(disable:4996)

#include <cstddef>
// For std::size_t
#include <algorithm>
// For std::max


// *********************************************************************
// class TSSArray - Class definition
// *********************************************************************


// class TSSArray
// Templated Stunningly Smart Array
// Resizable, copyable/movable, exception-safe.
// Invariants:
//     0 <= _size <= _capacity.
//     _data points to an array of int, allocated with new[], owned by
//      *this, holding _capacity ints. Exception: _data may be nullptr,
//      if _capacity == 0.
// Requirements on types:
//		dctor, move ctor, and move assignment must not throw
template <typename T>
class TSSArray {

	// ***** SSArray: types *****
public:

	// value_type: type of data items
	using value_type = T;

	// size_type: type of sizes & indices
	using size_type = std::size_t;

	// iterator, const_iterator: random-access iterator types
	using iterator = value_type *;
	using const_iterator = const value_type *;

	// ***** SSArray: internal-use constants *****
private:

	// Capacity of default-constructed object
	static const size_type DEFAULT_CAP = 16;

	// ***** SSArray: ctors, op=, dctor
public:

	// Default ctor & ctor from size
	// Strong Guarantee
	explicit TSSArray(size_type size = size_type(0))
		:_capacity(std::max(size, size_type(DEFAULT_CAP))),
		// _capacity must be declared before _data
		_size(size),
		_data(new value_type[_capacity])
	{}

	// Copy ctor
	// Strong Guarantee
	TSSArray(const TSSArray &other)
		:_capacity(other._capacity),
		_size(other._size),
		_data(new value_type[_capacity])
	{
		try
		{
			std::copy(other.begin(), other.end(), begin());
		}
		catch (...)
		{
			delete [] _data;
			throw;
		}
	}

	// Move ctor
	// No-Throw Guarantee
	TSSArray(TSSArray && other) noexcept
		:_capacity(other._capacity),
		_size(other._size),
		_data(other._data)
	{
		other._capacity = 0;
		other._size = 0;
		other._data = nullptr;
	}

	// Dctor
	// No-Throw Guarantee
	~TSSArray()
	{
		delete[] _data;
	}

	// Copy assignment
	// Strong guarantee
	TSSArray & operator=(const TSSArray & rhs)
	{
		if (this == &rhs)
			return *this;
		TSSArray copy_of_rhs(rhs);
		swap(copy_of_rhs);
		return *this;
	}

	// Move assignment
	// No-Throw Guarantee
	TSSArray & operator=(TSSArray && rhs) noexcept
	{
		if (this == &rhs) // Check for self-assignment
			return *this;
		swap(rhs);
		return *this;
	}


	// ***** SSArray: general public operators *****
public:

	// Operator[] - non-const & const
	// No-Throw Guarantee
	value_type & operator[](size_type index)
	{
		return _data[index];
	}
	const value_type & operator[](size_type index) const
	{
		return _data[index];
	}

	// ***** SSArray: general public functions *****
public:

	// size
	// No-Throw Guarantee
	// Exception neutral
	size_type size() const
	{
		return _size;
	}

	// empty
	// No-Throw Guarantee
	// Exception neutral
	bool empty() const
	{
		return size() == size_type(0);
	}

	// begin - non-const & const
	// No-Throw Guarantee
	// Exception neutral
	iterator begin()
	{
		return _data;
	}
	const_iterator begin() const
	{
		return _data;
	}

	// end - non-const & const
	// No-Throw Guarantee
	// Exception neutral
	iterator end()
	{
		return begin() + size();
	}
	const_iterator end() const
	{
		return begin() + size();
	}

	//Resize member function
	// Pre: function is passed a nonnegative size_type
	// Strong guarantee
	// Exception neutral
	void resize(size_type newsize)
	{
		if (newsize <= _capacity)
		{
			_size = newsize;
			return;
		}

		while (_capacity < newsize)
			_capacity *= 2;


		value_type * olddata = _data;
		_data = new value_type[_capacity];
		try {
            for (size_type i = 0; i < _size; ++i)
            {
                *(_data + i) = *(olddata + i);
            }

            _size = newsize;
		}
		catch(...) {
            delete[] olddata;
            throw;
		}
		delete[] olddata;
        return;
	}

	// insert
	// Pre: pos is a valid iterator to a TSSArray object
	// Strong Guarantee
	// Exception neutral
	iterator insert(iterator pos,
		const value_type & item)
	{
		iterator oldBegin = begin();
		resize(_size + 1);

		// Need to fix the pos iterator if it became invalid
		if (begin() != oldBegin) {
			pos = begin() + std::distance(oldBegin, pos);
		}

		// Move all elements past the given position down
		for (iterator index = end()-1; index > pos; --index) {
			std::swap(*(index-1), *index);
		}

		// Place the item
		*pos = item;

		return pos;
	}
	// erase
	// Pre: pos is a valid iterator to a TSSArray object
	// Strong Guarantee
	// Exception neutral
	iterator erase(iterator pos)
	{
		resize(_size-1);
		if(pos == end())
            return end();

		value_type *swapptr = pos;
        while(swapptr != end())
        {
            std::swap(*swapptr, *(swapptr+1));
            ++swapptr;
        }
        return pos;
	}

	// push_back
	// InsertEnd operation.
	// Strong Guarantee
	// Exception neutral
	void push_back(const value_type & item)
	{
		insert(end(), item);
	}

	// pop_back
	// RemoveEnd operation.
	// Pre:
	//     _size > 0.
	// Strong Guarantee
	// Exception neutral
	void pop_back()
	{
		erase(end() - 1);
	}

	// swap
	// No-Throw Guarantee
	// Exception neutral
	void swap(TSSArray &other) noexcept
	{
		std::swap(_capacity, other._capacity);
		std::swap(_size, other._size);
		std::swap(_data, other._data);
	}

	// ***** SSArray: data members *****
private:

	size_type    _capacity;  // Size of our allocated array
	size_type    _size;      // Size of client's data
	value_type * _data;      // Pointer to our array

}; // End class SSArray


#endif //#ifndef FILE_TSSARRAY_H_INCLUDED
