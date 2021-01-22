//http://www.add.ece.ufl.edu/4924/docs/arm/ARM%20NEON%20Development.pdf

#include <stdio.h>
#include <arm_neon.h>

int main(void){
//vector addition 8x8 example.
int r,s;

uint8x8_t a = vdup_n_u8(9);
uint8x8_t b = vdup_n_u8(10);

uint8x8_t dst = a * b;

r = vget_lane_u8( dst, 0);
s = vget_lane_u8( dst, 7);

if (r != 90 || s != 90) {
   fprintf(stderr, "%d || %d != 90\n", r, s);
   return 1;
}

return 0;
}
