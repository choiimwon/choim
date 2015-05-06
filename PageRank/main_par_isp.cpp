#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "PageRank_par.h"
#include "main.hpp"
#include "cstdlib"
#include "pthread.h"
using namespace std;

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

void *Run(void *arg)
{
	PageRank pr;
	PageRank::Elements elm = pr.Calc(arg);
	
	return arg;
}
int main(int argc, const char* argv[]){
	FILE * ifp;   
	int n;
  
	extern void s4_init_simulation();
	pthread_t p_thread[S4_NUM_BUFFERS];
	pthread_attr_t attr;
	PageRank::Elements arg[S4_NUM_BUFFERS];
	ifp = s4_fopen(argv[1],"r"); 
	
	vector<Node*> nodes;
	InitGraph(nodes);
   PageRank pr;
	int num = 40;	
	while((n=s4_pageread(0,S4_NUM_BUFFERS,ifp))>0)
	{
		for(int i=0;i<n;i++)
		{
			arg[i].nodes = nodes;
			arg[i].n = num;
			pthread_create(&p_thread[i], NULL, Run, (void *)&arg[i]);
		}
	}
	pr.PrintPageRank(nodes);
	extern void s4_wrapup_simulation();

	return 0;
}
