#include <stdio.h>

int main() {
    char mem[0x10000] = {0};
    mem[1] = getchar();
    mem[2] = getchar();
    mem[3] = getchar();
    mem[4] = getchar();
    mem[5] = getchar();
    mem[6] = getchar();
    while(mem[1]) {
        mem[1] -= 1;
        mem[7] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[1] += 1;
    }
    while(mem[1]) {
        mem[1] -= 1;
        mem[7] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[1] += 1;
    }
    while(mem[2]) {
        mem[2] -= 1;
        mem[8] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[2] += 1;
    }
    while(mem[2]) {
        mem[2] -= 1;
        mem[8] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[2] += 1;
    }
    while(mem[3]) {
        mem[3] -= 1;
        mem[9] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[3] += 1;
    }
    while(mem[3]) {
        mem[3] -= 1;
        mem[9] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[3] += 1;
    }
    while(mem[4]) {
        mem[4] -= 1;
        mem[10] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[4] += 1;
    }
    while(mem[4]) {
        mem[4] -= 1;
        mem[10] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[4] += 1;
    }
    while(mem[5]) {
        mem[5] -= 1;
        mem[11] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[5] += 1;
    }
    while(mem[5]) {
        mem[5] -= 1;
        mem[11] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[5] += 1;
    }
    while(mem[6]) {
        mem[6] -= 1;
        mem[12] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[6] += 1;
    }
    while(mem[6]) {
        mem[6] -= 1;
        mem[12] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[6] += 1;
    }
    while(mem[7]) {
        mem[7] -= 1;
        mem[13] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[7] += 1;
    }
    while(mem[1]) {
        mem[1] -= 1;
        mem[13] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[1] += 1;
    }
    while(mem[8]) {
        mem[8] -= 1;
        mem[14] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[8] += 1;
    }
    while(mem[2]) {
        mem[2] -= 1;
        mem[14] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[2] += 1;
    }
    while(mem[9]) {
        mem[9] -= 1;
        mem[15] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[9] += 1;
    }
    while(mem[3]) {
        mem[3] -= 1;
        mem[15] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[3] += 1;
    }
    while(mem[10]) {
        mem[10] -= 1;
        mem[16] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[10] += 1;
    }
    while(mem[4]) {
        mem[4] -= 1;
        mem[16] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[4] += 1;
    }
    while(mem[11]) {
        mem[11] -= 1;
        mem[17] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[11] += 1;
    }
    while(mem[5]) {
        mem[5] -= 1;
        mem[17] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[5] += 1;
    }
    while(mem[12]) {
        mem[12] -= 1;
        mem[18] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[12] += 1;
    }
    while(mem[6]) {
        mem[6] -= 1;
        mem[18] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[6] += 1;
    }
    while(mem[13]) {
        mem[13] -= 1;
        mem[19] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[13] += 1;
    }
    while(mem[1]) {
        mem[1] -= 1;
        mem[19] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[1] += 1;
    }
    while(mem[14]) {
        mem[14] -= 1;
        mem[20] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[14] += 1;
    }
    while(mem[2]) {
        mem[2] -= 1;
        mem[20] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[2] += 1;
    }
    while(mem[15]) {
        mem[15] -= 1;
        mem[21] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[15] += 1;
    }
    while(mem[3]) {
        mem[3] -= 1;
        mem[21] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[3] += 1;
    }
    while(mem[16]) {
        mem[16] -= 1;
        mem[22] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[16] += 1;
    }
    while(mem[4]) {
        mem[4] -= 1;
        mem[22] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[4] += 1;
    }
    while(mem[17]) {
        mem[17] -= 1;
        mem[23] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[17] += 1;
    }
    while(mem[5]) {
        mem[5] -= 1;
        mem[23] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[5] += 1;
    }
    while(mem[18]) {
        mem[18] -= 1;
        mem[24] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[18] += 1;
    }
    while(mem[6]) {
        mem[6] -= 1;
        mem[24] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[6] += 1;
    }
    while(mem[19]) {
        mem[19] -= 1;
        mem[25] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[19] += 1;
    }
    while(mem[1]) {
        mem[1] -= 1;
        mem[25] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[1] += 1;
    }
    while(mem[20]) {
        mem[20] -= 1;
        mem[26] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[20] += 1;
    }
    while(mem[2]) {
        mem[2] -= 1;
        mem[26] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[2] += 1;
    }
    while(mem[21]) {
        mem[21] -= 1;
        mem[27] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[21] += 1;
    }
    while(mem[3]) {
        mem[3] -= 1;
        mem[27] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[3] += 1;
    }
    while(mem[22]) {
        mem[22] -= 1;
        mem[28] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[22] += 1;
    }
    while(mem[4]) {
        mem[4] -= 1;
        mem[28] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[4] += 1;
    }
    while(mem[23]) {
        mem[23] -= 1;
        mem[29] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[23] += 1;
    }
    while(mem[5]) {
        mem[5] -= 1;
        mem[29] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[5] += 1;
    }
    while(mem[24]) {
        mem[24] -= 1;
        mem[30] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[24] += 1;
    }
    while(mem[6]) {
        mem[6] -= 1;
        mem[30] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[6] += 1;
    }
    while(mem[2]) {
        mem[2] -= 1;
        mem[31] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[2] += 1;
    }
    while(mem[9]) {
        mem[9] -= 1;
        mem[31] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[9] += 1;
    }
    while(mem[16]) {
        mem[16] -= 1;
        mem[31] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[16] += 1;
    }
    while(mem[23]) {
        mem[23] -= 1;
        mem[31] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[23] += 1;
    }
    while(mem[30]) {
        mem[30] -= 1;
        mem[31] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[30] += 1;
    }
    while(mem[25]) {
        mem[25] -= 1;
        mem[32] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[25] += 1;
    }
    while(mem[20]) {
        mem[20] -= 1;
        mem[32] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[20] += 1;
    }
    while(mem[15]) {
        mem[15] -= 1;
        mem[32] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[15] += 1;
    }
    while(mem[10]) {
        mem[10] -= 1;
        mem[32] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[10] += 1;
    }
    while(mem[5]) {
        mem[5] -= 1;
        mem[32] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[5] += 1;
    }
    while(mem[13]) {
        mem[13] -= 1;
        mem[33] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[13] += 1;
    }
    while(mem[8]) {
        mem[8] -= 1;
        mem[33] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[8] += 1;
    }
    while(mem[3]) {
        mem[3] -= 1;
        mem[33] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[3] += 1;
    }
    while(mem[22]) {
        mem[22] -= 1;
        mem[33] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[22] += 1;
    }
    while(mem[30]) {
        mem[30] -= 1;
        mem[33] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[30] += 1;
    }
    while(mem[7]) {
        mem[7] -= 1;
        mem[34] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[7] += 1;
    }
    while(mem[2]) {
        mem[2] -= 1;
        mem[34] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[2] += 1;
    }
    while(mem[21]) {
        mem[21] -= 1;
        mem[34] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[21] += 1;
    }
    while(mem[28]) {
        mem[28] -= 1;
        mem[34] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[28] += 1;
    }
    while(mem[17]) {
        mem[17] -= 1;
        mem[34] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[17] += 1;
    }
    while(mem[8]) {
        mem[8] -= 1;
        mem[35] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[8] += 1;
    }
    while(mem[15]) {
        mem[15] -= 1;
        mem[35] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[15] += 1;
    }
    while(mem[22]) {
        mem[22] -= 1;
        mem[35] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[22] += 1;
    }
    while(mem[29]) {
        mem[29] -= 1;
        mem[35] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[29] += 1;
    }
    while(mem[6]) {
        mem[6] -= 1;
        mem[35] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[6] += 1;
    }
    while(mem[7]) {
        mem[7] -= 1;
        mem[36] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[7] += 1;
    }
    while(mem[20]) {
        mem[20] -= 1;
        mem[36] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[20] += 1;
    }
    while(mem[3]) {
        mem[3] -= 1;
        mem[36] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[3] += 1;
    }
    while(mem[17]) {
        mem[17] -= 1;
        mem[36] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[17] += 1;
    }
    while(mem[30]) {
        mem[30] -= 1;
        mem[36] += 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[30] += 1;
    }
    mem[37] = 0;
    mem[37] += 53;
    mem[38] = 0;
    mem[38] += 228;
    mem[39] = 0;
    mem[39] += 5;
    mem[40] = 0;
    mem[40] += 158;
    mem[41] = 0;
    mem[41] += 73;
    mem[42] = 0;
    mem[42] += 123;
    while(mem[31]) {
        mem[31] -= 1;
        mem[37] -= 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[31] += 1;
    }
    while(mem[32]) {
        mem[32] -= 1;
        mem[38] -= 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[32] += 1;
    }
    while(mem[33]) {
        mem[33] -= 1;
        mem[39] -= 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[33] += 1;
    }
    while(mem[34]) {
        mem[34] -= 1;
        mem[40] -= 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[34] += 1;
    }
    while(mem[35]) {
        mem[35] -= 1;
        mem[41] -= 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[35] += 1;
    }
    while(mem[36]) {
        mem[36] -= 1;
        mem[42] -= 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[36] += 1;
    }
    mem[43] = 0;
    mem[43] += 48;
    while(mem[37]) {
        mem[43] += 1;
        mem[37] = 0;
    }
    while(mem[38]) {
        mem[43] += 1;
        mem[38] = 0;
    }
    while(mem[39]) {
        mem[43] += 1;
        mem[39] = 0;
    }
    while(mem[40]) {
        mem[43] += 1;
        mem[40] = 0;
    }
    while(mem[41]) {
        mem[43] += 1;
        mem[41] = 0;
    }
    while(mem[42]) {
        mem[43] += 1;
        mem[42] = 0;
    }
    mem[44] = getchar();
    mem[45] = getchar();
    mem[46] = getchar();
    mem[47] = getchar();
    mem[48] = getchar();
    mem[49] = getchar();
    mem[50] = 0;
    mem[50] += 101;
    mem[51] = 0;
    mem[51] += 95;
    mem[52] = 0;
    mem[52] += 67;
    mem[53] = 0;
    mem[53] += 48;
    mem[54] = 0;
    mem[54] += 100;
    mem[55] = 0;
    mem[55] += 51;
    while(mem[44]) {
        mem[44] -= 1;
        mem[50] -= 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[44] += 1;
    }
    while(mem[45]) {
        mem[45] -= 1;
        mem[51] -= 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[45] += 1;
    }
    while(mem[46]) {
        mem[46] -= 1;
        mem[52] -= 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[46] += 1;
    }
    while(mem[47]) {
        mem[47] -= 1;
        mem[53] -= 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[47] += 1;
    }
    while(mem[48]) {
        mem[48] -= 1;
        mem[54] -= 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[48] += 1;
    }
    while(mem[49]) {
        mem[49] -= 1;
        mem[55] -= 1;
        mem[0] += 1;
    }
    while(mem[0]) {
        mem[0] -= 1;
        mem[49] += 1;
    }
    while(mem[50]) {
        mem[43] += 1;
        mem[50] = 0;
    }
    while(mem[51]) {
        mem[43] += 1;
        mem[51] = 0;
    }
    while(mem[52]) {
        mem[43] += 1;
        mem[52] = 0;
    }
    while(mem[53]) {
        mem[43] += 1;
        mem[53] = 0;
    }
    while(mem[54]) {
        mem[43] += 1;
        mem[54] = 0;
    }
    while(mem[55]) {
        mem[43] += 1;
        mem[55] = 0;
    }
    printf("%c", mem[43]);
    return 0;
}
