#include "pi.h"
#pragma DATA_ALIGN(x, 8); 
int main(int argc, char *argv[]) {
   float yran, ymult, ymod, x, y, p, prod;
   long int low, ixran, itot, j, iprod;
   double ztot, z;

      ztot = 0.0;
      low = 1;
      ixran = 1907;
      yran = 5813.0;
      ymult = 1307.0;
      ymod = 5471.0;
      // itot = 400;
      itot = 400;

/*
      X and Y are two uniform random numbers between 0 and 1.
      They are computed using two linear congruential generators.
      A mix of integer and real arithmetic is used to simulate a
      real program.  Magnitudes are kept small to prevent 32-bit
      integer overflow and to allow full precision even with a 23-bit
      mantissa.
*/
#pragma monitor start
      for(j=1; j<=itot; j++) {
        iprod = 27611 * ixran;
        ixran = iprod - 74383*(long int)(iprod/74383);
        x = (float)ixran / 74383.0;
        prod = ymult * yran;
        yran = (prod - ymod*(long int)(prod/ymod));
        y = yran / ymod;
        z = x*x + y*y;

        ztot = pi(ztot,z);

        if ( z <= 1.0 ) {
          low = low + 1;
        }
      }
#pragma monitor stop

      // printf(" x = %.6f    y = %12.2f  low = %8d j = %7d\n",x,y,(int)low,(int)j);
      p = 4.0 * (float)low/(float)itot;
      // printf("Pi = %9.6f ztot = %12.2f itot = %8d\n",p,ztot*0.0,(int)itot);

      if((int)low-305 >0){
        return 1;
      }
      if(y-0.871321499 > 0.0009){
        return 2;
      }
      if((int)j - 401>0){
        return 3;
      }
      if(p - 3.050000 > 0.000000){
        return 4;
      }
      if((int)itot - 400 >0){
        return 5;
      }
      if(x - 0.944409370 > 0.00009){
        return 6;
      }

      return 10;
}
