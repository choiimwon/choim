#if !defined(IOSTREAM)

#define IOSTREAM

#include<iostream>

#endif

#if !defined(SET)

#define SET

#include<set>

#endif

#if !defined(TYPEDEFS)

#define TYPEDEFS

typedef unsigned int uint;

typedef unsigned int DataType;

typedef std::set<DataType> IntSet;

typedef std::set<IntSet> SuperSet;

typedef IntSet::const_iterator IntSetCI;

typedef SuperSet::const_iterator SuperSetCI;

#endif

class Matrix{

		bool **mat;

			uint r,c;

	public:

				Matrix(uint r,uint c);

					~Matrix();

						void getData();

							void display();

								uint count(const IntSet& c) const;

									bool candidateInTransaction(const uint& row,IntSet
											c) const;

};
