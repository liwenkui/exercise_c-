#ifndef QUOTE_H
#define QUOTE_H
#include <string>
#include <iostream>

class Quote{
	public:
		Quote():bookNo(std::string()),price(0.0){}
		Quote(const Quote& orig):bookNo(orig.bookNo),price(orig.price){
		} 
		Quote(Quote &&orig):bookNo(orig.bookNo),price(orig.price){
		} 
		Quote(const std::string &book,double sales_price):
			bookNo(book),price(sales_price){
			}
		virtual Quote* clone() const & {return new Quote(*this);}
		virtual Quote* clone() const &&{return new Quote(std::move(*this));}
		std::string isbn() const {return bookNo;}
		Quote& operator=(const Quote& rh){
			bookNo=rh.bookNo;
			price=rh.price;
			return *this;
		}
		virtual double net_price(std::size_t n) const {
			return n*price;}
		virtual void debug() const;
		virtual ~Quote() {
		}
	private:
		std::string bookNo;
	protected:
		double price = 0.0;
};
class Disc_quote:public Quote{
	public:
		Disc_quote():Quote(),quantity(0),discount(0.0){

		} 
		Disc_quote(const Disc_quote& orig):Quote(orig),quantity(orig.quantity)
										   ,discount(orig.discount){
										   }
		Disc_quote(Disc_quote&& orig):Quote(std::move(orig)),quantity(orig.quantity),
		discount(orig.discount){
		}
		Disc_quote(const std::string& book,double price,std::size_t qty,double disc):
			Quote(book,price),quantity(qty),discount(disc){}
		Disc_quote& operator=(const Disc_quote&rh){
			Quote::operator=(rh);
			quantity=rh.quantity;
			discount=rh.discount;
			return *this;
		}		
		double net_price(std::size_t) const = 0;
		~Disc_quote(){
		}
	protected:
		std::size_t quantity = 0;
		double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
	public:
		Bulk_quote() = default;
		Bulk_quote(const std::string & book,double price,std::size_t qty,double disc
				,double mqty):Disc_quote(book,price,qty,disc),min_qty(mqty){}
		Bulk_quote(const Bulk_quote&)=default;
		Bulk_quote(Bulk_quote &&)=default;
		Bulk_quote* clone() const & override{return new Bulk_quote(*this);}
		Bulk_quote* clone() const &&override{return new Bulk_quote(std::move(*this));}
		Bulk_quote& operator=(const Bulk_quote &rh){
			Disc_quote::operator=(rh);
			min_qty=rh.min_qty;
			return *this;
		}
		double net_price(std::size_t) const override;
		~Bulk_quote(){
			std::cout<<"Bulk_quote distructor"<<std::endl;
		}
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
