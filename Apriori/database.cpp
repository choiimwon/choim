#include "database.hpp"

Matrix::Matrix(uint r,uint c){

		this->r=r;this->c=c;

			mat=new bool*[r];

				for(int i=0;i < r;i++)

							mat[i]=new bool[c];

}

Matrix::~Matrix(){

		for(int i=0;i < r;i++)

					delete[] mat[i];

			delete[] mat;

}

void Matrix::getData(){

		for(int i=0;i < r;i++)

					for(int j=0;j < c;j++)

									std::cin>>mat[i][j];

}

void Matrix::display(){

		for(int i=0;i < r;i++){

					std::cout<<std::endl;

							for(int j=0;j< c;j++)

											std::cout<<mat[i][j]<<' ';

								}

}

bool Matrix::candidateInTransaction(const uint& row,IntSet c) const{

		for(IntSetCI i=c.begin();i != c.end();++i)

					if(!mat[row][*i])

									return false;

			return true;

}

uint Matrix::count(const IntSet& c) const{

		int i,count=0;

			for(i=0;i < r;i++)

						if(candidateInTransaction(i,c))

										count++;

				return count;

}
