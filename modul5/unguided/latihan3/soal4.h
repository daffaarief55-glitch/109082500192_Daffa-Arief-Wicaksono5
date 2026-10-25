
#ifndef SOAL4_H_INCLUDED
#define SOAL4_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElemenSoal4 *address;

struct ElemenSoal4 {
    infotype info;
    address next;
};

struct ListSoal4 {
    address First;
};

void buatList(ListSoal4 &L);
address buatElemen(infotype x);
void tambahAkhir(ListSoal4 &L, address P);
void tampilkanList(ListSoal4 L);
int hitungTotalInfo(ListSoal4 L);

#endif
