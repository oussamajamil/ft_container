/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:34:19 by ojamil            #+#    #+#             */
/*   Updated: 2022/09/25 04:37:49 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include "./iterators_traits.hpp"

namespace ft{
	template < class T>
	class iterator{
		private:
			pointer data;
		public:
		typedef typename ft::iterator_traits<T>::difference_type  difference_type;
		typedef typename ft::iterator_traits<T>::pointer  pointer;
		typedef typename ft::iterator_traits<T>::reference  reference;
		typedef typename ft::iterator_traits<T>::iterator_category  iterator_category;
		typedef typename  T value_type;

		iterator(){}
		iterator(const iterator& data){
			*this = data;
		}
		iterator(const iterator& data){
			this = data.data;
		}
		iterator& operator= (const iterator& data)const{
			if(this != data){
				this->data = data.data
			}
			return *this;
		}
		~iterator(){}

		iterator& operator++ ()const{
			this->data++;
			return *this;
		}
		iterator& operator++ (int)const{
			pointer tmp = this;
			this->data++;
			return tmp;
		}
		iterator& operator-- ()const{
			this->data--;
			return *this;
		}

		iterator& operator-- (int)const{

			pointer tmp = this;
			this->data--;
			return tmp;
		}
		iterator& operator[](key)const{
			return this->data+key;
		}
		iterator& operator == (iterator &comp) const{
			return comp.data == this->data;
		}
		iterator& operator != (iterator &comp) const{
			return comp.data != this->data;
		}
		iterator& operator < (iterator &comp) const{
			return comp.data < this->data;
		}
		iterator& operator > (iterator &comp) const{
			return comp.data > this->data;
		}
		iterator& operator >= (iterator &comp) const{
			return comp.data > this->data;
		}
		iterator& operator <= (iterator &comp) const{
			return comp.data > this->data;
		}
		iterator& operator + (iterator &comp) const{
			return iterator(comp.data + this->data);
		}
		iterator& operator - (iterator &comp) const{
			return iterator(comp.data - this->data);
		}

		iterator& operator += (iterator &comp) const{
			return this->data  + comp.data;
		}
		iterator& operator -= (iterator &comp) const{
			return this->data  - comp.data;
		}

		T& base(){
			
		}
	}
}


#endif;
