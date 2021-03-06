/*
 * any.h
 *
 * Code generation for function 'any'
 *
 */

#ifndef ANY_H
#define ANY_H

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
extern boolean_T any(boolean_T x);
extern boolean_T b_any(const boolean_T x[5]);
extern boolean_T c_any(const emlrtStack *sp, const emxArray_real_T *x);
extern boolean_T d_any(const emlrtStack *sp, const emxArray_boolean_T *x);

#endif

/* End of code generation (any.h) */
