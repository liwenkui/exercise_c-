#include <iostream>
using namespace std;

class A{
	public:
		virtual void print(){
			cout<<B<<endl;}
		char A='A';
	protected:
		char B='B';
	private:
		char C='C';
};
class B:public A{
	public:
		B()=default;
		// unless we say otherwise,the base part of a derived object is default initialized.
	//	void print()override{
	//		cout<<D<<endl;}
	protected:
	private:
		char D ='D';
};

int main() {
	B b;
	A &a=b;
	a.print();
	return 0;
}
	
	

