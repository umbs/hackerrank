#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define ull unsigned long long

ull two[65] = { 1UL, 2UL, 4UL, 8UL, 16UL, 32UL, 64UL, 128UL, 256UL, 512UL, 1024UL,
2048UL, 4096UL, 8192UL, 16384UL, 32768UL, 65536UL, 131072UL, 262144UL, 524288UL,
1048576UL, 2097152UL, 4194304UL, 8388608UL, 16777216UL, 33554432UL, 67108864UL,
134217728UL, 268435456UL, 536870912UL, 1073741824UL, 2147483648UL, 4294967296UL,
8589934592UL, 17179869184UL, 34359738368UL, 68719476736UL, 137438953472UL,
274877906944UL, 549755813888UL, 1099511627776UL, 2199023255552UL, 4398046511104UL,
8796093022208UL, 17592186044416UL, 35184372088832UL, 70368744177664UL,
140737488355328UL, 281474976710656UL, 562949953421312UL, 1125899906842624UL,
2251799813685248UL, 4503599627370496UL, 9007199254740992UL, 18014398509481984UL,
36028797018963968UL, 72057594037927936UL, 144115188075855872UL,
288230376151711744UL, 576460752303423488UL, 1152921504606846976UL,
2305843009213693952UL, 4611686018427387904UL, 9223372036854775808UL,
18446744073709551615UL,
};

char *winner(int turn)
{
    if (turn%2 == 1) return "Richard";
    return "Louise";
}

int twoPow(ull N)
{
    return (N & (N-1));
}

int indices(ull N)
{
    int i=0;
    while(N != (1<<i)) i++;
    return i;
}

ull lessPow(ull N)
{
    int i;
    for (i=0; i<65; i++) {
        if (N < two[i]) break;
    }

    return two[i-1];
}

int main()
{
    ull *N;
    int turn = 1, idx, tests;

    scanf("%d", &tests);

    N = malloc(tests * sizeof (ull));

    for (idx=0; idx < tests; idx++) scanf("%llu", &N[idx]);

    for (idx=0; idx < tests; idx++) {
        ull cntr = N[idx];
        while (cntr>1) {
            if (twoPow(cntr) == 0) cntr = cntr/2;
            else cntr = cntr - lessPow(cntr);
            turn++;
        }
        printf("%s\n", winner(turn));
        turn = 1;
    }

    free (N);
    return 0;
}
