#ifndef GRAPH_LIST
#define GRAPH_LIST
#include "Graph.h"
#include "../vector/vector.h"
#include "../list/List.h"

template <typename Tv>
struct Vertex
{
	Tv data;
	int inDegree, outDegree;
	VStatus status;
	int dTime, fTime;
	int parent;
	int priority;
	Vertex(Tv const &d = (Tv)0) : data(d), inDegree(0), outDegree(0), status(UNDISCOVERED),
	dTime(-1), fTime(-1), parent(-1), priority(INT_MAX) {}
};

template <typename Te>
struct Edge
{
	Te data;
	int weight;
	EType type;
	int v;
	Edge(Te const d, int w) : data(d), weight(w), type(UNDETERMINED) {}
};

template<typename Tv,typename Te>
class GraphList:public Graph<Tv,Te>{
	private:
		Vector<Vertex<Tv>> V;
		Vector<List<Edge<Te>*>> E;
	public:
		using Graph<Tv,Te>::n;
		using Graph<Tv,Te>::e;
		GraphList(){n=e=0;}
		~GraphList(){}
		virtual Tv &vertex(int i) { return V[i].data; }
		virtual int inDegree(int i) { return V[i].inDegree; }
		virtual int outDegree(int i) { return V[i].outDegree; }
		virtual int firstNbr(int i) { return nextNbr(i, n); }
		virtual int nextNbr(int i, int j)
		{
			while ((-1 < j) && (!exists(i, --j)))
				;
			return j;
		}
		virtual VStatus &status(int i) { return V[i].status; }
		virtual int &dTime(int i) { return V[i].dTime; }
		virtual int &fTime(int i) { return V[i].fTime; }
		virtual int &parent(int i) { return V[i].parent; }
		virtual int &priority(int i) { return V[i].priority; }

		virtual bool exists(int i,int j){
			if((0<=i)&&(i<n)&&(0<=j)&&(j<n)){
				auto p=E[i].first();
				auto s=E[i].size();
				while(s--){
					if(p->data->v==j)
						return true;
					p=p->succ;
				}
				return false;
			}
			return false;
		}

};
#endif
