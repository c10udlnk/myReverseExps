// By c10udlnk(https://github.com/c10udlnk)
// Enjoy it!

#include <cstdio>
unsigned char S_Box[256]={0};
// RC4 initial
void Init(unsigned char * key,int keyLen){
    unsigned char T[256]={0};
    for(int i=0;i<256;i++){
        S_Box[i]=i;
        T[i]=key[i%keyLen];
    }
    int j=0;
    for(int i=0;i<256;i++){
        j=(j+S_Box[i]+T[i])%256;
        unsigned char tmp=S_Box[i];
        S_Box[i]=S_Box[j];
        S_Box[j]=tmp;
    }
    return;
}
// RC4 Encryption and Decryption (The same)
void RC4(unsigned char * key,int keyLen,unsigned char * data,int dataLen){
    Init(key,keyLen);
    int i=0,j=0;
    for(int k=0;k<dataLen;k++){
        i=(i+1)%256;
        j=(j+S_Box[i])%256;
        unsigned char tmp=S_Box[i];
        S_Box[i]=S_Box[j];
        S_Box[j]=tmp;
        data[k]^=S_Box[(S_Box[i]+S_Box[j])%256];
    }
}
// Hex to Char
const char HexChar[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
void hex2char(unsigned char * hex,unsigned char * chr,int hexLen){
    int lastIdx=0;
    for(int i=0;i<hexLen;i++){
        int index=0;
        for(index=0;index<16;index++){
            if(HexChar[index]==hex[i]) break;
        }
        if(index==16){
            printf("Please check your hex string at POSITION [%d] again.\n",i);
            return;
        }
        if(i&1) chr[i/2]=lastIdx*16+index;
        else lastIdx=index;
    }
    return;
}
int main(){
    // 所有字符串均为经hex编码后的形式，且为小写字母
    // 搭配Python3的binascii.hexlify()使用最佳
    // RC4的加密与解密算法相同
    // 记得更改对应的dataLen和keyLen
    unsigned char key_hex[]="746831735f31735f6b33792121212121";
    unsigned char data_hex[]="8bd2d95d95ff7e5f295612b9efec8bd045";
    int keyLen=16,dataLen=17;
    unsigned char key[keyLen+1]={0};
    unsigned char data[dataLen+1]={0};
    hex2char(key_hex,key,keyLen*2);
    hex2char(data_hex,data,dataLen*2);
    RC4(key,keyLen,data,dataLen);
    printf("\n[*]RC4 Encrypt/Decrypt result: ");
    for(int i=0;i<dataLen;i++) printf("%02x",data[i]);
    // printf("\n%s",data);
    return 0;
}