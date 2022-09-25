/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookprom12020 <macbookprom12020@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:05:31 by ojamil            #+#    #+#             */
/*   Updated: 2022/09/24 15:59:52 by macbookprom      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <memory>
#include <memory>

namespace ft
{
	template <class T, class Alloc = std::allocator<T>>
	class vector
	{
	private:
		size_type _size;
		size_type _capacity;
		value_type *_data;
		Alloc alloc;

	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef std::size_t size_type;
		explicit vector(const allocator_type &alloc = allocator_type())
		{
			this->_size = 0;
			this->_capacity = 0;
			this->_data = nullptr;
			this->alloc = alloc;
		}
		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
		{
			this->alloc = alloc;
			this->_size = n;
			this->_capacity = n;
			this->_data = this->alloc.allocate(this->_capacity);
			for (std::size_t i = 0; i < n; i++)
			{
				arr[i] = val
			}
		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
					 const allocator_type &alloc = allocator_type()){

		};
		vector(const vector &x)
		{
			*this = x;
		};
		
	}


	////////
	// template<typename T>
	// class Vector
	// {
	// private:
	// 	size_t vCapcity ;
	// 	size_t vSize ;
	// 	T* v_Data;

	// void realloc (size_t newCapacity){
	// 		std::allocator<T> myAllocatore;
	// 		T* newVectore =myAllocatore.allocate(newCapacity);
	// 		if(newCapacity < this->vSize){
	// 			this->vSize = newCapacity;
	// 		}
	// 		for (size_t i= 0; i < this->vSize;i++){
	// 			newVectore[i] =std::move(this->v_Data[i]);
	// 		}
	// 		myAllocatore.deallocate(this->v_Data,this->vCapcity);
	// 		this->v_Data = newVectore;
	// 		this->vCapcity = newCapacity;
	// 	}
	// public:

	// 	Vector(){
	// 		this->v_Data = nullptr;
	// 		this->vSize = 0;
	// 		this->vCapcity = 0;
	// 		this->realloc(2);
	// 	};
	// 	void push_back(const T& value){
	// 		if(this->vSize  == this->vCapcity){
	// 			realloc(this->vCapcity + this->vCapcity/2);
	// 		}
	// 		this->v_Data[this->vSize++] = value;
	// 	}

	// 	// template <typename ...Args>
	// 	// T& emplace_back(Args&&... args){
	// 	// 	if(this->vSize  == this->vCapcity){
	// 	// 		realloc(this->vCapcity + this->vCapcity/2);
	// 	// 	}
	// 	// 	this->v_Data[this->vSize] = T(std::forward<Args>(args)...);
	// 	// 	return this->v_Data[this->vSize++];
	// 	// }

	// 	const  T& operator[](size_t index) const{
	// 		return this->v_Data[index];
	// 	}
	// 	T& operator[](size_t index) {
	// 		return this->v_Data[index];
	// 	}

	// 	~Vector(){
	// 			std::allocator<T> myAllocatore;
	// 			myAllocatore.deallocate(this->v_Data,this->vCapcity);
	// 	};

	// 	//////****************     Capacity ******************//////

	// 	size_t size()const {
	// 		return this->vSize;
	// 	}

	// 	size_t max_size(){
	// 		std::allocator<T> myAllocatore;
	// 		return myAllocatore.max_size();
	// 	}
	// 	size_t capacity(){

	// 	}
	// };

#endif