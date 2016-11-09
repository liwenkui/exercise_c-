#include <iostream>
#include <string>
#include "Sales_data.h"
using namespace std;

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

inline double Sales_data::avg_price() const
{
    double avg;
    avg = revenue / units_sold;
    return avg;
}

Sales_data::Sales_data(istream &is) : Sales_data()
{
	is>>*this;
}

Sales_data operator+(const Sales_data &lhs,const Sales_data &rhs)
{
	Sales_data sum=lhs;
	sum.combine(rhs);
	return sum;
}
istream &operator>>(istream &is, Sales_data &item)
{
	double price=0;
       is>>item.BookNo>>item.units_sold>>price;
       if(is)
	item.revenue=price*item.units_sold;
       else
	       item =Sales_data();
 	return is;
}	
Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
	units_sold+= rhs.units_sold;
	revenue+=rhs.revenue;
	return *this;
}

ostream &operator<<(ostream &os,const Sales_data &item)
{
	os<<item.isbn()<<" "<<item.units_sold<<" "
		<<item.revenue<<" "<< item.avg_price();
	return os;
}
bool compareIsbn(Sales_data const &lo, Sales_data const &hi)
{
    return lo.isbn().size() < hi.isbn().size();
}
Sales_data& Sales_data::operator-=(const Sales_data&rhs)
{
	units_sold-=rhs.units_sold;
	revenue-=rhs.revenue;
	return *this;
}
Sales_data operator-(const Sales_data &lhs,const Sales_data &rhs)
{
	Sales_data sum=lhs;
	sum-=rhs;
	return sum;
}
bool operator==(const Sales_data&lhs,const Sales_data&rhs){
	return lhs.isbn()==rhs.isbn()&&lhs.units_sold==lhs.units_sold&&
		lhs.revenue==rhs.revenue;
}
bool operator!=(const Sales_data&lhs,const Sales_data&rhs){
	return !(lhs==rhs);
}


