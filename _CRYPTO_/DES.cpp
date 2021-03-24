// By c10udlnk(https://github.com/c10udlnk)
// Enjoy it!

#include <cstdio>
#include <cstring>
const int PC1_Table[56]={57, 49, 41, 33, 25, 17,  9,
                          1, 58, 50, 42, 34, 26, 18,
                         10,  2, 59, 51, 43, 35, 27,
                         19, 11,  3, 60, 52, 44, 36,
                         63, 55, 47, 39, 31, 23, 15,
                          7, 62, 54, 46, 38, 30, 22,
                         14,  6, 61, 53, 45, 37, 29,
                         21, 13,  5, 28, 20, 12,  4};
const int Rotate_Table[17]={0, 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
const int PC2_Table[48]={14, 17, 11, 24,  1,  5,  3, 28,
                         15,  6, 21, 10, 23, 19, 12,  4,
                         26,  8, 16,  7, 27, 20, 13,  2,
                         41, 52, 31, 37, 47, 55, 30, 40,
                         51, 45, 33, 48, 44, 49, 39, 56,
                         34, 53, 46, 42, 50, 36, 29, 32};
const int IP_Table[64]={58, 50, 42, 34, 26, 18, 10,  2,
                        60, 52, 44, 36, 28, 20, 12,  4,
                        62, 54, 46, 38, 30, 22, 14,  6,
                        64, 56, 48, 40, 32, 24, 16,  8,
                        57, 49, 41, 33, 25, 17,  9,  1,
                        59, 51, 43, 35, 27, 19, 11,  3,
                        61, 53, 45, 37, 29, 21, 13,  5,
                        63, 55, 47, 39, 31, 23, 15,  7};
const int E_Table[48]={32,  1,  2,  3,  4,  5,
                        4,  5,  6,  7,  8,  9,
                        8,  9, 10, 11, 12, 13,
                       12, 13, 14, 15, 16, 17,
                       16, 17, 18, 19, 20, 21,
                       20, 21, 22, 23, 24, 25,
                       24, 25, 26, 27, 28, 29,
                       28, 29, 30, 31, 32,  1};
const int S_Box[8][4][16]={
    // S1
    {14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
      0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
      4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
     15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13},
    // S2
    {15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
      3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
      0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
     13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9},
    // S3
    {10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
     13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
     13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
      1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12},
    // S4
    { 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
     13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
     10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
      3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14},
    // S5
    { 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
     14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
      4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
     11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3},
    // S6
    {12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
     10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
      9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
      4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13},
    // S7
    { 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
     13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
      1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
      6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12},
    // S8
    {13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
      1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
      7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
      2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11}};
const int P_Table[32]={16,  7, 20, 21,
                       29, 12, 28, 17,
                        1, 15, 23, 26,
                        5, 18, 31, 10,
                        2,  8, 24, 14,
                       32, 27,  3,  9,
                       19, 13, 30,  6,
                       22, 11,  4, 25};
const int inv_IP_Table[64]={40,  8, 48, 16, 56, 24, 64, 32,
                            39,  7, 47, 15, 55, 23, 63, 31,
                            38,  6, 46, 14, 54, 22, 62, 30,
                            37,  5, 45, 13, 53, 21, 61, 29,
                            36,  4, 44, 12, 52, 20, 60, 28,
                            35,  3, 43, 11, 51, 19, 59, 27,
                            34,  2, 42, 10, 50, 18, 58, 26,
                            33,  1, 41,  9, 49, 17, 57, 25};
const char HexChar[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
const bool BinArr[16][4]={{0,0,0,0},{0,0,0,1},{0,0,1,0},{0,0,1,1},{0,1,0,0},{0,1,0,1},{0,1,1,0},{0,1,1,1},{1,0,0,0},{1,0,0,1},{1,0,1,0},{1,0,1,1},{1,1,0,0},{1,1,0,1},{1,1,1,0},{1,1,1,1}};
// Hex to Bin
void hex2bin(char hex[],bool bin[],int hexLen){
    if(hexLen%2!=0){
        printf("Hex string length error.\n");
        return;
    }
    for(int i=0;i<hexLen;i++){
        int index=0;
        for(index=0;index<16;index++){
            if(HexChar[index]==hex[i]) break;
        }
        if(index==16){
            printf("Please check your hex string at POSITION [%d] again.\n",i);
            return;
        }
        for(int j=0;j<4;j++){
            bin[i*4+j]=BinArr[index][j];
        }
    }
    return;
}
// Bin to Hex
void bin2hex(bool bin[],char hex[],int binLen){
    if(binLen%4!=0){
        printf("Binary string length error.\n");
        return;
    }
    for(int i=0;i<binLen/4;i++){
        int index=bin[i*4]*8+bin[i*4+1]*4+bin[i*4+2]*2+bin[i*4+3];
        hex[i]=HexChar[index];
    }
    return;
}
// Left rotate
void RotateLeft(bool src[28],bool dst[28],int cnt){
    for(int i=0;i<28;i++){
        dst[i]=src[(i+cnt)%28];
    }
    return;
}
// Generate sub keys
void GenSubKey(bool key[64],bool subKey[17][48]){
    // PC-1 substitution
    bool pc1[56]={0};
    for(int i=0;i<56;i++){
        pc1[i]=key[PC1_Table[i]-1];
    }
    // Sub keys left rotate
    bool c[17][28]={0},d[17][28]={0};
    for(int i=0;i<28;i++){
        c[0][i]=pc1[i];
        d[0][i]=pc1[28+i];
    }
    for(int i=1;i<=16;i++){
        RotateLeft(c[i-1],c[i],Rotate_Table[i]);
        RotateLeft(d[i-1],d[i],Rotate_Table[i]);
    }
    // PC-2 substitution
    bool pc2[17][56]={0};
    for(int i=1;i<=16;i++){
        for(int j=0;j<28;j++){
            pc2[i][j]=c[i][j];
            pc2[i][28+j]=d[i][j];
        }
    }
    for(int i=1;i<=16;i++){
        for(int j=0;j<48;j++){
            subKey[i][j]=pc2[i][PC2_Table[j]-1];
        }
    }
    return;
}
// Bin to Dec
int bin2dec(bool bin[],int len){
    int res=0,pos=1;
    for(int i=len-1;i>=0;i--){
        res+=bin[i]*pos;
        pos*=2;
    }
    return res;
}
// F round function
void fFunc(bool r[32],bool subKey[48],bool res[32]){
    // E extend
    bool eSub[48]={0};
    for(int i=0;i<48;i++){
        eSub[i]=r[E_Table[i]-1];
    }
    // Xor eSub,subKey
    bool xor_res[48]={0};
    for(int i=0;i<48;i++){
        xor_res[i]=eSub[i]^subKey[i];
    }
    // S box compress
    bool s_comp[32]={0};
    for(int i=0;i<8;i++){
        int x=xor_res[i*6]*2+xor_res[i*6+5];
        int y=bin2dec(&xor_res[i*6+1],4);
        int s=S_Box[i][x][y];
        for(int j=3;j>=0;j--){
            s_comp[i*4+j]=s%2;
            s/=2;
        }
    }
    // P substitution
    for(int i=0;i<32;i++){
        res[i]=s_comp[P_Table[i]-1];
    }
    return;
}
// DES Encryption function
void DES_encrypt(char key[16],char text[16],char cipher[16]){
    // Generate sub keys
    bool key_bin[64]={0};
    hex2bin(key,key_bin,16);
    bool subKey_bin[17][48]={0};
    GenSubKey(key_bin,subKey_bin);
    // IP substitution
    bool text_bin[64]={0},ip[64]={0};
    hex2bin(text,text_bin,16);
    for(int i=0;i<64;i++){
        ip[i]=text_bin[IP_Table[i]-1];
    }
    // 16 rounds of iteration
    bool l[17][32]={0},r[17][32]={0};
    for(int i=0;i<32;i++){
        l[0][i]=ip[i];
        r[0][i]=ip[32+i];
    }
    for(int i=1;i<=16;i++){
        bool f_res[32]={0};
        fFunc(r[i-1],subKey_bin[i],f_res);
        for(int j=0;j<32;j++){
            l[i][j]=r[i-1][j];
            r[i][j]=l[i-1][j]^f_res[j];
        }
    }
    // 16th Round special handling
    bool round16th[64]={0},finalRes[64]={0};
    for(int i=0;i<32;i++){
        round16th[i]=r[16][i];
        round16th[32+i]=l[16][i];
    }
    for(int i=0;i<64;i++){
        finalRes[i]=round16th[inv_IP_Table[i]-1];
    }
    bin2hex(finalRes,cipher,64);
    return;
}
// DES Decryption function
void DES_decrypt(char key[16],char cipher[16],char text[16]){
    // Generate sub keys
    bool key_bin[64]={0};
    hex2bin(key,key_bin,16);
    bool subKey_bin[17][48]={0};
    GenSubKey(key_bin,subKey_bin);
    // IP substitution
    bool cipher_bin[64]={0},ip[64]={0};
    hex2bin(cipher,cipher_bin,16);
    for(int i=0;i<64;i++){
        ip[i]=cipher_bin[IP_Table[i]-1];
    }
    // 16 rounds of iteration
    bool l[17][32]={0},r[17][32]={0};
    for(int i=0;i<32;i++){
        l[0][i]=ip[i];
        r[0][i]=ip[32+i];
    }
    for(int i=1;i<=16;i++){
        bool f_res[32]={0};
        fFunc(r[i-1],subKey_bin[16+1-i],f_res);
        for(int j=0;j<32;j++){
            l[i][j]=r[i-1][j];
            r[i][j]=l[i-1][j]^f_res[j];
        }
    }
    // 16th Round special handling
    bool round16th[64]={0},finalRes[64]={0};
    for(int i=0;i<32;i++){
        round16th[i]=r[16][i];
        round16th[32+i]=l[16][i];
    }
    for(int i=0;i<64;i++){
        finalRes[i]=round16th[inv_IP_Table[i]-1];
    }
    bin2hex(finalRes,text,64);
    return;
}
int main(){
    // 所有字符串均为经hex编码后的形式，且为小写字母
    // 搭配Python3的binascii.hexlify()使用最佳
    /* -=-=-= Encryption -=-=-= */
    char enc_key[16+1]="133457799bbcdff1"; // 8 bytes
    char enc_text[16+1]="0123456789abcdef"; // 8 bytes
    char enc_cipher[16+1]="0000000000000000"; // 8 bytes
    DES_encrypt(enc_key,enc_text,enc_cipher);
    printf("\n[+]DES Encrypt result: %s",enc_cipher);
    /* -=-=-= Decryption -=-=-= */
    char dec_key[16+1]="133457799bbcdff1"; // 8 bytes
    char dec_text[16+1]="0000000000000000"; // 8 bytes
    char dec_cipher[16+1]="85e813540f0ab405"; // 8 bytes
    DES_decrypt(dec_key,dec_cipher,dec_text);
    printf("\n[-]DES Decrypt result: %s",dec_text);
    return 0;
}