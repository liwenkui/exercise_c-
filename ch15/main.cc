#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Quote.h"
using namespace std;

double print_total(ostream &os, const Quote &item ,size_t n)
{
	double ret = item.net_price(n);
	os<<"ISBN: "<<item.isbn()
		<<" # sold: "<<n<<" total due: "<<ret<<endl;
	return ret;
}	

int main(int argc,char* argv[]){
	vector<shared_ptr<Quote>> basket;
	Quote a("isbn-111",11.1);
	Bulk_quote b("isbn-111",11.10,11,0.5,3.0);
	basket.push_back(make_shared<Quote>(a));
	basket.push_back(make_shared<Quote>(b));
	cout<<basket.back()->net_price(15)<<endl;
	return 0;
}

