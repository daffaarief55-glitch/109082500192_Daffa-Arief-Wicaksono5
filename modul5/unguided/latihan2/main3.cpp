
#include "SLL.h"

int main() {
    List L;
    address P;

    createList(L);

    insertLast(L, alokasi(2));
    insertLast(L, alokasi(4));
    insertLast(L, alokasi(6));
    insertLast(L, alokasi(8));
    insertLast(L, alokasi(10));

    cout << "Isi list: ";
    printInfo(L);

    P = findElm(L, 8);

    if (P != Nil) {
        cout << "8 ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    return 0;
}

