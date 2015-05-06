#include "sets.hpp"

void display(IntSet s){

		std::cout<<'{';

			if(s.size()){

						IntSetCI i=s.begin();

								std::cout<<*(i++);

										for(;i != s.end();++i)

														std::cout<<','<<*i;

											}

				std::cout<<'}';

}

void display(SuperSet ss){

		std::cout<<'{';

			if(ss.size()){

						SuperSetCI i=ss.begin();

								display(*(i++));

										for(;i != ss.end();++i){

														std::cout<<',';

																	display(*i);

																			}

											}

				std::cout<<'}';

}

void display(IntSet s,Index index){

		std::cout<<'{';

			if(s.size()){

						IntSetCI i=s.begin();

								std::cout<<index[*(i++)];

										for(;i != s.end();++i)

														std::cout<<','<<index[*i];

											}

				std::cout<<'}';

}

void display(SuperSet ss,Index index){

		std::cout<<'{';

			if(ss.size()){

						SuperSet::iterator i=ss.begin();

								display(*(i++),index);

										for(;i != ss.end();++i){

														std::cout<<',';

																	display(*i,index);

																			}

											}

				std::cout<<'}';

}

SuperSet genSubsets(IntSet s){

		SuperSet ss;

			if(s.size() < 2)

						return ss;

				IntSetCI front,back;

					IntSet temp;

						front=s.begin();back=s.end();

							--back;

								temp.insert(front,back);

									ss.insert(temp);

										temp.clear();

											++front;++back;

												temp.insert(front,back);

													ss.insert(temp);

														temp.clear();

															if(s.size() == 2)

																		return ss;

																back=++(s.begin());++front;

																	while(front != s.end()){

																				temp.insert(front,s.end());

																						temp.insert(s.begin(),back);

																								ss.insert(temp);

																										temp.clear();

																												front++;++back;

																													}

																		return ss;

}

IntSet allButLast(IntSet s){

		IntSet temp;

			if(s.size())

						temp.insert(s.begin(),--(s.end()));

				return temp;

}

IntSet last(IntSet s){

		IntSet temp;

			if(s.size())

						temp.insert(--(s.end()),s.end());

				return temp;

}
