/*
 * xgeqp3.h
 *
 * Code generation for function 'xgeqp3'
 *
 */

#ifndef __XGEQP3_H__
#define __XGEQP3_H__

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blas.h"
#include "rtwtypes.h"
#include "omp.h"
#include "yaapt_types.h"

/* Function Declarations */
extern void xgeqp3(const emlrtStack *sp, emxArray_real_T *A, emxArray_real_T
                   *tau, emxArray_int32_T *jpvt);

#endif

/* End of code generation (xgeqp3.h) */
