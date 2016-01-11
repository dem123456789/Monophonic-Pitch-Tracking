/*
 * pchip.c
 *
 * Code generation for function 'pchip'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "yaapt.h"
#include "pchip.h"
#include "yaapt_emxutil.h"
#include "lapacke.h"

/* Variable Definitions */
static emlrtRSInfo si_emlrtRSI = { 15, "pchip",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRSInfo ti_emlrtRSI = { 24, "pchip",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRSInfo ui_emlrtRSI = { 40, "pchip",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRSInfo vi_emlrtRSI = { 52, "pchip",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRSInfo wi_emlrtRSI = { 62, "pchip",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRSInfo xi_emlrtRSI = { 84, "pchip",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRTEInfo jc_emlrtRTEI = { 1, 14, "pchip",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRTEInfo kc_emlrtRTEI = { 23, 1, "pchip",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRTEInfo lc_emlrtRTEI = { 38, 1, "pchip",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRTEInfo mc_emlrtRTEI = { 47, 1, "pchip",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m" };

static emlrtRTEInfo xe_emlrtRTEI = { 32, 15, "chckxy",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

static emlrtRTEInfo ye_emlrtRTEI = { 36, 15, "chckxy",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

static emlrtRTEInfo af_emlrtRTEI = { 38, 1, "chckxy",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

static emlrtRTEInfo bf_emlrtRTEI = { 42, 19, "chckxy",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\chckxy.m" };

static emlrtDCInfo gb_emlrtDCI = { 38, 28, "pchip",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\pchip.m", 4 };

static emlrtDCInfo hb_emlrtDCI = { 32, 37, "pwchcore",
  "F:\\Matlab2015b\\toolbox\\eml\\lib\\matlab\\polyfun\\private\\pwchcore.m", 4
};

/* Function Definitions */

/*
 *
 */
void pchip(const emlrtStack *sp, const emxArray_real_T *x, const emxArray_real_T
           *y, emxArray_real_T *v_breaks, emxArray_real_T *v_coefs)
{
  boolean_T p;
  int32_T k;
  boolean_T exitg2;
  boolean_T exitg1;
  emxArray_real_T *h;
  int32_T nx;
  int32_T i29;
  int32_T szdel[2];
  emxArray_real_T *del;
  uint32_T uv3[2];
  emxArray_real_T *slopes;
  real_T signd1;
  real_T hs3;
  real_T w1;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &si_emlrtRSI;
  if (x->size[1] >= 2) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &xe_emlrtRTEI,
      "MATLAB:chckxy:NotEnoughPts", 0);
  }

  p = ((!muDoubleScalarIsInf(x->data[0])) && (!muDoubleScalarIsNaN(x->data[0])));
  if (p) {
    k = 0;
    exitg2 = false;
    while ((!exitg2) && (k <= x->size[1] - 2)) {
      if (!(x->data[k] < x->data[k + 1])) {
        p = false;
        exitg2 = true;
      } else {
        k++;
      }
    }
  }

  if (p && (!muDoubleScalarIsInf(x->data[x->size[1] - 1]))) {
    p = true;
  } else {
    p = false;
  }

  if (p) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &ye_emlrtRTEI,
      "Coder:toolbox:MustBeFiniteAndStrictlyIncreasing", 0);
  }

  p = false;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= y->size[1] - 1)) {
    if (muDoubleScalarIsNaN(y->data[k])) {
      p = true;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (!p) {
  } else {
    emlrtErrorWithMessageIdR2012b(&st, &af_emlrtRTEI,
      "Coder:toolbox:UnsupportedNaN", 0);
  }

  if ((y->size[1] != x->size[1]) && (!(y->size[1] == x->size[1] + 2))) {
    emlrtErrorWithMessageIdR2012b(&st, &bf_emlrtRTEI,
      "MATLAB:chckxy:NumSitesMismatchValues", 4, 12, x->size[1], 12, y->size[1]);
  }

  emxInit_real_T(&st, &h, 2, &kc_emlrtRTEI, true);
  nx = x->size[1];
  i29 = h->size[0] * h->size[1];
  h->size[0] = 1;
  h->size[1] = x->size[1] - 1;
  emxEnsureCapacity(sp, (emxArray__common *)h, i29, (int32_T)sizeof(real_T),
                    &jc_emlrtRTEI);
  st.site = &ti_emlrtRSI;
  for (k = 1; k < nx; k++) {
    h->data[k - 1] = x->data[k] - x->data[k - 1];
  }

  for (i29 = 0; i29 < 2; i29++) {
    szdel[i29] = y->size[i29];
  }

  szdel[1]--;
  for (i29 = 0; i29 < 2; i29++) {
    k = szdel[i29];
    if (!(k > 0)) {
      emlrtNonNegativeCheckR2012b(k, &gb_emlrtDCI, sp);
    }
  }

  emxInit_real_T(sp, &del, 2, &lc_emlrtRTEI, true);
  i29 = del->size[0] * del->size[1];
  del->size[0] = 1;
  del->size[1] = szdel[1];
  emxEnsureCapacity(sp, (emxArray__common *)del, i29, (int32_T)sizeof(real_T),
                    &jc_emlrtRTEI);
  st.site = &ui_emlrtRSI;
  for (k = 0; k + 1 < nx; k++) {
    del->data[k] = (y->data[k + 1] - y->data[k]) / h->data[k];
  }

  for (i29 = 0; i29 < 2; i29++) {
    uv3[i29] = (uint32_T)y->size[i29];
  }

  emxInit_real_T(sp, &slopes, 2, &mc_emlrtRTEI, true);
  i29 = slopes->size[0] * slopes->size[1];
  slopes->size[0] = 1;
  slopes->size[1] = (int32_T)uv3[1];
  emxEnsureCapacity(sp, (emxArray__common *)slopes, i29, (int32_T)sizeof(real_T),
                    &jc_emlrtRTEI);
  if (x->size[1] == 2) {
    st.site = &vi_emlrtRSI;
    for (k = 1; k <= nx; k++) {
      slopes->data[k - 1] = del->data[0];
    }
  } else {
    st.site = &wi_emlrtRSI;
    for (k = 1; k <= nx - 2; k++) {
      signd1 = h->data[k - 1] + h->data[k];
      hs3 = 3.0 * signd1;
      w1 = (h->data[k - 1] + signd1) / hs3;
      signd1 = (h->data[k] + signd1) / hs3;
      hs3 = 0.0;
      if (del->data[k - 1] < 0.0) {
        if (del->data[k] <= del->data[k - 1]) {
          hs3 = del->data[k - 1] / (w1 * (del->data[k - 1] / del->data[k]) +
            signd1);
        } else {
          if (del->data[k] < 0.0) {
            hs3 = del->data[k] / (w1 + signd1 * (del->data[k] / del->data[k - 1]));
          }
        }
      } else {
        if (del->data[k - 1] > 0.0) {
          if (del->data[k] >= del->data[k - 1]) {
            hs3 = del->data[k - 1] / (w1 * (del->data[k - 1] / del->data[k]) +
              signd1);
          } else {
            if (del->data[k] > 0.0) {
              hs3 = del->data[k] / (w1 + signd1 * (del->data[k] / del->data[k -
                1]));
            }
          }
        }
      }

      slopes->data[k] = hs3;
    }

    hs3 = ((2.0 * h->data[0] + h->data[1]) * del->data[0] - h->data[0] *
           del->data[1]) / (h->data[0] + h->data[1]);
    signd1 = muDoubleScalarSign(del->data[0]);
    if (muDoubleScalarSign(hs3) != signd1) {
      hs3 = 0.0;
    } else {
      if ((signd1 != muDoubleScalarSign(del->data[1])) && (muDoubleScalarAbs(hs3)
           > muDoubleScalarAbs(3.0 * del->data[0]))) {
        hs3 = 3.0 * del->data[0];
      }
    }

    slopes->data[0] = hs3;
    hs3 = ((2.0 * h->data[x->size[1] - 2] + h->data[x->size[1] - 3]) * del->
           data[x->size[1] - 2] - h->data[x->size[1] - 2] * del->data[x->size[1]
           - 3]) / (h->data[x->size[1] - 2] + h->data[x->size[1] - 3]);
    signd1 = muDoubleScalarSign(del->data[x->size[1] - 2]);
    if (muDoubleScalarSign(hs3) != signd1) {
      hs3 = 0.0;
    } else {
      if ((signd1 != muDoubleScalarSign(del->data[x->size[1] - 3])) &&
          (muDoubleScalarAbs(hs3) > muDoubleScalarAbs(3.0 * del->data[x->size[1]
            - 2]))) {
        hs3 = 3.0 * del->data[x->size[1] - 2];
      }
    }

    slopes->data[x->size[1] - 1] = hs3;
  }

  st.site = &xi_emlrtRSI;
  k = x->size[1];
  i29 = v_breaks->size[0] * v_breaks->size[1];
  v_breaks->size[0] = 1;
  v_breaks->size[1] = k;
  emxEnsureCapacity(&st, (emxArray__common *)v_breaks, i29, (int32_T)sizeof
                    (real_T), &jc_emlrtRTEI);
  for (i29 = 0; i29 < k; i29++) {
    v_breaks->data[v_breaks->size[0] * i29] = x->data[i29];
  }

  nx = slopes->size[1] - 1;
  i29 = v_coefs->size[0] * v_coefs->size[1];
  k = slopes->size[1] - 1;
  if (!(k > 0)) {
    emlrtNonNegativeCheckR2012b(k, &hb_emlrtDCI, &st);
  }

  v_coefs->size[0] = k;
  v_coefs->size[1] = 4;
  emxEnsureCapacity(&st, (emxArray__common *)v_coefs, i29, (int32_T)sizeof
                    (real_T), &jc_emlrtRTEI);
  for (k = 0; k + 1 < x->size[1]; k++) {
    signd1 = (del->data[k] - slopes->data[k]) / h->data[k];
    hs3 = (slopes->data[k + 1] - del->data[k]) / h->data[k];
    v_coefs->data[k] = (hs3 - signd1) / h->data[k];
    v_coefs->data[nx + k] = 2.0 * signd1 - hs3;
    v_coefs->data[(nx << 1) + k] = slopes->data[k];
    v_coefs->data[3 * nx + k] = y->data[k];
  }

  emxFree_real_T(&slopes);
  emxFree_real_T(&del);
  emxFree_real_T(&h);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (pchip.c) */
