#include <stdio.h>
#include <string.h>
void RC4_init(unsigned char* Sbox, unsigned char* key, int keylen) {
  for (size_t i = 0; i < 256; i++) {
    Sbox[i] = i;
  }
  size_t j = 0;
  for (size_t i = 0; i < 256; i++) {
    j = (j + Sbox[i] + key[i % keylen]) % 256;
    char temp = Sbox[i];
    Sbox[i] = Sbox[j];
    Sbox[j] = temp;
  }
}

void RC4(unsigned char* Sbox,
         unsigned char* data,
         unsigned char* key,
         int datalen,
         int keylen) {
  RC4_init(Sbox, key, keylen);
  size_t i = 0, j = 0;
  for (size_t k = 0; k < datalen; k++) {
    i = (i + 1) % 256;
    j = (j + Sbox[i]) % 256;
    char temp = Sbox[i];
    Sbox[i] = Sbox[j];
    Sbox[j] = temp;
    data[k] ^= Sbox[(Sbox[i] + Sbox[j]) % 256];
  }
}

int main(int argc, char const* argv[]) {
  //   test
  unsigned char Sbox[256] = {0};
  unsigned char data[] = "helloworld";
  unsigned char key[] = "1234";
  RC4(Sbox, data, key, strlen(data), strlen(key));
  printf("%s\n", data);
  RC4(Sbox, data, key, strlen(data), strlen(key));
  printf("%s\n", data);
  puts("-----------------------------");
  unsigned char datahex[] = "\x99\x65\xf4\x48\x29\x90\xa9\x8f";
  unsigned char keyhex[] = "flag";
  //   strlen(key)函数求的是字符串的实际长度，它求得方法是从开始到遇到第一个'\0'
  RC4(Sbox, datahex, keyhex, strlen(datahex), strlen(keyhex));
  printf("%s\n", datahex);
  for (size_t i = 0; i < strlen(datahex); i++)
    printf("\\x%.2x", (int)datahex[i]);
  puts("");
  RC4(Sbox, datahex, keyhex, strlen(datahex), strlen(keyhex));
  printf("%s\n", datahex);
  for (size_t i = 0; i < strlen(datahex); i++)
    printf("\\x%.2x", (int)datahex[i]);
  puts("");
  return 0;
}