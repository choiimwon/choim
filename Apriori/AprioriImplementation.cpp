#include "AprioriImplementation.hpp"

void display(Index index);/*for testing purposes*/

int main(int argc, const char* argv[]){

	FILE* ifp;

	int n;

	Index index;

	extern void s4_init_simulation();

	uint min_sup;
	uint noItems,noTrans;
	std::cout<<"Reading Data...";
	ifp = s4_fopen(argv[2],"r");
	ifp = s4_fopen(argv[1],"r");
	while((n=s4_pageread(0,S4_NUM_BUFFERS,ifp))>0)
	{
		std::cin>>min_sup>>noItems>>noTrans;
		for(int i=0;i <noItems;i++)	
			std::cin>>index[i];
	}
	Matrix db(noTrans,noItems);
	db.getData();
	std::cout<<"\nProcessing...\n";
	display(apriori(noItems,db,min_sup),index);

	extern void s4_wrapup_simulation();	
														
	return 0;

}

void display(Index index){

	std::cout<<"Map :-";

	for(IndexCI i=index.begin();i != index.end();++i)
		std::cout<<std::endl<<i->first<<'\t'<<i->second;

}
