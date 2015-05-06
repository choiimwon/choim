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
#if !defined(SETS)
#define SETS
#include "sets.hpp"
#endif
#if !defined(DATABASE)
#define DATABASE
#include "database.hpp"
#endif
#if !defined(APRIORI)
#define APRIORI
#include "apriori.hpp"
#endif
#ifdef __cplusplus
extern "C" {
#endif
	#include "/home/choim/s4sim/include/s4.h"
	void s4_init_simulation();
	void s4_wrapup_simulation();
	FILE *
	s4_fopen(const char * filename, const char * mode);
	size_t
	s4_pageread(size_t pageStartNumber, size_t numPages, FILE * stream);
	
#ifdef __cplusplus
};
#endif
