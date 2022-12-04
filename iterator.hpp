#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <cstddef>
#include <stddef.h>
namespace ft
{
    template <class T>
    class random_access_iterator
    {
    private:
        T *prai;

    public:
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T &reference;
        typedef std::random_access_iterator_tag iterator_category;

        random_access_iterator() {}
        random_access_iterator(const random_access_iterator &obj)
        {
            prai = obj.prai;
        }

        random_access_iterator &operator=(const random_access_iterator &obj)
        {
            prai = obj.prai;
            return *this;
        }

        random_access_iterator(const pointer t)
        {
            prai = t;
        }
        ~random_access_iterator() {}
        bool operator==(const random_access_iterator &obj)
        {
            return prai == obj.prai;
        }
        bool operator!=(const random_access_iterator &obj)
        {
            return prai != obj.prai;
        }
        reference operator*()
        {
            return *prai;
        }
        T *operator->()
        {
            return prai;
        }
        random_access_iterator &operator++()
        {
            prai++;
            return *this;
        }
        random_access_iterator &operator--()
        {
            prai--;
            return *this;
        }
        random_access_iterator operator++(int)
        {
            random_access_iterator tmp;
            tmp = *this;
            ++prai;
            return tmp;
        }
        random_access_iterator operator--(int)
        {
            random_access_iterator tmp;
            tmp = *this;
            --prai;
            return tmp;
        }
        random_access_iterator &operator+(int n)
        {
            prai += n;
            return *this;
        }
        random_access_iterator &operator-(int n)
        {
            prai -= n;
            return *this;
        }
        random_access_iterator &operator-=(int n)
        {
            prai -= n;
            return *this;
        }
        random_access_iterator &operator+=(int n)
        {
            prai += n;
            return *this;
        }
        //  operator random_access_iterator<const T>()const{
        //     return (random_access_iterator<const T> (prai));
        //  }
        T &operator[](int n)
        {
            return prai[n];
        }
        T *base() const
        {
            return prai;
        }
    };
    template <class T1, class T2>
    bool operator<(const random_access_iterator<T1> &t1, const random_access_iterator<T2> &t2)
    {
        return t1.base() < t2.base();
    }
    template <class T1, class T2>
    bool operator>(const random_access_iterator<T1> &t1, const random_access_iterator<T2> &t2)
    {
        return t1.base() > t2.base();
    }

    template <class T1, class T2>
    bool operator>=(const random_access_iterator<T1> &t1, const random_access_iterator<T2> &t2)
    {
        return t1.base() >= t2.base();
    }
    template <class T1, class T2>
    bool operator<=(const random_access_iterator<T1> &t1, const random_access_iterator<T2> &t2)
    {
        return t1.base() <= t2.base();
    }
    template <class T1, class T2>
    typename random_access_iterator<T1>::difference_type operator-(const random_access_iterator<T1> &t1, const random_access_iterator<T2> &t2)
    {
        return t1.base() - t2.base();
    }
    template <class T1, class T2>
    bool operator==(const random_access_iterator<T1> &t1, const random_access_iterator<T2> &t2)
    {
        return t1.base() == t2.base();
    }
    template <class T1, class T2>
    bool operator!=(const random_access_iterator<T1> &t1, const random_access_iterator<T2> &t2)
    {
        return t1.base() != t2.base();
    }
}
#endif