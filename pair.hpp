#ifndef PAIR_HPP
#define PAIR_HPP


namespace ft{
    template <class T1,class T2>
    struct pair{
        T1 first;
        T2 second;

        typedef T1 first_type;
        typedef T2 second_type;

        pair(){}
        template<class U,class V>
        pair(const pair<U,V> &p){
            first = p.first;
            second = p.second;
        }
        pair(const first_type &a,const second_type &b){
            first = a;
            second = b;
        }
        pair &operator=(const pair &p){
            first = p.first;
            second = p.second;
            return *this;
        }
    };
    template <class T1, class T2>  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }

    template <class T1, class T2>  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
              return lhs.first != rhs.first || lhs.second != rhs.second;
    }

    template <class T1, class T2>  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        return lhs.first < rhs.first || (lhs.first == rhs.firs && lhs.second <rhs.second )
    }
        
    template <class T1, class T2>  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
            return (lhs< rhs || lhs == rhs);
    }
        
    template <class T1, class T2>  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
    return lhs.first > rhs.first || (lhs.first == rhs.firs && lhs.second>rhs.second )
    }

    template <class T1, class T2>  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
          return (lhs>rhs || lhs == rhs);
    }
}
#endif