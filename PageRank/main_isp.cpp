#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "PageRank.h"
#include "main.hpp"
#include "cstdlib"
using namespace std;

void InitGraph(vector<Node*> & nodes)
{
	int index;
	for(int i=0;i<100;i++){		
		Node * node = new Node(i+1);
		nodes.push_back(node);	
	}
	for(int j=0;j<100;j++)
	{
		index = rand()%nodes.size();
		Node * target = nodes.at(index);
		Node * target2 = nodes.at(j);
		target2->InsertLinkdInNode(target);
	}
}


int main(int argc, const char* argv[]){
	FILE * ifp;   
	int n;
  
	extern void s4_init_simulation();
	
	ifp = s4_fopen(argv[1],"r"); 
	
	//create node
	vector<Node*> nodes;
	InitGraph(nodes);
   PageRank pr;
	// culating pagerank 5 times
	while((n=s4_pageread(0,S4_NUM_BUFFERS,ifp))>0)
	{
			pr.Calc(nodes,40);
	}
	pr.PrintPageRank(nodes);
	extern void s4_wrapup_simulation();

	return 0;
}
