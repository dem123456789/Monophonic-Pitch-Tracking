/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * isequal.c
 *
 * Code generation for function 'isequal'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "isequal.h"
#include "lapacke.h"

/* Function Definitions */

/*
 *
 */
boolean_T b_isequal(const emxArray_real_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  int32_T exitg1;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      if (varargin_1->size[k] != 0) {
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (!b_p) {
  } else {
    p = true;
  }

  return p;
}

/*
 *
 */
boolean_T c_isequal(const emxArray_boolean_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  int32_T exitg1;
  int32_T i15;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      if (k + 1 <= 1) {
        i15 = varargin_1->size[0];
      } else {
        i15 = 1;
      }

      if (i15 != 0) {
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (!b_p) {
  } else {
    p = true;
  }

  return p;
}

/*
 *
 */
boolean_T isequal(const emxArray_real_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  int32_T exitg1;
  int32_T i11;
  p = false;
  b_p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      if (k + 1 <= 1) {
        i11 = varargin_1->size[0];
      } else {
        i11 = 1;
      }

      if (i11 != 0) {
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      b_p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (!b_p) {
  } else {
    p = true;
  }

  return p;
}

/* End of code generation (isequal.c) */
