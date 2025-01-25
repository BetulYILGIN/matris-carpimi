# Matrix Multiplication with Threads

## Açıklama

Bu C programı, iki matrisi çarpmak için çoklu iş parçacıklarını (threads) kullanır. Program, rastgele sayılarla doldurulmuş iki `MAX x MAX` boyutlarında matris alır ve her bir iş parçacığını kullanarak matris çarpımını hesaplar. Her iş parçacığı, bir elemanın çarpımını hesaplar ve sonucu döndürür.

## Özellikler

- İki `MAX x MAX` boyutlarında matrisin çarpımı hesaplanır.
- Her iş parçacığı, bir elemanın çarpımını hesaplar.
- Matris A ve B rastgele sayılarla doldurulur.
- Sonuç matrisini iş parçacıkları tamamladıktan sonra yazdırır.

## Gereksinimler

- C derleyicisi (örneğin, GCC)
- pthread kütüphanesi

## Kullanım

1. C kaynak kodunu bir dosyaya kopyalayın.
2. Programı bir C derleyicisiyle derleyin:
   ```bash
   gcc -o matrix_multiplication matrix_multiplication.c -lpthread

## Programı çalıştırın:
bash
Kopyala
Düzenle
./matrix_multiplication
Program, iki matrisi rastgele olarak oluşturacak ve bunların çarpımını iş parçacıklarıyla gerçekleştirecek. Sonuç, konsolda gösterilecektir.

### Örnek Çıktı

A MATRISI  
3 5 4 7 2 
1 9 3 4 6 
8 2 5 1 9 
0 7 2 6 3 
4 8 1 6 9 

B MATRISI 
2 3 9 4 6 
5 1 8 4 2 
3 2 7 1 5 
8 6 3 2 9 
0 4 1 9 7 

### MATRIS CARPIMI SONUCU  
127 92 142 92 116 
69 83 90 68 73 
126 100 104 75 136 
51 46 77 40 76 
77 94 105 63 95


## Açıklamalar
Program, iki MAX x MAX boyutlarında matrisi rastgele doldurur.
Her bir elemanın çarpımı için ayrı bir iş parçacığı (thread) oluşturulur.
Her iş parçacığı, matrisin bir elemanının çarpımını hesaplar.
Tüm iş parçacıkları tamamlandıktan sonra sonuçlar yazdırılır.


## Notlar
MAX sabiti matrisin boyutunu belirtir (bu örnekte MAX = 5 olarak ayarlanmıştır).
Program pthread kütüphanesini kullanarak çoklu iş parçacıkları (threads) ile paralel hesaplama yapar.
Programda kullanılan malloc ve free fonksiyonları, bellek yönetimini sağlar.
