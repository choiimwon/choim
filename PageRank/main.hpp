#ifdef __cplusplus
extern "C" {
#endif
   #include "s4.h"
   void s4_init_simulation();
   void s4_wrapup_simulation();
   FILE *
	s4_fopen(const char * filename, const char * mode);
   size_t
   s4_pageread(size_t pageStartNumber, size_t numPages, FILE * stream);
#ifdef __cplusplus
};
#endif
