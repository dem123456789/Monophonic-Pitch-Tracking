/*
 * File: sort1.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 19:51:15
 */

#ifndef __SORT1_H__
#define __SORT1_H__

/* Include Files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "omp.h"
#include "yaapt_types.h"

/* Function Declarations */
extern void c_sort(double x[3], int idx[3]);
extern void e_sort(emxArray_real_T *x, emxArray_int32_T *idx);
extern void sort(double x[100], int idx[100]);

#endif

/*
 * File trailer for sort1.h
 *
 * [EOF]
 */
