#include <iostream>
using namespace std;
int main(){
	int* n=nullptr;
	char* c=nullptr;
	int a=1;
	int* p=&a;
	int* p2=&a;
	cout<<(n-n)<<' '<<(p-p2)<<endl;
	cout<<((n+1)-n)<<endl;
	cout<<((p+1)-p2)<<endl;
	cout<<((p+2)-p2)<<endl;
	cout<<((p-1)-p2)<<endl;
	cout<<n<<endl;
	cout<<(n+1)<<endl;
	cout<<(n-1)<<endl;
	cout<<endl;
	cout<<(c+1)<<endl;
	cout<<(c-1)<<endl;
	return 0;
}
