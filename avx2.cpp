// https://www.cs.virginia.edu/~cr4bd/3330/F2018/simdref.html

#include <immintrin.h>
#include <iostream>

int main() {

    int32_t ia[8]= {0, 10, 20, 30, 40, 50, 60, 70};
    int32_t ib[8]= {1, 1, 1, 1, 1, 1, 1, 1};
    int32_t iab[8];

    __m256i a = _mm256_loadu_si256((__m256i*) ia);
    __m256i b = _mm256_loadu_si256((__m256i*) ib);

    __m256i ab = _mm256_add_epi32(a, b);

    _mm256_storeu_si256((__m256i*) iab, ab);

    for (auto i = 0; i < 8; i++) {
        if(iab[i] != 10*i + 1) {
            std::cerr << "ERROR on index: " << i << " value: " << iab[i] << std::endl;
            return i+1;
            }
    }

    return EXIT_SUCCESS;
}
