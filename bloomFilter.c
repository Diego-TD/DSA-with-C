// //
// // Created by Diego Torres Durante on 11/4/24.
// //
//
// #define BLOOM_SIZE 1000
// #define BYTE_SIZE 8
// #include <stdbool.h>
// #include <stdio.h>
// unsigned char bloomFilter[BLOOM_SIZE / BYTE_SIZE] = {0};
//
// int primaryHash(char *url) {
//     int position = 1;
//     while (*url) {
//         position = (position * 99 + *url) % BLOOM_SIZE;
//         url++;
//     }
//     printf("1st hash byte position: %d bit position: %d \n",position/8, position%8);
//     return position;
// }
//
// int secondaryHash(char *url) {
//     int position = 1;
//     while (*url) {
//         position = (position * 47 + *url) % BLOOM_SIZE;
//         url++;
//     }
//     printf("2nd hash byte position: %d bit position: %d \n",position/8, position%8);
//     return position;
// }
//
// int tertiaryHash(char *url) {
//     int position = 1;
//     while (*url) {
//         position = (position * 243 + *url) % BLOOM_SIZE;
//         url++;
//     }
//     printf("3rd hash byte position: %d bit position: %d \n",position/8, position%8);
//     return position;
// }
//
// void setBit(int bit) {
//     bloomFilter[bit/8] |= 1 << bit %8;
// }
//
// void addUrl(char *url) {
//     setBit(primaryHash(url));
//     setBit(secondaryHash(url));
//     setBit(tertiaryHash(url));
// }
//
// bool isBitSet(int bit) {
//     return bloomFilter[bit / 8] & (1 << (bit % 8));
// }
//
// bool contains(char* value) {
//     printf("\nVerifying\n");
//     return isBitSet(primaryHash(value)) && isBitSet(secondaryHash(value)) && isBitSet(tertiaryHash(value));
// }
//
// void printBloomFilter() {
//     for (int i = 0; i < BLOOM_SIZE / BYTE_SIZE; ++i) {
//         printf("Byte %d: ", i);
//         for (int j = 7; j >= 0; j--) {
//             printf("%d",bloomFilter[i] >> j & 1);
//         }
//         printf("\n");
//     }
//     printf("\n\n");
// }
//
// int main () {
//     char *url1,*url2;
//     url1 = "sanpedrodotcom";
//
//
//     printf("Is %s in Bloom Filter? %s\n\n", url1, contains(url1) ? "Yes" : "No");
//     printBloomFilter();
//
//     printf("Add %s\n",url1);
//     addUrl(url1);
//     printf("Is %s in Bloom Filter? %s\n\n", url1, contains(url1) ? "Yes" : "No");
//     printBloomFilter();
//
//     url2 = "picapiedradotcom";
//     printf("Add %s\n",url2);
//     addUrl(url2);
//
//
//     printf("Is %s in Bloom Filter? %s\n\n", url2, contains(url2) ? "Yes" : "No");
//     printBloomFilter();
//
//     url2 = "picapiedradotcnm";
//     printf("\nThis should be false\n");
//     printf("Is %s in Bloom Filter? %s\n\n", url2, contains(url2) ? "Yes" : "No");
//     printBloomFilter();
//
//     return 0;
// }
//
//
//
