Nama Anggota Kelompok :
1. Rafael Dwiyanson Simarmata (5223600065)
2. Wira Yuda Prastha (5223600067)
   
**Description**
This Github contains several code for core features development on Dinner Dash style game. 

**How To Use**
1. Clone this repository
2. Compile the code in compiler C++

**Code Explanation**
1. Order
  - Mewakili pesanan yang dibuat oleh pelanggan.
  - Melacak status pesanan menggunakan enum OrderStatus:
  - Belum Diambil: Pesanan belum diambil oleh pelayan.
  - Di Dapur: Pesanan sedang diproses di dapur.
  = Telah Disajikan: Pesanan telah diantarkan ke pelanggan.
2. CustomerEmotion
  - Mengelola nilai emosi pelanggan, yang dimulai dari 5 dan berkurang seiring waktu jika pesanan tidak disajikan.
  - Secara otomatis mengurangi emosi pelanggan setiap detik (dalam simulasi).
  - Mengatur ulang emosi pelanggan ke nilai maksimum (5) setelah pesanan diantarkan.
3. Table
  - Mengelola sebuah meja di restoran, termasuk pesanan dan emosi pelanggan.
  - Memberikan notifikasi kepada pelayan ketika pesanan berada di dapur dan siap untuk disajikan.
  - Menampilkan status saat ini dari meja, termasuk pesanan dan emosi pelanggan.
