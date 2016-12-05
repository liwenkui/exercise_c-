#include "Graph.h"
#include "../queue/queue.h"
#include "../stack/stack.h"

template<typename Tv,typename Te>
void Graph<Tv,Te>::bfs(int s){
	reset();
	int clock = 0;
	int v = s;
	do
		if(UNDISCOVERED == status(v))
			BFS(v,clock);
	while(s!=(v=(++v%n)));
}
template<typename Tv,typename Te>
void Graph<Tv,Te>::dfs(int s){
	reset();
	int clock = 0;
	int v = s;
	do
		if(UNDISCOVERED == status(v))
			DFS(v,clock);
	while(s!=(v=(++v%n)));
}
template<typename Tv,typename Te>
void Graph<Tv,Te>::BFS(int v,int& clock){
	Queue<int> Q;
	status(v) = DISCOVERED;
	Q.enqueue(v);
	while(!Q.empty()){
		int v = Q.dequeue();
		// visit()
		dTime(v) = ++clock;
		for(int u=firstNbr(v);-1<u;u=nextNbr(v,u))
			if(UNDISCOVERED==status(u)){
				status(u) = DISCOVERED;
				Q.enqueue(u);
				type(v,u)=TREE;
				parent(u)=v;
			}else{//discovered or visited state
				type(v,u)=CROSS;
			}
		status(v)=VISITED;
	}
}

template<typename Tv,typename Te>
void Graph<Tv,Te>::DFS(int v,int&clock){
	dTime(v)=++clock;
	status(v)=DISCOVERED;
	for(int u=firstNbr(v);-1<u;u=nextNbr(v,u))
		switch(status(u)){
			case UNDISCOVERED:
				type(v,u) = TREE;parent(u)=v;DFS(u,clock);break;
			case DISCOVERED:
				type(v,u) = BACKWARD;break;	
			default:
				status(v,u) = dTime(v)<dTime(u)?FORWARD:CROSS;break;	
		}
	status(v)=VISITED;
	fTime(v)=++clock;
}

template<typename Tv,typename Te>
void Graph<Tv,Te>::DFS_I(int v,int&clock){
	Stack<int> path;
	path.push(v);
	status(v)=DISCOVERED;
	dTime(v)=++clock;
	while(!path.empty()){
		v=path.top();
		int p_clock=clock;
		for(int u=firstNbr(v);-1<u;u=nextNbr(v,u)){
			switch(status(u)){
				case UNDISCOVERED:
					type(v,u) = TREE;parent(u)=v;status(u)=DISCOVERED;
					dTime(u)=++clock;
					path.push(u);break;
				case DISCOVERED:
					type(v,u) = BACKWARD;break;
				default:
					status(v,u) = dTime(v)<dTime(u)?FORWARD:CROSS;break;	
			}
			if(u==path.top()) break;//判断，是否有入栈，同样可以用 p_clock!=clock来判断是否有入栈
		}
		//如果入栈时钟必然变化，这是不能弹出
		if(p_clock==clock){
			status(v)=VISITED;
			fTime(v)=++clock;
			path.pop();
		}
	}
}
template<typename Tv,typename Te>
Stack<Tv>* Graph<Tv,Te>::tSort(int s){
	reset();
	int clock = 0;
	int v=s;
	Stack<Tv>* S = new Stack<Tv>;
	do{
		if(UNDISCOVERED == status(v))
			if(!TSort(v,clock,S)){
				while(!S->empty())
					S->pop();break;
			}
	}while(s!=(v=(++v%n)));
	return S;
}
template<typename Tv,typename Te>
bool Graph<Tv,Te>::TSort(int v,int&clock,Stack<Tv>* S){
	dTime(v)=++clock;
	status(v)=DISCOVERED;
	for(int u=firstNbr(v);-1<u;u=nextNbr(v,u))
		switch(status(u)){
			case UNDISCOVERED:
				parent(u)=v;type(u,v)=TREE;
				if(!TSort(u,clock,S))
					return false;
				break;
			case DISCOVERED:
				type(v,u)=BACKWARD;
				return false;	
			default:
				type(v,u)=(dTime(v)<dTime(u))?FORWARD:CROSS;
				break;
		}
	status(v)=VISITED;
	S->push(vertex(v));
	return true;
}

template<typename Tv,typename Te>template <typename PU>
void Graph<Tv,Te>::pfs(int s,PU prioUpdater){
	reset();
	int v=s;
	do
		if(UNDISCOVERED==status(v))
			PFS(v,prioUpdater);
	while(s!=(v==(++v%n)));
}

template<typename Tv,typename Te>template<typename PU>
void Graph<Tv,Te>::PFS(int s,PU prioUpdater){
	priority(s)=0;
	status(s)=VISITED;
	parent(s)=-1;
	while(1){
		for(int w=firstNbr(s);-1<w;w=nextNbr(s,w))
			prioUpdater(this,s,w);
		for(int shortest=INT_MAX,w=0;w<n;w++)
			if(UNDISCOVERED==status(w))
				if(shortest>priority(w))
				{shortest=priority(w);s=w;}
		if(VISITED==status(s))break;
		status(s)=VISITED;type(parent(s),s)=TREE;
	}
}

template<typename Tv,typename Te>struct BfsPU{
	virtual void operator()(Graph<Tv,Te>* g,int uk,int v){
		if(g->status(v)==UNDISCOVERED)
			if(g->priority(v)>g->priority(uk)+1){
				g->priority(v)=g->priority(uk)+1;
				g->parent(v)=uk;
			}
	}
};
