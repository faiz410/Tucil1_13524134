# QueensBoardSolver
Program C untuk solve permainan papan 

Informasi untuk file .txt input:
1. Warna direpresentasikan sebagai huruf kapital alphabet 
2. Warna, baris, dan kolom petak berjumlah sama
3. Spasi dan baris kosong akan diabaikan (jika ada). Hal ini memungkinkan petak dengan elemen berjarak.

Pesan error mungkin akan muncul jika ketentuan di atas ada yang tidak terpenuhi

Cara Jalankan Program:
1. Buka repositori di vscode lokal
2. Pindahkan file papan (.txt) ke folder src
3. Jalankan program dengan tombol 'Mulai'
4. Masukkan nama file saat diminta program
5. Selesai

Langkah Pencarian Solusi Program dengan Algoritma Brute Force (Maybe):
1. Pilih warna pertama (paling kiri atas matriks papan)
2. Pilih posisi ratu di posisi pertama warna (paling kiri atas)
3. Jika posisi ratu valid (tidak ada ratu di baris dan kolom yang sama serta di dekatnya), letakkan ratu di posisi tersebut
4. Jika tidak valid, pilih ratu di posisi kedua warna dan seterusnya sampai valid.
5. Jika tidak valid juga sampai akhir pencarian, warna sebelumnya akan dipilih untuk dicari kembali ratunya (Posisi ratu yang dipilih akan berbeda dari sebelumnya)
6. Jika dipilih warna pertama (dari awal atau hasil backtracking) dan tidak valid juga, papan tidak memiliki solusi
7. jika posisi ratu valid (poin 3 atau setelah backtracking), warna berikutnya akan dipilih untuk dicari posisi ratu
8. Jika posisi ratu valid sampai warna terkahir, papan akan memiliki solusi

Contoh File Test dan Keluaran Program:
1. 
Input:
A A B B
C C D D
E E F F
Output:
Kesalahan: dimensi papan tidak persegi
2. 
Input:
A A A A
B B B B
A A A A
B B C C
Output:
Kesalahan: jumlah warna tidak sama dengan dimensi papan
3. 
Input:
A A A B B C C D D E
A A B B C C D D E E
F F G G H H I I J J
F F G G H H I I J J
A B C D E F G H I J
J I H G F E D C B A
A A A A A B B B B B
C C C C C D D D D D
E E E E E F F F F F
G G G G G H H H H H
Output (Huruf kecil adalah ratu):
a A A B B C C D D E
A A B B c C D D E E
F f G G H H I I J J
F F G G H H i I J J
A B C D E F G H I j
J I H g F E D C B A
A A A A A b B B B B
C C C C C D D d D D
E E e E E F F F F F
G G G G G H H H h H
4. 
Input:
A A A B B
A A B B B
C C D D E
C C D E E
C D D E E
Output:
a A A B B
A A B b B
C c D D E
C C D E e
C D d E E
5. 
Input:
A A A A A A A A A A A A B
B B B B B B B B B B B B C
C C C C C C C C C C C C D
D D D D D D D D D D D D E
E E E E E E E E E E E E F
F F F F F F F F F F F F G
G G G G G G G G G G G G H
H H H H H H H H H H H H I
I I I I I I I I I I I I J
J J J J J J J J J J J J K
K K K K K K K K K K K K L
L L L L L L L L L L L L M
M M M M M M M M M M M M A
Output:
Waktu pencarian: 249370.00 ms
Jumlah iterasi: 695002157
Tidak ditemukan solusi

Program by Salman Faiz Assidqi (13524134)
