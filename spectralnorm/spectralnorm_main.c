#include "spectralnorm.h"

#pragma DATA_ALIGN(x, 8);  
int main(int argc, char *argv[])
{
  int i;
  int N = ((argc == 2) ? atoi(argv[1]) : 20);
  double u[N],v[N],vBv,vv;
  for(i=0;i<N;i++) u[i]=1;
 #pragma monitor start
  for(i=0;i<10;i++)
    {
      spectralnorm(N,u,v);
      spectralnorm(N,v,u);
    }
 #pragma monitor stop
  vBv=vv=0;
  for(i=0;i<N;i++) { vBv+=u[i]*v[i]; vv+=v[i]*v[i]; }
  float res = sqrt(vBv/vv);
  // printf("%0.9f\n",res);
  if(res - 1.273839831 > 0.00000009){
    return 1;
  }

  return 10;
}
