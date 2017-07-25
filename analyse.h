/**
 *  analyse.h
 *
 *  Entry points to the Analyse Dynamic Library
 *
 *  25-07-2017 - First Implementation by Guillermo Amodeo
 *
 **/

#ifndef ANALYSE_DYLIB
#define ANALYSE_DYLIB

#include <errno.h>

/** --------------------------------------------- *
 *
 * \brief Analyse 'input' and write results in 'output'
 *
 *  This function analyse the file specified by 'input'
 *  and write the results in the file specified by
 *  'output'.
 *
 *  It returns 0 for success or a negative number
 *  for error, which is a negative version of the
 *  standard errors in errno.h
 *
 *  Please note that 'output' would be overwritten
 *  in success and deleted on error.
 * --------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif

int analyse(const char * input, const char * output);

#ifdef __cplusplus
};
#endif

#endif


