#ifndef STRING_H
#define STRING_H
#include <memory>
#include <initializer_list>
class String{
	public:
	String()=default;
	String(const char *cp):sz(std::strlen(cp)),p(a.allocate(sz)){
		std::uninitialized_copy(cp,cp+sz,p);}
	String(const String&s):sz(s.sz),p(a.allocate(sz)){
		std::uninitialized_copy(s.p,s.p+sz,p);}
	String(String &&s)noexcept:sz(s.size()),p(s.p){
		s.p=nullptr;
		s.sz=0;}
	String(size_t n,char c):sz(n),p(a.allocate(sz)){
		std::uninitialized_fill_n(p,sz,c);}
	String &operator=(const String&);
	String &operator=(String &&);
	~String()noexcept {if(p) a.deallocate(p,sz);}
	
	String &operator=(const char*);
	String &operator=(char);
	String &operator=(std::initializer_list<char>);
	const char *begin(){return p;}
	const char *cbegin()const {return p;}
	const char *end() {return p+sz;}
	const char *cend() {return p+sz;}
	size_t size()const {return sz;}
	void swap(String &s)
	{auto tmp =p;
		p=s.p;
		s.p=tmp;
		auto cnt=sz;
		sz=s.sz;
		s.sz=cnt;}
	private:
	std::size_t sz=0;
       	static std::allocator<char> a;
	char *p =nullptr;
};
std::allocator<char>String::a;
#endif
