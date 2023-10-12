#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

	private:
		    T* arr;
		    int max;//tamañano array
		    int n;//número de elementos
		    static const int MINSIZE=2;
		    void resize(int new_size) {
			 T* new_arr = new T[new_size];
				 for (int i=0; i < n; i++) {
                                     new_arr[i] = arr[i];
				      }
			 delete[] arr;
			 arr = new_arr;
			 max = new_size;
		     }

	public:
		    ListArray() : max(MINSIZE), n(0) {
			 arr = new T[MINSIZE];
			 }

		    ~ListArray() {
			 delete[] arr;
			   }

		    T operator[](int pos) {
			    if (pos < 0 || pos >= n) {
				    throw std::out_of_range("No existe esa posicón en ListArray.");
					        }
			        return arr[pos];
	                 	} 

		    friend std::ostream& operator<<(std::ostream& out, const ListArray<T>& list) {
			     out << "[";
			     for (int i = 0; i < list.n; i++) {
					 out << list.arr[i];
					 if (i < list.n - 1) {
						 out << ". ";
							 }
					 }
					     out << "]";
					 return out;
		          }
//implmentación de LIST
		    void insert(int pos, T e){
			    if(pos < 0||pos >n){
				    throw std::out_of_range("Posición fuera de rango");
			    }
			    if (n==max) {
				    resize(max*2);
			    }
			    for(int i=n; i>pos; i--) {
				    arr[i]=arr[i-1];
                                         }
			    arr[pos]=e;
			    
		    }
		    void append(T e){
			    if(n==max){
				    resize(max*2);
			    }
			    arr[n]=e;
			    n++;
		    }
		    void preppend(T e){
			    if(n==max){
				    resize(max*2);
			    }
			    for (int i=n; i > 0; i--){
				     arr[i]=arr[i - 1];
			    }
			    arr[0]=e;
			    n++;
		    }
		    T remove(int pos){
			    if(pos<0 || pos>n){
				    throw std::out_of_range("Posición fuera de rango");
			    }
			T relement=arr[pos];
			for(int i= pos; i<n-1; i++){
				arr[i]=arr[i+1];
			}
			if(max>2*n){
				resize(max/2);
			}
			n--;
			return relement;
		    }
		   T get(int pos){
			   if(pos>0||pos>n){
				   throw std::out_of_range("fuera de rango");
			   }
			   T element=arr[pos];
			   return element;
		   }
                   int search(T e){
			   for( int i=0; i<n; i++){
				   if(arr[i]==e){
					   return i;
				   }
			   }
			   return -1;
		   }
		   bool empty(){
			   return n==0;
		   }
		   int size(){
			   return n;
		   }
    };

