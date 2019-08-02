#include <stdio.h>

#if 1
int numSubarraysWithSum(int* A, int ASize, int S) {
    int lptr = 0, cnt = 0, cur_sum = 0;
    for (int i = 0; i < ASize; i++) {
        cur_sum += A[i];
        // if cur_sum > S, move the left window
        while (lptr < i && cur_sum > S) {
            cur_sum -= A[lptr++];
        } 
        if (cur_sum < S) continue;
        if (cur_sum == S) cnt++;
        // count the number of zero in the left window every time we move forward
        int tmp_ptr = lptr;
        while (tmp_ptr < i && A[tmp_ptr++] != 1) {
            cnt++;
        }
    }
    return cnt;
}
#else
int numSubarraysWithSum(int* A, int ASize, int S){
    int lptr = 0, rptr = 0;
    int lzero = 0, rzero;
    int cnt = 0;
    int cur_sum = 0;
    // handling S = 0
    if (S == 0) {
        while (lptr < ASize) {
            if (A[lptr] == 0) {
                lzero++;
            } else {
                cnt += (lzero + 1) * lzero / 2;
                lzero = 0;
            }
            lptr++;
        }
        cnt += (lzero + 1) * lzero / 2;
    } else {
        // wait until the correct total sum
        while (rptr < ASize) {
            cur_sum += A[rptr];
            if (cur_sum == S) break;
            rptr++;
        }
        while(lptr < ASize && rptr < ASize) {
            lzero = rzero = 0;
            // count the left zero
            while (lptr < ASize && A[lptr] == 0) {
                lptr++;
                lzero++;
            }
            lptr++;
            // count the right zero
            rptr++;
            while (rptr < ASize && A[rptr] == 0) {
                rptr++;
                rzero++;
            }
            // add cnt
            cnt += (lzero + 1) * (rzero + 1);
        }
    }
    return cnt;
}
#endif

int main() {
    int A[] = {1,0,1,0,1};
    int ASize = sizeof(A)/sizeof(A[0]);
    int S = 2;
    printf("result=%d\n", numSubarraysWithSum(A, ASize, S));
    return 0;
}