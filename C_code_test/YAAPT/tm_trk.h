/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: tm_trk.h
 *
 * MATLAB Coder version            : 3.0
 * C/C++ source code generated on  : 14-Nov-2015 18:37:50
 */

#ifndef __TM_TRK_H__
#define __TM_TRK_H__

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
extern void tm_trk(const emxArray_real_T *Data, double Fs, const emxArray_real_T
                   *SPitch, const double pStd_data[], const int pStd_size[1],
                   emxArray_real_T *Pitch, emxArray_real_T *Merit);

#endif

/*
 * File trailer for tm_trk.h
 *
 * [EOF]
 */
