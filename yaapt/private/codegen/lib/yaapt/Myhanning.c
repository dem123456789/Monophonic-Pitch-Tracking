/*
 * File: Myhanning.c
 *
 * MATLAB Coder version            : 3.1
 * C/C++ source code generated on  : 23-Sep-2016 04:55:32
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "Myhanning.h"
#include "yaapt_emxutil.h"
#include "cos.h"
#include "Myspecgram.h"
#include "yaapt_rtwutil.h"

/* Function Definitions */

/*
 * HANNING   Hanning window.
 *    HANNING(N) returns the N-point symmetric Hanning window in a column
 *    vector.  Note that the first and last zero-weighted window samples
 *    are not included.
 *
 *    HANNING(N,'symmetric') returns the same result as HANNING(N).
 *
 *    HANNING(N,'periodic') returns the N-point periodic Hanning window,
 *    and includes the first zero-weighted window sample.
 *
 *    NOTE: Use the HANN function to get a Hanning window which has the
 *           first and last zero-weighted samples.
 *
 *    See also BARTLETT, BLACKMAN, BOXCAR, CHEBWIN, HAMMING, HANN, KAISER
 *    and TRIANG.
 * Arguments    : double order
 *                emxArray_real_T *w
 * Return Type  : void
 */
void Myhanning(double order, emxArray_real_T *w)
{
  emxArray_real_T *y;
  double half;
  int n;
  double anew;
  double apnd;
  double ndbl;
  double cdiff;
  int i11;
  int nm1d2;
  int k;
  emxArray_real_T *b_w;
  int i12;

  /*    Copyright 1988-2002 The MathWorks, Inc. */
  /*    $Revision: 1.11 $  $Date: 2002/04/15 01:11:49 $ */
  /*  Check number of inputs */
  /*  error(nargchk(1,2,nargin)); */
  /*  Check for trivial order */
  /* [n,w,trivialwin] = check_order(varargin{1}); */
  /* if trivialwin, return, end */
  /*  Select the sampling option */
  /*  if nargin == 1, */
  /*     sflag = 'symmetric'; */
  /*  else */
  /*     sflag = lower(varargin{2}); */
  /*  end */
  /*   */
  /*  % Allow partial strings for sampling options */
  /*  allsflags = {'symmetric','periodic'}; */
  /*  sflagindex = strmatch(sflag, allsflags); */
  /*  if length(sflagindex)~=1         % catch 0 or 2 matches */
  /*     error('Sampling flag must be either ''symmetric'' or ''periodic''.'); */
  /*  end */
  /*  sflag = allsflags{sflagindex}; */
  /*  Evaluate the window */
  /*  switch sflag, */
  /*  case 'periodic' */
  /*  Includes the first zero sample */
  /*     w = [0; sym_hanning(n-1)]; */
  /*  case 'symmetric' */
  /*  Does not include the first and last zero sample */
  /*     w = sym_hanning(n); */
  emxInit_real_T(&y, 2);
  if (!(rt_remd_snf(order, 2.0) != 0.0)) {
    /*  Even length window */
    half = order / 2.0;
    if (rtIsNaN(half)) {
      n = 1;
      anew = rtNaN;
      apnd = half;
    } else if (half < 1.0) {
      n = 0;
      anew = 1.0;
      apnd = half;
    } else if (rtIsInf(half)) {
      n = 1;
      anew = rtNaN;
      apnd = half;
    } else {
      anew = 1.0;
      ndbl = floor((half - 1.0) + 0.5);
      apnd = 1.0 + ndbl;
      cdiff = (1.0 + ndbl) - half;
      if (fabs(cdiff) < 4.4408920985006262E-16 * half) {
        ndbl++;
        apnd = half;
      } else if (cdiff > 0.0) {
        apnd = 1.0 + (ndbl - 1.0);
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        n = (int)ndbl;
      } else {
        n = 0;
      }
    }

    i11 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = n;
    emxEnsureCapacity((emxArray__common *)y, i11, (int)sizeof(double));
    if (n > 0) {
      y->data[0] = anew;
      if (n > 1) {
        y->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (k = 1; k < nm1d2; k++) {
          y->data[k] = anew + (double)k;
          y->data[(n - k) - 1] = apnd - (double)k;
        }

        if (nm1d2 << 1 == n - 1) {
          y->data[nm1d2] = (anew + apnd) / 2.0;
        } else {
          y->data[nm1d2] = anew + (double)nm1d2;
          y->data[nm1d2 + 1] = apnd - (double)nm1d2;
        }
      }
    }

    i11 = w->size[0];
    w->size[0] = y->size[1];
    emxEnsureCapacity((emxArray__common *)w, i11, (int)sizeof(double));
    nm1d2 = y->size[1];
    for (i11 = 0; i11 < nm1d2; i11++) {
      w->data[i11] = 6.2831853071795862 * y->data[y->size[0] * i11] / (order +
        1.0);
    }

    b_cos(w);
    i11 = w->size[0];
    emxEnsureCapacity((emxArray__common *)w, i11, (int)sizeof(double));
    nm1d2 = w->size[0];
    for (i11 = 0; i11 < nm1d2; i11++) {
      w->data[i11] = 1.0 - w->data[i11];
    }

    i11 = w->size[0];
    emxEnsureCapacity((emxArray__common *)w, i11, (int)sizeof(double));
    nm1d2 = w->size[0];
    for (i11 = 0; i11 < nm1d2; i11++) {
      w->data[i11] *= 0.5;
    }

    if (1 > w->size[0]) {
      i11 = 1;
      k = 1;
      n = 0;
    } else {
      i11 = w->size[0];
      k = -1;
      n = 1;
    }

    emxInit_real_T2(&b_w, 1);
    i12 = b_w->size[0];
    b_w->size[0] = (w->size[0] + div_s32_floor(n - i11, k)) + 1;
    emxEnsureCapacity((emxArray__common *)b_w, i12, (int)sizeof(double));
    nm1d2 = w->size[0];
    for (i12 = 0; i12 < nm1d2; i12++) {
      b_w->data[i12] = w->data[i12];
    }

    nm1d2 = div_s32_floor(n - i11, k);
    for (n = 0; n <= nm1d2; n++) {
      b_w->data[n + w->size[0]] = w->data[(i11 + k * n) - 1];
    }

    i11 = w->size[0];
    w->size[0] = b_w->size[0];
    emxEnsureCapacity((emxArray__common *)w, i11, (int)sizeof(double));
    nm1d2 = b_w->size[0];
    for (i11 = 0; i11 < nm1d2; i11++) {
      w->data[i11] = b_w->data[i11];
    }

    emxFree_real_T(&b_w);
  } else {
    /*  Odd length window */
    half = (order + 1.0) / 2.0;
    if (rtIsNaN(half)) {
      n = 1;
      anew = rtNaN;
      apnd = half;
    } else if (half < 1.0) {
      n = 0;
      anew = 1.0;
      apnd = half;
    } else if (rtIsInf(half)) {
      n = 1;
      anew = rtNaN;
      apnd = half;
    } else {
      anew = 1.0;
      ndbl = floor((half - 1.0) + 0.5);
      apnd = 1.0 + ndbl;
      cdiff = (1.0 + ndbl) - half;
      if (fabs(cdiff) < 4.4408920985006262E-16 * half) {
        ndbl++;
        apnd = half;
      } else if (cdiff > 0.0) {
        apnd = 1.0 + (ndbl - 1.0);
      } else {
        ndbl++;
      }

      if (ndbl >= 0.0) {
        n = (int)ndbl;
      } else {
        n = 0;
      }
    }

    i11 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = n;
    emxEnsureCapacity((emxArray__common *)y, i11, (int)sizeof(double));
    if (n > 0) {
      y->data[0] = anew;
      if (n > 1) {
        y->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (k = 1; k < nm1d2; k++) {
          y->data[k] = anew + (double)k;
          y->data[(n - k) - 1] = apnd - (double)k;
        }

        if (nm1d2 << 1 == n - 1) {
          y->data[nm1d2] = (anew + apnd) / 2.0;
        } else {
          y->data[nm1d2] = anew + (double)nm1d2;
          y->data[nm1d2 + 1] = apnd - (double)nm1d2;
        }
      }
    }

    i11 = w->size[0];
    w->size[0] = y->size[1];
    emxEnsureCapacity((emxArray__common *)w, i11, (int)sizeof(double));
    nm1d2 = y->size[1];
    for (i11 = 0; i11 < nm1d2; i11++) {
      w->data[i11] = 6.2831853071795862 * y->data[y->size[0] * i11] / (order +
        1.0);
    }

    b_cos(w);
    i11 = w->size[0];
    emxEnsureCapacity((emxArray__common *)w, i11, (int)sizeof(double));
    nm1d2 = w->size[0];
    for (i11 = 0; i11 < nm1d2; i11++) {
      w->data[i11] = 1.0 - w->data[i11];
    }

    i11 = w->size[0];
    emxEnsureCapacity((emxArray__common *)w, i11, (int)sizeof(double));
    nm1d2 = w->size[0];
    for (i11 = 0; i11 < nm1d2; i11++) {
      w->data[i11] *= 0.5;
    }

    if (1.0 > (double)w->size[0] - 1.0) {
      i11 = 1;
      k = 1;
      n = 0;
    } else {
      i11 = (int)((double)w->size[0] - 1.0);
      k = -1;
      n = 1;
    }

    emxInit_real_T2(&b_w, 1);
    i12 = b_w->size[0];
    b_w->size[0] = (w->size[0] + div_s32_floor(n - i11, k)) + 1;
    emxEnsureCapacity((emxArray__common *)b_w, i12, (int)sizeof(double));
    nm1d2 = w->size[0];
    for (i12 = 0; i12 < nm1d2; i12++) {
      b_w->data[i12] = w->data[i12];
    }

    nm1d2 = div_s32_floor(n - i11, k);
    for (n = 0; n <= nm1d2; n++) {
      b_w->data[n + w->size[0]] = w->data[(i11 + k * n) - 1];
    }

    i11 = w->size[0];
    w->size[0] = b_w->size[0];
    emxEnsureCapacity((emxArray__common *)w, i11, (int)sizeof(double));
    nm1d2 = b_w->size[0];
    for (i11 = 0; i11 < nm1d2; i11++) {
      w->data[i11] = b_w->data[i11];
    }

    emxFree_real_T(&b_w);
  }

  emxFree_real_T(&y);

  /* --------------------------------------------------------------------- */
  /*  function w = sym_hanning(n) */
  /* SYM_HANNING   Symmetric Hanning window.  */
  /*    SYM_HANNING Returns an exactly symmetric N point window by evaluating */
  /*    the first half and then flipping the same samples over the other half. */
  /*  if ~rem(n,2) */
  /*     % Even length window */
  /*     half = n/2; */
  /*     w = calc_hanning(half,n); */
  /*     w = [w; w(end:-1:1)]; */
  /*  else */
  /*     % Odd length window */
  /*     half = (n+1)/2; */
  /*     w = calc_hanning(half,n); */
  /*     w = [w; w(end-1:-1:1)]; */
  /*  end */
  /*  end */
  /* --------------------------------------------------------------------- */
  /*  function w = calc_hanning(m,n) */
  /* CALC_HANNING   Calculates Hanning window samples. */
  /*    CALC_HANNING Calculates and returns the first M points of an N point */
  /*    Hanning window. */
  /*  w = .5*(1 - cos(2*pi*(1:m)'/(n+1)));  */
  /*  [EOF] hanning.m */
  /*  end */
}

/*
 * File trailer for Myhanning.c
 *
 * [EOF]
 */
