/**/

#ifndef TSSARRAY_H
#define TSSARRAY_H

#include<iostream>
#include<algorithm>
using std::copy;

template <typename T>
class TSSArray
{
public:
    using value_type = T;
    using size_type = std::size_t;
    using iterator = value_type *;
    using const_iterator = const value_type *;


    //Default ctor and ctor from size
    explicit TSSArray(size_type size = size_type(0))
        :_capacity(std::max(size,_dCap)),_size(size),
        _data(new value_type[_capacity]){}


    //copy ctor
    TSSArray(const TSSArray &other)
        :_capacity(other._capacity),
        _size(other._size),
        _data(new value_type[_capacity])
    {
        try
        {
            copy(other.begin(), other.end(), begin());
        }
        catch(...)
        {
            delete this;
            throw;
        }
    }

    //move ctor
    TSSArray(TSSArray && other) noexcept
        :_capacity(other._capacity),
        _size(other._size),
        _data(other._data)
    {
        other._capacity = 0;
        other._size = 0;
        other._data = nullptr;
    }

    //Copy assignment
    TSSArray &operator=(const TSSArray & rhs)
    {
        // TODO: WRITE THIS!!!
        return *this; // DUMMY
    }


    // Move assignment
    TSSArray & operator=(TSSArray && rhs) noexcept
    {
        // TODO: WRITE THIS!!!
        return *this; // DUMMY
    }

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

    // size
    // No-Throw Guarantee
    size_type size() const
    {
        return _size;
    }

    // empty
    // No-Throw Guarantee
    bool empty() const
    {
        return size() == size_type(0);
    }

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
    iterator end()
    {
        return begin() + size();
    }
    const_iterator end() const
    {
        return begin() + size();
    }

    //swap member function
    void swap(TSSArray &other) noexcept
    {
        std::swap(_capacity, other._capacity);
        std::swap(_size, other._size);
        std::swap(_data, other._data);
    }


    //Resize member function
    //exception neutral
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
		for (size_type i = 0; i < _size; ++i)
		{
			*(_data + i) = *(olddata + i);
		}

		_size = newsize;
		delete[] olddata;

        /*
        try
        {
            copy(other.begin(), other.end(), begin());
        }
        catch(...)
        {
            delete this;
            throw;
        }
        */
    }

    iterator insert(iterator pos,
                    const value_type & item)
    {

    }

    // erase
    iterator erase(iterator pos)
    {

    }


private:
    size_type _size;
    size_type _capacity;
    value_type * _data;
    const size_type _dCap = 16;
};


#endif // TSSARRAY_H
