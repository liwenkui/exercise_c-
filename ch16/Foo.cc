#include <string>
#include <iostream>
using namespace std;
template<typename T>class Foo{
	public:
		Foo(){++ctr;}
		static size_t count(){return ctr;}
	private:
		static size_t ctr;
};

template<typename T>
size_t Foo<T>::ctr=0;

int main(){
		Foo<string> fs;
	Foo<int> fi,fi2,fi3;
	cout<<fi3.count()<<endl;
	return 0;
}
