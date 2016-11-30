#ifndef GRAPH_LIST
#define GRAPH_LIST
#include "../vector/vector.h"
#include "../list/List.h"

template<typename Tv,typename Te>
class GraphList:public Graph<Tv,Te>{
	private:
		Vector<Vertex<Tv>> V;
		Vector<List<Edge<Te>*>> E;
	public:
		
};
#endif
