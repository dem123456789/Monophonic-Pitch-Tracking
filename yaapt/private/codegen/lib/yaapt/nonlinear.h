/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: nonlinear.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 15-Nov-2015 00:14:51
 */

#ifndef __NONLINEAR_H__
#define __NONLINEAR_H__

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
extern void nonlinear(const emxArray_real_T *DataA, double Fs, emxArray_real_T
                      *DataB, emxArray_real_T *DataC, emxArray_real_T *DataD,
                      double *newFs);

#endif

/*
 * File trailer for nonlinear.h
 *
 * [EOF]
 */
