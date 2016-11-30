#include "../bintree/bintree.h"
typedef BinTree<char> PFCTree;

#include "../vector/vector.h"
typedef Vector<PFCTree*> PFCForest;

#include "../bitmap/bitmap.h"
#include "../skiplist/skiplist.h"
typedef Skiplist<char,char*>PFCTable;

#define N_Char (0x80 - 0x20)

PFCForest* initForest(){
	PFCForest* forest=new PFCForest;
	for(int i=0;i<N_Char;i++){
		forest->insert(i,new PFCTree());
		(*forest)[i]->insertAsRoot(0x20+i);
	}
	return forest;
}

PFCTree* generateTree(PFCForest* forest){
	srand((unsigned int)time(NULL));
	while(1<forest->size()){
		PFCTree* s =new PFCTree;
		s->insertAsRoot('^');
		Rank r1=rand()%forest->size();
		s->attachAsLC(s->root(),(*forest)[r1]);
		forest->remove(r1);
		Rank r2=rand()%forest->size();
		s->attachAsRC(s->root(),(*forest)[r2]);
		forest->remove(r2);
		forest->insert(forest->size(),s);
   	}
	return (*forest)[0];
}

