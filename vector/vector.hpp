#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>

#include "../iterator_traits.hpp"
#include "../reverse_iterator.hpp"
#include "../iterator.hpp"
#include "../enable_if.hpp"
#include "../is_integral.hpp"

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
    public:
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef std::size_t size_type;
        typedef ft::random_access_iterator<value_type> iterator;
        typedef ft::random_access_iterator<const value_type> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const iterator> const const_reverse_iterator;
        typedef std::ptrdiff_t difference_type;

        explicit vector(const allocator_type &alloc = allocator_type())
        {
            this->_alloc = alloc;
            this->_size = 0;
            this->_capacity = 0;
            this->_data = nullptr;
        }
        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
        {
            this->_capacity = n;
            this->_alloc = alloc;
            this->_size = n;
            this->_data = _alloc.allocate(_capacity);
            for (std::size_t i = 0; i < _capacity; i++)
            {
                this->_data[i] = val;
            }
        }
        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
               typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = 0)
        {
            difference_type n = last - first;
            this->_capacity = n;
            this->_size = n;
            this->_alloc = alloc;
            this->_data = this->_alloc.allocate(n);
            int i = 0;
            for (InputIterator it = first; it != last; it++)
            {
                this->_data[i] = *it;
                i++;
            }
        }
        vector(const vector &x)
        {
            this->_capacity = 0;
            this->_size = 0;
            *this = x;
        }
        size_type size()
        {
            return this->_size;
        }
        vector &operator=(const vector &x)
        {
            for (size_type i = 0; i < this->_size; i++)
            {
                this->_alloc.destroy(this->_data + i);
            }
            if (this->capacity > 0)
                this->_alloc.deallocate(this->_data, this->_capacity);
            this->_data = this->_alloc.allocate(_capacity);
            for (size_t i = 0; i < x._size; ++i)
            {
                this->_data[i] = x._data[i];
            }
            return *this;
        }

        reference operator[](size_type n)
        {
            return this->_data[n];
        }
        const_reference operator[](size_type n) const
        {
            return this->_data[n];
        }
        ~vector()
        {
            for (int i = 0; i < _size; i++)
            {
                _alloc.destroy(_data + i);
            }
            if (this->_capacity)
                _alloc.deallocate(_data, _capacity);
            _size = 0;
            _capacity = 0;
            _data = NULL;
        }
        iterator begin()
        {
            return iterator(_data);
        }
        const_iterator begin() const
        {
            return const_iterator(_data);
        }

        iterator end()
        {
            return iterator(_data + _size);
        }
        const_iterator end() const
        {
            return const_iterator(_data + _size);
        }
        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }
        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(end());
        }
        size_type capacity() const
        {
            return _capacity;
        }
        bool empty() const
        {
            _size ? true : false;
        }
        size_type max_size() const
        {
            return this->_alloc.max_size();
        }
        void reserve(size_type n)
        {
            if (n > _alloc.max_size())
                throw std::length_error("param > max_size");
            else if (n > _capacity)
            {
                pointer new_dt = _alloc.allocate(_capacity);
                for (size_type i = 0; i < _size; i++)
                    _alloc.construct(new_dt + i, _data[i]);
                for (size_type i = 0; i < _size; i++)
                    _alloc.destroy(_data + i);
                if (_capacity > 0)
                    _alloc.deallocate(_data, _size);
                _capacity = n;
                _data = new_dt;
            }
        }

        void push_back(const value_type &val)
        {
            if (_capacity == 0)
                reserve(1);
            if (_size + 1 > _capacity)
                reserve(_capacity * 2);
            _alloc.construct(_data + _size, val);
            _size++;
        }

        void pop_back()
        {
            if (_size > 0)
            {
                _alloc.destroy(_data + _size - 1);
                _size--;
            }
        }
        reference front()
        {
            return _data[0];
        }
        const_reference front() const
        {
            return _data[0];
        }
        reference back()
        {
            return _data[_size - 1];
        }
        const_reference back() const
        {
            return _data[_size - 1];
        }
        void assign(size_type n, const value_type &val)
        {
            if (n > _alloc.max_size())
                throw std::length_error("param > max_size");
            else if (n > _capacity)
                reserve(n);
            value_type *new_dt = _alloc.allocate(n);
            for (size_type i = 0; i < n; i++)
                _alloc.construct(new_dt + i, val);
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(_data + i);
            if (_capacity > 0)
                _alloc.deallocate(_data, _size);
            _capacity = n;
            _size = n;
            _data = new_dt;
        }

        template <class InputIterator>
        void assign(InputIterator first, InputIterator last,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type * = 0)
        {

            difference_type n = last - first;
            if (n > _alloc.max_size())
                throw std::length_error("param > max_size");
            else if (n > _capacity)
                reserve(n);
            value_type *new_dt = _alloc.allocate(n);
            for (size_type i = 0; i < n; i++)
            {
                _alloc.construct(new_dt + i, *first);
                first++;
            }
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(_data + i);
            if (_capacity > 0)
                _alloc.deallocate(_data, _size);
            _capacity = n;
            _size = n;
            _data = new_dt;
        }
        iterator insert(iterator position, const value_type &val)
        {
            size_t k = 0;
            ft::vector<value_type>
                tmp;
            tmp.assign(position, end());
            _size = position - begin();
            if (_size + 1 > _capacity)
                reserve(_capacity * 2);
            for (difference_type i = _size; i < _size + tmp.size(); i++)
            {
                _alloc.destroy(_data + i);
            }
            push_back(val);
            for (size_t i = _size; i < _size + tmp.size(); i++)
            {
                _alloc.construct(_data + i, tmp[k]);
                k++;
            }
            _size += k;
            return position;
        }
        template <class InputIterator>
        void insert(iterator position, InputIterator first, InputIterator last)
        {
            difference_type n = end() - position;
            difference_type m = last - first;
            ft::vector<value_type> tmp;
            tmp.assign(position, end());
            for (size_t i = position - begin(); i < _size; i++)
                _alloc.destroy(_data + i);
            if (_size + m > _capacity)
                reserve(_size + m);
            _size -= n;
            for (iterator it = first; it != last; it++)
            {
                push_back(*it);
            }
            for (size_t k = 0; k < tmp.size(); k++)
            {
                push_back(tmp[k]);
            }
        }
        iterator erase(iterator position)
        {
            size_t k = 0;
            ft::vector<value_type> tmp(position + 1, end());
            for (difference_type i = position - begin(); i < _size; i++)
                _alloc.destroy(_data + i);
            _size = position - begin();
            pop_back();
            for (size_t i = _size; i < _size + tmp.size(); i++)
                _alloc.construct(this->_data + i, tmp[k++]);
            _size += tmp.size();
            return position;
        }
        iterator erase(iterator first, iterator last)
        {
            ft::vector<value_type> tmp(last, end());
            iterator it = last + 1;
            size_t k = _size;
            for (difference_type i = first - begin(); i < k; i++)
                pop_back();
            for (size_t i = 0; i < tmp.size(); i++)
                push_back(tmp[i]);
            return it;
        }

        void swap(vector &x){
            
        }
    private:
        pointer _data;
        size_t _size;
        size_t _capacity;
        Alloc _alloc;
    };
}
#endif