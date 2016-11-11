
class Base{
	public:
		virtual void memfcn(Base& b){b=*this;}
	protected:
		int a=0;
	private:
		int c=0;
};

class Pub_Derv:public Base{
	public:
		void memfcn(Base& b) override {b=*this;} 
	protected:
		int b=0;
	private:
		int d=0;
};

int main(){
	Pub_Derv a;
	Base *p = &a;
	return 0;
}
