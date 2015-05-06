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

#if !defined(DATABASE)

#define DATABASE

#include "database.hpp"

#endif

#if !defined(SETS)

#define SETS

#include "sets.hpp"

#endif

bool has_infrequent_subset(IntSet c,SuperSet l1);

SuperSet apriori_gen(SuperSet l1);

SuperSet scanDB(SuperSet cs,Matrix &db,const uint& min_sup);

SuperSet makeL1(const uint& noItems,const Matrix& db,const uint& min_sup);

SuperSet apriori(const uint& noItems,const Matrix& db,const uint& min_sup);
