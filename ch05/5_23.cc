#include <iostream>
#include <exception>
#include <stdexcept>

int main(){
	int num1,num2;
	int ans=0;
	std::cout<<"input two number"<<std::endl;
	while(std::cin>>num1>>num2){
		try{
			if(num2==0)
				throw std::invalid_argument("num2 must not be 0");
			ans=num1/num2;
		}catch(std::invalid_argument err){
			std::cout<<err.what()<<std::endl;
			std::cout<<"try again? y/n"<<std::endl;
			char c;
			std::cin>>c;
			if(!std::cin||c=='n')
				break;
		}
	}
	std::cout<<ans<<std::endl;
	return 0;
}
