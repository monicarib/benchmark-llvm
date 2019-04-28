#include "reedsolomon.h"

int main(void) {
  unsigned char rs_in[204], rs_out[204];
  int i, j, k;

#ifdef SMALL_PROBLEM_SIZE
#define LENGTH 15000
#else
#define LENGTH 150000
#endif

#ifdef __MINGW32__
#define random() rand()
#endif

  for (i=0; i<LENGTH; ++i) {
    /* Generate random data */
    for (j=0; j<188; ++j) {
      rs_in[j] = (random() & 0xFF);
    }
    reedsolomon(rs_out, rs_in);
    /* Number of errors to insert */
    k = random() & 0x7F;

    for (j=0; j<k; ++j) {
      rs_out[random() % 204] = (random() & 0xFF);
    }
    
    reedsolomon(rs_in, rs_out);
  }

  int expectedResult [] = { 131 , 251 , 118 , 104 , 173 , 253 , 40 , 182 , 22 , 247 , 15 , 121 , 144 , 159 , 58 , 184 , 42 , 32 , 172 , 194 , 127 , 73 , 148 , 211 , 51 , 24 , 109 , 99 , 1 , 86 , 222 , 132 , 81 , 224 , 42 , 255 , 221 , 82 , 181 , 243 , 174 , 48 , 67 , 218 , 99 , 166 , 53 , 142 , 4 , 225 , 61 , 70 , 30 , 119 , 25 , 93 , 125 , 134 , 193 , 126 , 221 , 43 , 2 , 46 , 172 , 44 , 124 , 232 , 127 , 226 , 220 , 201 , 166 , 72 , 163 , 10 , 239 , 98 , 152 , 182 , 186 , 213 , 252 , 228 , 13 , 22 , 35 , 36 , 156 , 3 , 162 , 121 , 46 , 164 , 126 , 57 , 43 , 213 , 33 , 79 , 184 , 253 , 24 , 216 , 70 , 188 , 104 , 20 , 252 , 157 , 235 , 153 , 147 , 167 , 51 , 125 , 53 , 117 , 161 , 154 , 120 , 67 , 19 , 166 , 20 , 187 , 223 , 183 , 145 , 0 , 7 , 73 , 118 , 31 , 254 , 68 , 219 , 16 , 121 , 112 , 16 , 122 , 190 , 185 , 75 , 86 , 99 , 148 , 168 , 4 , 227 , 222 , 71 , 246 , 132 , 46 , 178 , 39 , 230 , 67 , 100 , 237 , 3 , 98 , 12 , 51 , 166 , 232 , 67 , 231 , 39 , 84 , 131 , 22 , 58 , 110 , 8 , 158 , 23 , 110 , 122 , 56 , 77 , 234 , 241 , 181 , 54 , 163 , 233 , 212 , 44 , 26 , 82 , 240 , 209 , 162 , 106 , 78 , 18 , 63 , 161 , 176 , 158 , 140 };
  for (j=0; j<204; ++j) {
    // printf("%d \n",(int)rs_out[j]);
    if((int)rs_out[j] != expectedResult[j]){
        // printf("%d\n",j;
        // printf("%d != %d ",(int)rs_out[j], expectedResult[j]);
        return 1;
    }
  }
  return 10;
}
