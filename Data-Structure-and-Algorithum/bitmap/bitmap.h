#ifdef BITMAP_H
#define BITMAP_H

class Bitmap{
	private:
		char* M;
		int N;
	protected:
		void init(int n){M=new char[N=(n+7)/8];memset(M,0,N);}
	public:
		Bitmap(int n=8):N(n){}
		Bitmap(char*file,int n=8){
			init(n);
			FILE* fp=fopen(file,"r");
			fread(M,sizeof(char),N,fp);
			fclose(fp);
		}
	   ~Bitmap(){delete [] M;M=nullptr;}
   		void set(int k){expand(k); M[k>>3]|=(0x80>>(k&0x07));}	   
		void clear(int k){expand(k);M[k>>3]&=~(0x80>>(k&0x07));}
};
#endif
