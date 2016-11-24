#include <iostream>
#include "test2.cc"
using namespace std;
int j1=1;
constexpr int j2=2;
int main(){
	char a1=0;
	short a2=0;
	int a3=0;
	long a4=0;
	long long a5=0;
	float f1=0.0;
	double f2=0.0;
	long double f3=0.0;
	char a[]="A";
	
	cout<<sizeof(a1)<<endl;
	cout<<sizeof(a2)<<endl;
	cout<<sizeof(a3)<<endl;
	cout<<sizeof(a4)<<endl;
	cout<<sizeof(a5)<<endl;
	cout<<sizeof(f1)<<endl;
	cout<<sizeof(f2)<<endl;
	cout<<sizeof(f3)<<endl;
	cout<<sizeof(a)<<endl;
	cout<<sizeof(L'a')<<endl;
	cout<<sizeof(L"a")<<endl;
	static  int num;
	cout<<num<<endl;
	int num2;
	cout<<num2<<endl;
	extern int a6;
	extern int b;
	cout<<b<<endl;
	double d=3.14;
	void *vp=&d;
	double *dp=static_cast<double*>(vp);
	int *ip=static_cast<int *>(vp);//resault is undefined
    cout<<*dp<<endl;	
	cout<<*ip<<"  resault is undefined"<<endl;
	extern const int b1;
	cout<<b1<<endl;
	int const &b2=b1;
	const int &b3=b2;
	int &&a7=13;
	int *const p1=&a7;
	*p1=12;	
	cout<<p1<<' '<<*p1<<endl;
	cout<<a7<<endl;
	constexpr int*p3=&j1;
	constexpr const int *p4=&j2;
	cout<<*p3<<' '<<*p4<<endl;
	//constexpr int *p4=&j2;
	//constexpr impose top-level const,

	return 0;
}
