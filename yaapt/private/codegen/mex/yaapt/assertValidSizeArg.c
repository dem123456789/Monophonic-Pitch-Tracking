/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * assertValidSizeArg.c
 *
 * Code generation for function 'assertValidSizeArg'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "assertValidSizeArg.h"
#include "yaapt_data.h"
#include "lapacke.h"

/* Function Definitions */

/*
 *
 */
void assertValidSizeArg(const emlrtStack *sp, real_T varargin_1)
{
  boolean_T p;
  boolean_T guard1 = false;
  if ((varargin_1 != muDoubleScalarFloor(varargin_1)) || muDoubleScalarIsInf
      (varargin_1)) {
    p = false;
  } else {
    p = true;
  }

  guard1 = false;
  if (p) {
    if ((-2.147483648E+9 > varargin_1) || (2.147483647E+9 < varargin_1)) {
      p = false;
    } else {
      p = true;
    }

    if (p) {
      p = true;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    p = false;
  }

  if (p) {
  } else {
    emlrtErrorWithMessageIdR2012b(sp, &ke_emlrtRTEI,
      "Coder:MATLAB:NonIntegerInput", 4, 12, MIN_int32_T, 12, MAX_int32_T);
  }
}

/* End of code generation (assertValidSizeArg.c) */
