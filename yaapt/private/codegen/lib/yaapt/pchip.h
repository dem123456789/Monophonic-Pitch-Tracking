/*
 * File: pchip.h
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 13-Nov-2015 04:43:17
 */

#ifndef __PCHIP_H__
#define __PCHIP_H__

/* Include files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "yaapt_types.h"

/* Function Declarations */
extern void pchip(const emxArray_real_T *x, const emxArray_real_T *y,
                  emxArray_real_T *v_breaks, emxArray_real_T *v_coefs);

#endif

/*
 * File trailer for pchip.h
 *
 * [EOF]
 */