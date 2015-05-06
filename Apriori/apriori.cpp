#include "apriori.hpp"

bool has_infrequent_subset(IntSet c,SuperSet l1){//Assuming c.size() > 1

		SuperSet subsetsC=genSubsets(c);

			for(SuperSetCI i=subsetsC.begin();i != subsetsC.end();++i)

						if(!l1.count(*i))

										return true;

				return false;

}

SuperSet apriori_gen(SuperSet l1){

		SuperSet ck;

			if(l1.size() < 2)

						return ck;

				SuperSetCI rearmost=--(l1.end()),i,j,tempI;

					for(i=l1.begin(); i != rearmost;++i){

								tempI=i; 

										for(j=++tempI;j != l1.end();++j){

														if(allButLast(*i) == allButLast(*j)
																&& last(*i) != last(*j)){

																			IntSet
																				temp(i->begin(),i->end());

																							temp.insert(--(j->end()),j->end());/*Assuming
																																			 itemset.size()
																																			 >=
																																			 >1*/

																											if(has_infrequent_subset(temp,l1))

																																	;//ignore;

																															else

																																					ck.insert(temp);

																																		}

																}

											}

						return ck;

}

SuperSet scanDB(SuperSet cs,const Matrix &db,const uint &min_sup){

		SuperSet l2;

			for(SuperSetCI i=cs.begin();i != cs.end();++i)

						if(db.count(*i) >= min_sup)

										l2.insert(*i);

				return l2;

}

SuperSet makeL1(const uint& noItems,const Matrix& db,const uint& min_sup){

		IntSet temp;

			SuperSet c1;

				for(int i=0;i < noItems;i++){

							temp.insert(i);

									c1.insert(temp);/*By Value*/

											temp.clear();

												}

					return scanDB(c1,db,min_sup);

}

SuperSet apriori(const uint& noItems,const Matrix& db,const uint& min_sup){

		SuperSet l1,prev;

			l1=makeL1(noItems,db,min_sup);

				while(l1.size()){

							prev=l1;

									l1=scanDB(apriori_gen(l1),db,min_sup);

										}

					return prev;

}
