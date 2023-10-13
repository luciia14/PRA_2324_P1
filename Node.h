#include <ostream>

template <typename T> 
class Node {
	    public:
		T data;//elemento
		Node<T>* next;//puntero al siguiente nodo
		Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}
		friend std::ostream& operator<<(std::ostream &out, const Node<T> &node) {
			out << node.data;
			    return out;
		}
           };  
