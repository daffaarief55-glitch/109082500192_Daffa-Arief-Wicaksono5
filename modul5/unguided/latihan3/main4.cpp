
#include "Soal4.h"

int main() {
    ListSoal4 L;

    buatList(L);

    tambahAkhir(L, buatElemen(9));
    tambahAkhir(L, buatElemen(12));
    tambahAkhir(L, buatElemen(8));
    tambahAkhir(L, buatElemen(0));
    tambahAkhir(L, buatElemen(2));

    cout << "Isi list: ";
    tampilkanList(L);

    cout << "Total info dari kelima elemen adalah "
         << hitungTotalInfo(L) << endl;

    return 0;
}
