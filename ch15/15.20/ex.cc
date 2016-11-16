
class Base{
	public:
		void pub_men();
	protected:
		int prot_mem;
	private:
		char priv_mem;
};

struct Pub_Derv:public Base{
	int f(){return prot_mem;}
	void memfcn(Base &b){b=*this;}
};	

struct Prot_Derv:protected Base{
	int f(){return prot_mem;}
	void memfcn(Base &b){b=*this;}
};

struct Priv_Derv:private Base{
	int f1(){return prot_mem;}
	void memfcn(Base &b){b=*this;}
};

struct Derived_from_Public:protected Pub_Derv{
	int use_base(){return prot_mem;}
	void memfcn(Base &b){b=*this;}
};
struct Derived_from_Private:public Priv_Derv{
	void memfcn(Base &b){b=*this;}
};
struct Derived_from_Protected:public Prot_Derv{
	int use_base(){return prot_mem;}
};

int main(){
	Base*p=new Pub_Derv;
	//Base*p1=new Prot_Derv;
	//Base*p2=new Derived_from_Protected;
	return 0;
}

