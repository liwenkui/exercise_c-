#include <iostream>
#include <exception>
#include <stdexcept>

int main(){
	int num1,num2;
	int ans=0;
	std::cout<<"input two number"<<std::endl;
	while(std::cin>>num1>>num2){
		if(num2==0)
			throw std::invalid_argument("num2 must no be 0");
	}
	std::cout<<ans<<std::endl;
	return 0;
}
