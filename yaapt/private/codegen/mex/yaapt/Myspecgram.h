/*
 * Myspecgram.h
 *
 * Code generation for function 'Myspecgram'
 *
 */

#ifndef MYSPECGRAM_H
#define MYSPECGRAM_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "yaapt_types.h"

/* Function Declarations */
extern void Myspecgram(const emlrtStack *sp, emxArray_real_T *x, real_T nfft,
  real_T window, real_T noverlap, emxArray_creal_T *yo);

#endif

/* End of code generation (Myspecgram.h) */
