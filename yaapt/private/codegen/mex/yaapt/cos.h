/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cos.h
 *
 * Code generation for function 'cos'
 *
 */

#ifndef __COS_H__
#define __COS_H__

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
extern void b_cos(real_T x[75]);
extern void c_cos(const emlrtStack *sp, emxArray_real_T *x);

#endif

/* End of code generation (cos.h) */
