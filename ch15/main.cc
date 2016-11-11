#include <iostream>
#include <string>
#include <iostream>
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
	Quote a("isbn-111",11.1);
	Bulk_quote b("isbn-111",11.1,11,0.5);

	return 0;
}

