#if !defined(IOSTREAM)

#define IOSTREAM

#include<iostream>

#endif

#if !defined(SET)

#define SET

#include<set>

#endif

#if !defined(MAP)

#define MAP

#include<map>

#endif

#if !defined(STRING)

#define STRING

#include<string>

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

#if !defined(TYPEDEFS_MAPS)

#define TYPEDEFS_MAPS

typedef std::map<DataType,std::string> Index;

typedef Index::const_iterator IndexCI;

#endif

void display(IntSet s);

void display(SuperSet ss);

void display(IntSet s,Index index);

void display(SuperSet ss,Index index);

IntSet allButLast(IntSet s);

IntSet last(IntSet s);

SuperSet genSubsets(IntSet s);
