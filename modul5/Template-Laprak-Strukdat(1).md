# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori
### A. Singly Linked List<br/>
Singly Linked List adalah struktur data yang terdiri dari beberapa node yang saling terhubung menggunakan pointer. Setiap node memiliki dua bagian, yaitu info untuk menyimpan data dan next untuk menyimpan alamat node berikutnya. Data pada Singly Linked List dibaca secara berurutan mulai dari node pertama sampai node terakhir. Pada node terakhir, pointer next bernilai NULL karena tidak ada node selanjutnya [1].

#### 1.Struktur Elemen pada Singly Linked List
Dalam Singly Linked List, setiap node memiliki dua bagian, yaitu info dan next. Info digunakan untuk menyimpan data, sedangkan next digunakan untuk menunjuk ke node berikutnya. Selain itu, ada First yang berfungsi untuk menyimpan alamat node pertama. Jika list masih kosong, maka First bernilai Nil atau NULL. Bagian-bagian ini digunakan untuk membuat dan mengatur data dalam Singly Linked List [1].

#### 2. Pointer dan Address
Pointer adalah variabel yang digunakan untuk menyimpan alamat memori suatu data. Pada Singly Linked List, address digunakan untuk menyimpan alamat node. Pointer bisa digunakan untuk mengambil data pada node dengan P->info dan berpindah ke node berikutnya dengan P->next. Jadi, pointer berfungsi untuk membantu program mengakses dan menghubungkan setiap node dalam linked list [1][2].

#### 3. Pembuatan dan Penambahan Elemen
Pembuatan list dimulai dengan fungsi CreateList untuk membuat list dalam keadaan kosong. Selanjutnya, fungsi alokasi digunakan untuk membuat node baru dan mengisi datanya pada bagian info. Setelah itu, node bisa dimasukkan ke dalam list menggunakan insertFirst untuk menambahkan data di awal list atau insertLast untuk menambahkan data di akhir list [1].

### B.Operasi pada Singly Linked List<br/>
Operasi pada Singly Linked List digunakan untuk mengelola data yang ada di dalam list. Beberapa operasi yang dipelajari dalam Modul 5 yaitu mencari data, menampilkan semua data yang ada di dalam list, dan menghitung total nilai dari seluruh data tersebut [1].

#### 1. Searching atau Pencarian Elemen
Searching adalah proses untuk mencari data tertentu di dalam Singly Linked List. Pencarian dilakukan dengan memeriksa data pada setiap node mulai dari node pertama sampai data yang dicari ditemukan atau sampai akhir list. Fungsi findElm(L, x) digunakan untuk mencari data yang nilainya sama dengan x. Jika data ditemukan, fungsi akan mengembalikan alamat node tersebut. Jika data tidak ditemukan, fungsi akan mengembalikan Nil [1].

#### 2. Penelusuran dan Penjumlahan Seluruh Elemen
Penelusuran data pada Singly Linked List dimulai dari node pertama yang ditunjuk oleh L.First. Setelah itu, pointer berpindah ke node berikutnya menggunakan P = P->next. Proses ini digunakan untuk menampilkan semua data atau menghitung total nilai yang ada di dalam list. Untuk menghitung total, program menggunakan variabel yang awalnya bernilai nol, kemudian setiap nilai info dijumlahkan sampai semua node selesai diperiksa dan pointer mencapai Nil [1][2].

#### 3.Implementasi Singly Linked List dalam C++
Program Singly Linked List dalam C++ dibagi menjadi tiga file, yaitu file header (.h), file implementasi (.cpp), dan file utama (main.cpp). File header digunakan untuk menuliskan struktur data dan deklarasi fungsi. File implementasi berisi kode untuk menjalankan fungsi-fungsi tersebut, sedangkan file main.cpp digunakan untuk menjalankan program. Pembagian ini membuat kode lebih rapi dan mudah dipahami, serta membantu menerapkan konsep Abstract Data Type (ADT) [1][2].

## Guided 

### 1. listBuah.h

```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```
kode tersebut digunakan sebagai dasar untuk membuat program Singly Linked List yang menyimpan data buah. Di dalamnya terdapat struktur data dan deklarasi fungsi untuk menambahkan, menghapus, mengubah, menampilkan, serta mencari data buah. Dengan struktur ini, pengelolaan data dalam program C++ menjadi lebih rapi dan mudah dipahami.

### 2. listBuah.cpp

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - UPDATE -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - SEARCHING -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
  }
```
kode ini merupakan program Singly Linked List menggunakan C++ untuk menyimpan dan mengelola data buah. Program ini bisa digunakan untuk menambah, menghapus, menampilkan, dan mengubah data buah. Selain itu, program juga bisa mencari buah berdasarkan nama, alamat node, dan rentang harga. Dengan program ini, data buah bisa dikelola dengan lebih mudah dan teratur.

### 3. main.cpp

```C++
  #include "listBuah.h"

  #include<iostream>
  using namespace std;

  int main(){
      linkedlist List;
      address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
      createList(List);

      dataBuah dtBuah;

      nodeA = alokasi("Jeruk", 100, 3000);
      nodeB = alokasi("Apel", 75, 4000);
      nodeC = alokasi("Pir", 87, 5000);
      nodeD = alokasi("Semangka", 43, 11500);
      nodeE = alokasi("Durian", 15, 31450);

      insertFirst(List, nodeA);
      insertLast(List, nodeB);
      insertAfter(List, nodeC, nodeA);
      insertAfter(List, nodeD, nodeC);
      insertLast(List, nodeE);

      cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
      printList(List);
      cout << "jumlah node : " << nbList(List) << endl;
      cout << endl;

      updateFirst(List);
      printList(List);
      updateLast(List);
      printList(List);
      updateAfter(List, nodeD);
      printList(List);

      cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
      printList(List);
      cout << "jumlah node : " << nbList(List) << endl;
      cout << endl;

      FindNodeByData(List, "kelapa");
      FindNodeByAddress(List, nodeC);
      FindNodeByRange(List, 5000, 10000);

      delFirst(List);
      printList(List);
      delLast(List);
      printList(List);
      delAfter(List, nodeD, nodeC);
      printList(List);

      cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
      printList(List);
      cout << "jumlah node : " << nbList(List) << endl;
      cout << endl;

      deleteList(List);
      cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
      printList(List);
      cout << "jumlah node : " << nbList(List) << endl;
      cout << endl;

      return 0;
  }
```
Kode main() merupakan program utama untuk mengelola data buah menggunakan Singly Linked List. Program ini menjalankan fungsi untuk menambah, menampilkan, mengubah, mencari, dan menghapus data buah. Tujuannya agar kita bisa memahami cara kerja Singly Linked List dalam C++.

## Unguided 

### 1. (isi dengan soal unguided 1)

```singlylist.h
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(const List &L);
void insertFirst(List &L, address P);
address findElm(const List &L, infotype x);
int totalInfo(const List &L);

#endif 
```

```singlylist.cpp#include <iostream>
#include "Singlylist.h"
using namespace std;

void createList(List &L) {
    L.first = nullptr;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(address &P) {
    if (P != nullptr) {
        delete P;
        P = nullptr;
    }
}

void printInfo(const List &L) {
    address P = L.first;
    while (P != nullptr) {
        cout << P->info;
        if (P->next != nullptr) cout << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    if (P == nullptr) return;
    P->next = L.first;
    L.first = P;
}

address findElm(const List &L, infotype x) {
    address P = L.first;
    while (P != nullptr) {
        if (P->info == x) return P;
        P = P->next;
    }
    return nullptr;
}

int totalInfo(const List &L) {
    int total = 0;
    address P = L.first;
    while (P != nullptr) {
        total += P->info;
        P = P->next;
    }
    return total;
}
```

```main2.cpp
#include <iostream>
#include "Singlylist.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "Isi linked list: ";
    printInfo(L);

    address hasil = findElm(L, 8);
    if (hasil != nullptr) {
        cout << hasil->info << " ditemukan dalam list" << endl;
    } else {
        cout << "Data tidak ditemukan dalam list" << endl;
    }

    cout << "Total info dari kelima elemen adalah "
         << totalInfo(L) << endl;

    while (L.first != nullptr) {
        address Hapus = L.first;
        L.first = L.first->next;
        dealokasi(Hapus);
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

ketiga kode tersebut digunakan untuk membuat program Singly Linked List menggunakan C++. Kode pertama berisi struktur data dan deklarasi fungsi, kode kedua berisi proses dari setiap fungsi, sedangkan kode ketiga digunakan untuk menjalankan program. Dari ketiga kode tersebut, kita bisa belajar cara menambah data, menampilkan isi list, mencari angka, menghitung total nilai, dan menghapus data dari memori.

### 2. (isi dengan soal unguided 2)

```sll.h

#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED

#include <iostream>
using namespace std;

#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void insertLast(List &L, address P);
void printInfo(List L);
address findElm(List L, infotype x);

#endif

```

```sll.cpp

#include "SLL.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void insertLast(List &L, address P) {
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

void printInfo(List L) {
    address P = L.First;

    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }

    cout << endl;
}

// Fungsi baru untuk mencari elemen
address findElm(List L, infotype x) {
    address P = L.First;

    while (P != Nil) {
        if (P->info == x) {
            return P;
        }

        P = P->next;
    }

    return Nil;
}

```

```main3.cpp

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

```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)



ketiga kode tersebut digunakan untuk membuat program Singly Linked List dengan bahasa C++. Kode pertama berisi struktur data dan deklarasi fungsi, kode kedua berisi implementasi fungsi, sedangkan kode ketiga digunakan untuk menjalankan program. Program ini dapat menambahkan data di akhir list, menampilkan seluruh data, dan mencari elemen berdasarkan nilai yang dimasukkan.

### 3. (isi dengan soal unguided 3)

```soal4.h

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

```

```soal4.cpp

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

```

```main4.cpp
#include <iostream>
#include "soal4.h"

using namespace std;

int main() {
    ListSoal4 L;

    buatList(L);

    tambahAkhir(L, buatElemen(9));
    tambahAkhir(L, buatElemen(12));
    tambahAkhir(L, buatElemen(8));
    tambahAkhir(L, buatElemen(0));
    tambahAkhir(L, buatElemen(2));

    cout << "Total info dari kelima elemen adalah "
         << hitungTotalInfo(L) << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)


ketiga kode tersebut saling berhubungan untuk menjalankan program Singly Linked List menggunakan C++. Kode pertama berisi struktur data dan deklarasi fungsi, kode kedua berisi proses dari setiap fungsi, sedangkan kode ketiga digunakan untuk memasukkan data dan menghitung total nilainya. Dengan program ini, kita dapat memahami cara menambahkan data di akhir list dan menjumlahkan seluruh data yang tersimpan.

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
