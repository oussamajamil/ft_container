#ifndef ITERATORS_TRAITS_HPP
#define ITERATORS_TRAITS_HPP

#include <iostream>
namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t,
						class Pointer = T *, class Reference = T &>
	struct iterator
	{
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};

	template <class Iterator>
	class iterator_traits
	{
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};
	template <class T>
	class iterator_traits<T *>
	{
		typedef typename T value_type;
		typedef typename str::ptrdiff_t difference_type;
		typedef typename T* pointer;
		typedef typename T& reference;
		typedef typename std::random_access_iterator_tag iterator_category;
	};
	template <class T>
	class iterator_traits<const T *>
	{
		typedef typename T value_type;
		typedef typename str::ptrdiff_t difference_type;
		typedef typename const T* pointer;
		typedef typename const T& reference;
		typedef typename std::random_access_iterator_tag iterator_category;
	}
}
#endif