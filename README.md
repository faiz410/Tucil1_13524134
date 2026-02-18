# Queens Board Solver

Queens Board Solver adalah program bahasa C yang dapat mencari solusi dari permainan Papan Queens LinkedIn dengan pendekatan algoritma Brute Froce. Program ini akan meminta file .txt berisi papan game dengan format susunan seperti yang disebutkan setelah bagian ini. Setelah file tersebut telah dibaca, program akan mencari solusi yang valid dengan algorima Brute Force dan menampilkan hasilnya. Sebelum melakukan pencarian solusi, program akan melakukan validasi papan input, seperti pengecekan dimensi dan karakter yang digunakan.

## Format File .txt Input
1. Isi file adalah kumpulan **huruf alfabet kapital** yang disusun dalam bentuk n buah baris berisi n buah huruf sehingga membentuk matriks persegi berukuran n. Warna petak yang berbeda ditandai dengan jenis huruf yang berbeda.
2. Jarak antar elemen dapat diterapkan dengan menggunakan **spasi** antar elemen dalam satu baris, atau menggunakan **baris baru kosong** di antara dua baris. 
3. Jenis huruf (warna petak), baris, dan kolom memiliki **jumlah yang sama**
4. **Warna petak/huruf yang sama** sebaiknya **bertetangga satu sama lain** (dalam matriks), tetapi jika ada yang terpisah, program akan tetap menanganinya sebagai satu warna yang sama.

## Cara Menjalankan Program

1.  Buka repositori di VS Code lokal
2.  Pindahkan file-file papan (.txt) yang telah dibuat ke folder src
3.  Jalankan program dengan menekan tombol 'Mulai' di panel kanan atas. Jika menjalankan program menggunakan file executable di folder bin, pindahkan/salin file-file papan tadi ke folder tersebut sebelum memulai
4.  Masukkan nama file yang diinginkan saat diminta program
5.  Program akan mulai memproses file papan dan mencari solusinya

## Pembuat Program

Program ini dibuat oleh Salman Faiz Assidqi (NIM 13524134)