#include <iostream>
#include "PageRank_par.h"
using namespace std;


PageRank::PageRank(double q) : q_(q)
{
    // q_ must < 1
}

PageRank::~PageRank(void)
{
}

PageRank::Elements PageRank::Calc(void* arg)
{
	PageRank::Elements elements = *((PageRank::Elements *)arg);
	int n = elements.n;
	vector<Node *> nodes = elements.nodes;
		
		for(int i=0;i<n;i++)
		{
      	vector<Node*>::const_iterator citr = nodes.begin();
      	for (; citr!=nodes.end(); ++citr)
        	{
				Node * node = *citr;
				double pr = node->CalcRank();
       		if (pr < 0.00000000000000000000001 && pr > -0.00000000000000000000001) //pr == 0
		  		{
		   		pr = 1-q_;
		  		}
		  		else
		  		{
		      	 pr = pr * q_ + 1-q_;
		  	 	}
		   
				node->Node::SetPageRank(pr);
			}
		}
			return elements;
}
void PageRank::PrintPageRank(vector<Node*> & nodes)
{
    double total_pr = 0;
    vector<Node*>::const_iterator citr = nodes.begin();
    for (; citr!=nodes.end(); ++citr)
    {
        Node * node = *citr;
        node->PrintNode();
        total_pr += node->GetPageRank();
    }
    cout << "Total PR:" << total_pr << endl;
}

