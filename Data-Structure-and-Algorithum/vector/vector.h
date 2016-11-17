#ifndef VECTOR
#define VECTOR
#define DEFAULT_CAPACITY 3
typedef int Rank;
template <typename T>
class Vector
{
	friend bool operator<(Vector const&,Vector const&);
	protected:
		Rank _size;
		int _capacity;
		T *_elem;
		void copyFrom(T const *, Rank, Rank);
		void expand();
		void shrink();
		bool bubble(Rank lo,Rank hi);
		void bubbleSort(Rank lo,Rank hi);
		Rank max(Rank lo,Rank hi);
		void selectinSort(Rank lo,Rank hi);
		void merge(Rank lo,Rank mi,Rank hi);
		void mergeSort(Rank lo,Rank hi);
		Rank partition (Rank lo, Rank hi);
		void quickSort(Rank lo,Rank hi);
		void heapSort(Rank lo,Rank hi);
	public:
		//constructor
		Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0):
			_capacity(c),_size(s)
		{
			_elem = new T[_capacity];
			for(int i=0;i!=_size;_elem[i++]=v);
		}
		Vector(T const *A, Rank n) {copyFrom(A,0,n);}
		Vector(T const *A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }
		Vector(Vector<T> const&V){copyFrom(V._elem,0,V._size);}
		Vector(Vector<T> const&V,Rank lo,Rank hi){copyFrom(V._elem,lo,hi);}
		//destructor
		~Vector() { delete[] _elem; }
		//read
		Rank size() { return _size; }
		bool empty() {return !_size;}
		int disordered() const;
		Rank find(T const &e) const { return find(e, 0, _size); }
		Rank find(T const &, Rank, Rank) const;
		Rank search(T const &e)const {return search(e, 0, _size);}
		Rank search(T const &,Rank, Rank) const;
		//write
		T &operator[](Rank r) const;
		Vector<T> &operator=(Vector<T> const &);
		T remove(Rank r);
		int remove(Rank lo, Rank hi);
		Rank insert(Rank r, T const &e);
		Rank insert(T const &e){return insert(_size,e);}
		void sort(Rank lo,Rank hi);
		void sort() {sort (0,_size);}
		void unsort(Rank lo, Rank hi);
		void unsort(){unsort(0,_size);}
		int deduplicate();
		int uniquify();
		//traverse
		void traverse(void(*) (T&));
		template <typename VST> void traverse (VST &);
};

template<typename T>
bool operator<(Vector<T> const &lh,Vector<T> const &rh){
	if(lh.size()<rh.size())
		return true;
	else if(lh._elem[0]<rh._elem[0])
		return true;
	else if(c_lh(lh).remove(0)<c_rh(rh).remove(0))
		return true;
	else
		return false;
}

#include "src.cc"
#endif
