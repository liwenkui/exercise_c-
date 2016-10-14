#include <iostream>
#include <string>
#include <fstream>
#include "Sales_data.h"
using namespace std;
int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    ofstream out(argv[2], ofstream::app);

    Sales_data total(in);
    if (!total.isbn().empty())
    {
	Sales_data trans;
	while (read(in, trans))
	{
	    if (total.isbn() == trans.isbn())
	    {
		total.combine(trans);
	    }
	    else
	    {
		print(cout, total) << endl;
		total = trans;
	    }
	    print(cout, total) << endl;
	}
    }
    else
    {
	cerr << "no data?!" << endl;
	return -1;
    }
    return 0;
}