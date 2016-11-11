#ifndef QUOTE_H
#define QUOTE_H
#include <string>
#include <iostream>

class Quote{
	public:
		Quote() = default;
		Quote(const std::string &book,double sales_price):
			bookNo(book),price(sales_price){}
		std::string isbn() const {return bookNo;}
		virtual double net_price(std::size_t n) const {
			return n*price;}
		virtual void debug() const;
		virtual ~Quote() = default;
	private:
		std::string bookNo;
	protected:
		double price = 0.0;
};
class Disc_quote:public Quote{
	public:
		Disc_quote() = default;
		Disc_quote(const std::string& book,double price,std::size_t qty,double disc):
			Quote(book,price),quantity(qty),discount(disc){}
		double net_price(std::size_t) const = 0;
	protected:
		std::size_t quantity = 0;
		double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
	public:
		Bulk_quote() = default;
		Bulk_quote(const std::string & book,double price,std::size_t qty,double disc):
			Disc_quote(book,price,qty,disc){}
		double net_price(std::size_t) const override;
	private:
		std::size_t min_qty = 0;
};

class Limit_quote: public Disc_quote {
	public:
		Limit_quote() = default;
		Limit_quote(const std::string book,double price,std::size_t max,double disc):
			Disc_quote(book,price,max,disc){}
		double net_price(std::size_t n)const override{
			return n*price*(n<quantity?1-discount:1);}
};

double Bulk_quote::net_price(size_t cnt)const {
	if(cnt>=min_qty)
		return cnt*(1-discount)*price;
	else
		return cnt*price;	
}

void Quote::debug() const{
	std::cout<<"data menbers of this class:\n"
			 <<"bookNo= "<<this->bookNo<<" "
		 	 <<"price= "<<this->price<<" ";
}

#endif
