#ifndef STACK_HPP
#define STACK_HPP
#include "../vector/vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T>>
	class stack
	{
	protected:
		Container c;

	public:
		typedef Container container_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::size_type size_type;
		explicit stack(const container_type &ctnr = container_type()){
				c(ctnr)};
	 stack(const stack &st) { *this = &st; }
	~stack() {}
	size_t size() { return c.size() }
	bool empty() const {return c.empty()};
	value_type &top()
	{
		return c.back();
	}
	value_type &top() const
	{
		return c.back();
	}
	void push(const value_type &val)
	{
		c.push_back(val);
	}
	void pop()
	{
		c.pop_back();
	}
}
	template <class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
	template <class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
	template <class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
	template <class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
	template <class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
	template <class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs);
}

#endif