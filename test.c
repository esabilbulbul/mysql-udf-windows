/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include <my_global.h>

//#include "libexport.h"
//#include "simil.h"

#define ATTRIBUTE_UNUSED __attribute__ ((unused))

typedef char my_bool;

enum Item_result {STRING_RESULT=0, REAL_RESULT, INT_RESULT, ROW_RESULT,
                  DECIMAL_RESULT};

                  
typedef struct st_udf_init
{
  my_bool maybe_null;          /* 1 if function can return NULL */
  unsigned int decimals;       /* for real functions */
  unsigned long max_length;    /* For string functions */
  char *ptr;                   /* free pointer for function data */
  my_bool const_item;          /* 1 if function always returns the same value */
  void *extension;
} UDF_INIT;

typedef struct st_udf_args
{
  unsigned int arg_count;		/* Number of arguments */
  enum Item_result *arg_type;		/* Pointer to item_results */
  char **args;				/* Pointer to argument */
  unsigned long *lengths;		/* Length of string arguments */
  char *maybe_null;			/* Set to 1 for all maybe_null args */
  char **attributes;                    /* Pointer to attribute name */
  unsigned long *attribute_lengths;     /* Length of attribute arguments */
  void *extension;
} UDF_ARGS;

__declspec(dllexport) int test();
__declspec(dllexport) char SIMIL_init(UDF_INIT *initid, UDF_ARGS *args, char *message);
__declspec(dllexport) void shipshuk_test_deinit(UDF_INIT *initid ATTRIBUTE_UNUSED);


__declspec(dllexport) int test()
{
    return 123;
}

__declspec(dllexport) char test_init(UDF_INIT *initid, UDF_ARGS *args, char *message)
{
    return 0;
}

__declspec(dllexport) void test_deinit(UDF_INIT *initid ATTRIBUTE_UNUSED)
{

}

