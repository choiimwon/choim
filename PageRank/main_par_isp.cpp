#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "PageRank.h"
#include "main.hpp"
#include "cstdlib"
using namespace std;
struct CalArgument{
	vector <Node*> nodes;
	int n;
};
void InitGraph(vector<Node*> & nodes)
{
	int index;
	for(int i=0;i<1000;i++){		
		Node * node = new Node(i+1);
		nodes.push_back(node);	
	}
	for(int j=0;j<1000;j++)
	{
		index = rand()%nodes.size();
		Node * target = nodes.at(index);
		Node * target2 = nodes.at(j);
		target2->InsertLinkdInNode(target);
	}
}
void *Calc(void* theArg)
{
	PageRank pr;
	struct CalArgument* arg = (struct CalArgument*)theArg;
	pr.Calc(arg->nodes,arg->n);
	pr.PrintPageRank(arg->nodes);
}

int main(int argc, const char* argv[]){
	FILE * ifp;   
	int n;
  
	extern void s4_init_simulation();
	
	ifp = s4_fopen(argv[1],"r"); 
	pthread_t p_thread[S4_NUM_BUFFERS];
	struct CalArgument arg[S4_NUM_BUFFERS];
	//create node
	vector<Node*> nodes;
	InitGraph(nodes);
   PageRank pr;
	// culating pagerank 5 times
	while((n=s4_pageread(0,S4_NUM_BUFFERS,ifp))>0)
	{
		for(int i=0;i<n;i++)
		{
			arg[i].nodes = nodes;
			arg[i].n = 40;
			pthread_create(&p_thread[i], NULL, Calc, (void *)&arg[i]);		
		}
		for(int i=0;i<n;i++)
		{
			pthread_join(p_thread[i],NULL);
		}
	
	}
	extern void s4_wrapup_simulation();

	return 0;
}
