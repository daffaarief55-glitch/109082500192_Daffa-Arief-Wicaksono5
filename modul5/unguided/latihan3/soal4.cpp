
#include "Soal4.h"

void buatList(ListSoal4 &L) {
    L.First = Nil;
}

address buatElemen(infotype x) {
    address P = new ElemenSoal4;
    P->info = x;
    P->next = Nil;
    return P;
}

void tambahAkhir(ListSoal4 &L, address P) {
    if (L.First == Nil) {
        L.First = P;
    } else {
        address Q = L.First;

        while (Q->next != Nil) {
            Q = Q->next;
        }

        Q->next = P;
    }
}

void tampilkanList(ListSoal4 L) {
    address P = L.First;

    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }

    cout << endl;
}

int hitungTotalInfo(ListSoal4 L) {
    address P = L.First;
    int total = 0;

    while (P != Nil) {
        total += P->info;
        P = P->next;
    }

    return total;
}
