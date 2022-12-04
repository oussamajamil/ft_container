#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP


#include "iterator_traits.hpp"

namespace ft{
    template<class Iterator> class reverse_iterator
    {
    protected:
        Iterator current;
    public:
        typedef Iterator iterator_type;
        typedef typename ft::iterator_traits<Iterator>::iterator_category iterator_category;
        typedef typename  ft::iterator_traits<Iterator>::value_type value_type;
        typedef typename  ft::iterator_traits<Iterator>::difference_type difference_type;
        typedef typename  ft::iterator_traits<Iterator>::pointer pointer;
        typedef typename  ft::iterator_traits<Iterator>::reference reference;


        reverse_iterator();
        //explicit 
        explicit reverse_iterator (iterator_type it){
            current = it;
        }
        template <class Iter>  reverse_iterator (const reverse_iterator<Iter>& rev_it){
            *this = rev_it;
        }
        ~reverse_iterator(){}
        iterator_type base()const {
            return current;
        }
        reference operator*()const {
            iterator_type tmp;
            tmp = current;
            return *--tmp;
        }
        reverse_iterator operator+(difference_type n)const {
            reverse_iterator tmp(current - n);
            return tmp;
        }
          reverse_iterator operator-(difference_type n)const {
            reverse_iterator tmp(current + n);
            return tmp;
        }
        reverse_iterator operator++(int)
        {
            reverse_iterator tmp = *this;
            ++(*this);
            return tmp;
        }
         reverse_iterator operator++()
        {
           current--;
           return *this;
        }
         reverse_iterator operator--(int)
        {
            reverse_iterator tmp = *this;
            --(*this);
            return tmp;
        }
         reverse_iterator operator--()
        {
           current++;
           return *this;
        }
          reverse_iterator operator+=(difference_type n)
        {
           current-=n;
           return *this;
        }
          reverse_iterator operator-=(difference_type n)
        {
           current+=n;
           return *this;
        }
           reverse_iterator operator->() const
        {
            return &(operator*());
        }
           reverse_iterator operator[](difference_type n)const
        {
            return current[-n-1];
        }
    };    
template <class Iterator>  
bool operator== (const reverse_iterator<Iterator>& t1,const reverse_iterator<Iterator>& t2){
    return t1.base() == t2.base();
}
template <class Iterator>  
bool operator!= (const reverse_iterator<Iterator>& t1,const reverse_iterator<Iterator>& t2){
    return t1.base() != t2.base();
}

template <class Iterator>  
bool operator< (const reverse_iterator<Iterator>& t1,const reverse_iterator<Iterator>& t2){
    return t1.base() < t2.base();
}

template <class Iterator>  
bool operator<= (const reverse_iterator<Iterator>& t1,const reverse_iterator<Iterator>& t2){
    return t1.base() <= t2.base();
}

template <class Iterator>  
bool operator>= (const reverse_iterator<Iterator>& t1,const reverse_iterator<Iterator>& t2){
    return t1.base() >= t2.base();
}

template <class Iterator>  
bool operator>(const reverse_iterator<Iterator>& t1,const reverse_iterator<Iterator>& t2){
    return t1.base() > t2.base();
}
template <class Iterator>  
bool operator+(typename reverse_iterator<Iterator>::difference_type n,const reverse_iterator<Iterator>& t2){
    return reverse_iterator<Iterator>(t2.base() -n);
}


template <class Iterator>  
typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& t1,const reverse_iterator<Iterator>& t2){
        return t1.base() - t2.base();
    }

}

#endif