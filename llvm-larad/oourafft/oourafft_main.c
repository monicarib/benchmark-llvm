void oourafft(int n, int isgn, double *a, int *ip, double *w);
#include <stdlib.h>

int N = 100;
int TRIES = 100;

#pragma DATA_ALIGN(x, 8);  
int main()
{
  int i, j;
  int *ip;
  double *ref, *cmp, *src, *w;
  double t_start, t_end, t_overhead, t_total = 0, err_val;


  /* Measure overhead of get_time() call */
  t_start = get_time();
  t_end = get_time();
  t_overhead = t_end - t_start;

  /* Prepare aux data */
  ip = malloc(sqrt(N)*sizeof(int));
  w  = malloc(2*N*5/4*sizeof(double));
  makewt(N >> 1, ip, w);

  /* Allocate buffers */
  ref = malloc(2*N*sizeof(double));
  cmp = malloc(2*N*sizeof(double));
  src = malloc(2*N*sizeof(double));

  /* Perform sanity check of FFT */
  putdata(0, 2*N - 1, ref);
  oourafft(2*N,  1, ref, ip, w);
  oourafft(2*N, -1, ref, ip, w);
  err_val = errorcheck(0, 2*N - 1, 1.0/N, ref);
  if (fabs(err_val) > 1e-10) {
    printf("FFT sanity check failed! Difference is: %le\n", err_val);
    //abort();
  }

  /* Prepare reference sequence */
  memset(ref, 0, 2*N*sizeof(double));
  putdata(0, N-1, ref);
  oourafft(2*N, 1, ref, ip, w);
  for (j=0; j<N; ++j){
    ref[2*j+1] = -ref[2*j+1];
  }

  /*printf("Doing %d correlations (%d FFTs of size %d)\n", TRIES, 2*TRIES, N);*/
  memset(src, 0, 2*N*sizeof(double));
  putdata(0, N-1, src);

  t_start = get_time();
  for (i=0; i<TRIES; ++i) {
    int k;

    memcpy(cmp, src, 2*N*sizeof(double));
    oourafft(2*N, 1, cmp, ip, w);

    for (k=0; k<N; ++k) {
      double re1 = cmp[2*k];
      double re2 = ref[2*k];
      double im1 = cmp[2*k+1];
      double im2 = ref[2*k+1];
      cmp[2*k]   = re1*re2 - im1*im2;
      cmp[2*k+1] = re1*im2 + im1*re2;
    }
    #pragma monitor start
    oourafft(2*N, -1, cmp, ip, w);
    #pragma monitor stop
  }
  t_end = get_time();
  t_total += t_end - t_start - t_overhead;

  // for (j=0; j<N; ++j) {
  //   printf("%e %e\n",
  //          (fabs(cmp[2*j]) > 1e-9 ? cmp[2*j] : 0),
  //          (fabs(cmp[2*j+1]) > 1e-9 ? cmp[2*j+1] : 0));
  // }
  // printf("Overall time: %le, for single correlation: %le\n", t_total, t_total/TRIES);

  //free(ref);
  //free(w);
  //free(ip);
//  free(cmp);
  //free(src);

  return 10;
}

