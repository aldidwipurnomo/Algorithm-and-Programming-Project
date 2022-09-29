#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#define maks 100

typedef struct tanggal{
	int hari;
	int bulan;
	int tahun;
}tgl;
typedef struct data_buku{
	char pelanggan[100];
	int novel;
	int ensiklopedia;
	int komik;
	int biografi;
	int kamus;
	struct tanggal tgl;
}data_buku;


//FUNCTION PENDATAAN PENJUALAN BUKU {VIANA}
void data_penjualan(int pilihan,int j){
	data_buku buku[maks]; //PEMANGGILAN STRUCT PADA TYPEDEF STRUCT data_buku.
	if(pilihan==1){//KETIKA PENGGUNA PROGRAM MEMILIH PILIHAN 1 MAKA, AKAN MASUK KE PROGRAM PENDATAAN PENJUALAN BUKU 
		int i;
		FILE *file; //PENDEKLARASIAN FILE
		file = fopen("sales.txt","w"); //buat memasukan data pada file
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),14);
		printf("\t\t\tSELAMAT DATANG DI THE GIFTED STORE\n");
		printf("\t\t======================================================\n\n\n");
		printf("Terdapat %d data yang akan diisi.",j);
		int sum_ensi[j],sum_nov[j],sum_bio[j],sum_kam[j],sum_kom[j],total[j];
		printf("\n");
		
		//Melakukan pengeluaran output mengenai daftar harga.
		printf("\t\t\tDAFTAR HARGA BUKU\n");
		for(i=1;i<=13;i++){
			printf("_____");
		}
		puts("");
		printf("No\tJenis Buku\tNama Buku\t\tHarga Buku\n");
		for(i=1;i<=13;i++){
			printf("_____");
		}
		puts("");
		printf("1.\tEnsiklopedia\tMesir Kuno\t\tRp150.000\n");
		printf("2.\tBiografi\tSoekarno\t\tRp140.000\n");
		printf("3.\tNovel\t\tDear Nathan\t\tRp 90.000\n");
		printf("4.\tKamus\t\tInggris-Indonesia\tRp 50.000\n");
		printf("5.\tKomik\t\tDoraemon\t\tRp 30.000\n");
		for(i=1;i<=13;i++){
			printf("_____");
		}
		puts("");printf("*Apabila anda tidak memesan ketik 0.\n*Pada bagian tanggal diharapkan menginputkan seperti contoh: dd mm yyyy.");puts("");puts("");
		
		
		//MENDATA PEMBELIAN.
		for(i=1;i<=j;i++){
			printf("Pembeli ke-%d\n",i);
			printf("__________________\n");
			printf("Tanggal : "); scanf("%d %d %d",&buku[i].tgl.hari,&buku[i].tgl.bulan,&buku[i].tgl.tahun);
			printf("Masukan nama anda : ");
			fflush(stdin);
			gets(buku[i].pelanggan);
			
			printf("\nHalo %s, selamat datang di The Gifted Store selamat berbelanja.\n\n",buku[i].pelanggan);
			printf("\tPESANAN PEMBELIAN\n");//banyak buku yang ingin dibeli.
			printf("----------------------------------\n");
			printf("Banyak Ensiklopedia\t: "); scanf("%d",&buku[i].ensiklopedia);
			printf("Banyak Biografi\t\t: "); scanf("%d",&buku[i].biografi);
			printf("Banyak Novel\t\t: "); scanf("%d",&buku[i].novel);
			printf("Banyak Kamus\t\t: "); scanf("%d",&buku[i].kamus);
			printf("Banyak Komik\t\t: "); scanf("%d",&buku[i].komik);
			printf("----------------------------------\n\n");
		}
		printf("\n\nData berhasil kami simpan.........\n\n");
		fwrite(buku, sizeof(buku), 1, file);//UNTUK MENYIMPAN DATA PADA FILE
		fclose(file);//MENYUDAHI OPERASI FILE.
	}
}


//FUCTION PENCETAKAN LAPORAN PENJUALAN BUKU TERURUT BERDASARKAN TANGGAL TRANSAKSI {AlDI}
void bubbleSort(struct data_buku A[],int t){
	data_buku swap;
	int i,j;
	for(i=1;i<=t;i++){
		for(j=1;j<=t-i;j++){
			if(A[j].tgl.tahun > A[j+1].tgl.tahun){
				swap = A[j];
				A[j] = A[j+1];
				A[j+1] = swap;
			} 
			else if(A[j].tgl.tahun==A[j].tgl.tahun){
				if(A[j].tgl.bulan > A[j+1].tgl.bulan){
					swap = A[j];
					A[j] = A[j+1];
					A[j+1] = swap;
				} 
				else if(A[j].tgl.bulan==A[j+1].tgl.bulan){
					if(A[j].tgl.hari > A[j+1].tgl.hari){
						swap = A[j];
						A[j] = A[j+1];
						A[j+1] = swap;
					} 
				}
			}
		}
	}
}
	
void Laporan_penjualan_TT(int pilihan,int j){
	if(pilihan==2){ //KETIKA PENGGUNA PROGRAM MEMILIH PILIHAN 2 MAKA, AKAN MASUK KE PROGRAM PENCETAKAN LAPORAN PENJUALAN BUKU TERURUT BERDASARKAN PRODUK YANG TERJUAL PALING BANYAK
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),6);
		int i,k,hari,bulan,tahun;
		data_buku bukuout[maks]; //PEMANGGILAN STRUCT PADA TYPEDEF STRUCT data_buku.
		FILE *fileout;
		fileout= fopen("sales.txt","r");//buat membuka file yang mana tempat data disimpan
		fread(bukuout, sizeof(bukuout),1,fileout); //buat ngeread data.
		
		bubbleSort(bukuout,j); //melakukan sorting dengn memasukan struct data_buku dan batas.
		printf("PILIHAN BULAN:\n");//melakukan pengeluaran output bulan untuk pilihan
		for(i=1;i<=j;i++){
			if(bukuout[i].tgl.tahun!=bukuout[i+1].tgl.tahun||bukuout[i].tgl.bulan!=bukuout[i+1].tgl.bulan){
			printf("%d-%d\n",bukuout[i].tgl.bulan,bukuout[i].tgl.tahun);	
			}
		}
		printf("\n\nTanggal Transaksi Bulanan (MM YYYY): ");
		scanf("%d %d",&bulan,&tahun);
		
		
		//pada bagian ini kami ingin membuat program yang mengeluarkan data berdasarkan bulan yang dipilih ini bertujuan agar bisa mengeluarkan laporan bulanan.
		//guna mempermudah saat melihat data yang dimiliki
		
		//PRINT RESI.
		int ensi=0,nov=0,bio=0,kam=0,kom=0;
		for(i=1;i<=j;i++){
			if(bulan==bukuout[i].tgl.bulan&&tahun==bukuout[i].tgl.tahun){
			int sum_ensi[j],sum_nov[j],sum_bio[j],sum_kam[j],sum_kom[j],total[j];
			sum_ensi[i] = 150000*bukuout[i].ensiklopedia;
			sum_bio[i] = 140000*bukuout[i].biografi;
			sum_nov[i] = 90000*bukuout[i].novel;
			sum_kam[i]	= 50000*bukuout[i].kamus;
			sum_kom[i] = 30000*bukuout[i].komik;
			total[i] = sum_ensi[i]+sum_bio[i]+sum_nov[i]+sum_kam[i]+sum_kom[i];
			puts("");
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),3);
			printf("\tRESI PEMBAYARAN\n");
			printf("Tanggal	: %d-%d-%d\n",bukuout[i].tgl.hari,bukuout[i].tgl.bulan,bukuout[i].tgl.tahun);
			printf("Nama	: %s\n",bukuout[i].pelanggan);
			printf("Nomor	: %d\n",i);
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
			printf("-----------------------------------\n");
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),3);
			printf("%d Ensiklopedia		: Rp %d\n",bukuout[i].ensiklopedia,sum_ensi[i]);
			printf("%d Biografi		: Rp %d\n",bukuout[i].biografi,sum_bio[i]);
			printf("%d Novel			: Rp %d\n",bukuout[i].novel,sum_nov[i]);
			printf("%d Kamus			: Rp %d\n",bukuout[i].kamus,sum_kam[i]);
			printf("%d Komik			: Rp %d\n",bukuout[i].komik,sum_kom[i]);
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
			printf("------------------------------------\n");
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),3);
			printf("Total Pembayaran	: Rp %d\n",total[i]);
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
			printf("------------------------------------\n");
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),3);
			
			ensi+= bukuout[i].ensiklopedia;
			nov+= bukuout[i].novel;
			bio+= bukuout[i].biografi;
			kam+= bukuout[i].kamus;
			kom+= bukuout[i].komik;
			puts(""); puts("");
			}
		}
		
		if(bulan<=12&&bulan>=1){
		for(i=1;i<=21;i++){
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),7);
			printf("+++++");
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),6);
		}
		puts("");puts("");
		
		//LAPORAN BULANAN.
		printf("\t\t\t\t\tLAPORAN PENJUALAN BULANAN\n");
		
		if(bulan==1){
			printf("\t\t\t\t\t      Januari %d\n\n",tahun);
		} else if(bulan==2){
			printf("\t\t\t\t\t      Februari %d\n\n",tahun);
		} else if(bulan==3){
			printf("\t\t\t\t\t\t Maret %d\n\n",tahun);
		} else if(bulan==4){
			printf("\t\t\t\t\t\t April %d\n\n",tahun);
		} else if(bulan==5){
			printf("\t\t\t\t\t\t Mei %d\n\n",tahun);
		} else if(bulan==6){
			printf("\t\t\t\t\t\t Juni %d\n\n",tahun);
		} else if(bulan==7){
			printf("\t\t\t\t\t\t Juli %d\n\n",tahun);
		} else if(bulan==8){
			printf("\t\t\t\t\t      Agustus %d\n\n",tahun);
		} else if(bulan==9){
			printf("\t\t\t\t\t      September %d\n\n",tahun);
		} else if(bulan==10){
			printf("\t\t\t\t\t      Oktober %d\n\n",tahun);
		} else if(bulan==11){
			printf("\t\t\t\t\t      November %d\n\n",tahun);
		} else if(bulan==12){
			printf("\t\t\t\t\t      Desember %d\n\n",tahun);
		}
			for(i=1;i<=34;i++){
			printf("___");
		}
		puts("");
		
		printf("No\tJenis Buku\tNama Buku\t\tHarga Buku Satuan\tKuantitas\tTotal\n");
		for(i=1;i<=34;i++){
			printf("___");
		}
		puts("");
		printf("1.\tEnsiklopedia\tMesir Kuno\t\tRp150000\t\t%d\t\tRp%d\n",ensi,ensi*150000);
		printf("2.\tBiografi\tSoekarno\t\tRp140000\t\t%d\t\tRp%d\n",bio,bio*140000);
		printf("3.\tNovel\t\tDear Nathan\t\tRp 90000\t\t%d\t\tRp%d\n",nov,nov*90000);
		printf("4.\tKamus\t\tInggris-Indonesia\tRp 50000\t\t%d\t\tRp%d\n",kam,kam*50000);
		printf("5.\tKomik\t\tDoraemon\t\tRp 30000\t\t%d\t\tRp%d\n",kom,kom*30000);
		for(i=1;i<=34;i++){
			printf("___");
		}
		puts("");
		printf("TOTAL PENDAPATAN\t\t\t\t\t\t\t\t\tRp%d\n",ensi*150000+bio*140000+nov*90000+kam*50000+kom*30000);
		for(i=1;i<=34;i++){
			printf("___");
		}
		puts("");
		fclose(fileout);
		} else printf("MOHON MAAF, INPUTAN YANG DIBERIKAN SALAH."); //apabila bulan yang diinputkan tidak sesuai maka laporan bulanan tidak akan dijalankan.
	
		
	}
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
}




//FUNCTION PENCETAKAN LAPORAN PENJUALAN BUKU TERURUT BERDASARKAN PRODUK YANG TERJUAL PALING BANYAK {JUlIA}
struct data{
	char *nama; //menyimpan nama jenis buku.
	int nilai; //banyak buku yang dibeli.
};

void swap(struct data *xp, struct data *yp)  {  //jadi nanti akan melakukan pertukaran.
    struct data temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}
 
void bubbleSort3(struct data arr[], int n)  { 
    int i, j;  
    for (i = 0; i < n-1; i++)       
    for (j = 0; j < n-i-1; j++)  
        if (arr[j].nilai < arr[j+1].nilai) //apabila pada nilai pada array j < daripada array j+1, maka akan melakukan sorting. apabila tidak memenuhi maka akan tetap.
            swap(&arr[j], &arr[j+1]);  
}

void Laporan_penjualan_PB(int pilihan, int j){
	if(pilihan==3){ //KETIKA PENGGUNA PROGRAM MEMILIH PILIHAN 3 MAKA, AKAN MASUK KE PROGRAM PENCETAKAN LAPORAN PENJUALAN BUKU TERURUT BERDASARKAN PRODUK YANG TERJUAL PALING BANYAK
		data_buku buku[maks]; //PEMANGGILAN STRUCT PADA TYPEDEF STRUCT data_buku.
		int i;
		int sum_ensi=0, sum_nov=0, sum_bio=0, sum_kam=0, sum_kom=0;
		FILE *fp;
		fp= fopen("sales.txt","r"); //buat membuka file yang mana tempat data disimpan
		fread(buku, sizeof(buku),1,fp); //buat ngeread data.
		
		//Untuk menambah banyak produk yang terjual.
		for(i=1;i<=j;i++){
			sum_ensi+= buku[i].ensiklopedia;
			sum_nov+= buku[i].novel;
			sum_bio+= buku[i].biografi;
			sum_kam+= buku[i].kamus;
			sum_kom+= buku[i].komik;
		}
		
		
		struct data A[5];//pemanggilan struct data.
		//memasukan data data yang akan disimpan pada struct data.
	A[0].nama = "Biografi"; 
	A[0].nilai=sum_bio;
	A[1].nama ="Ensiklopedia"; 
	A[1].nilai=sum_ensi;
	A[2].nama ="Kamus"; 
	A[2].nilai=sum_kam;
	A[3].nama ="Komik"; 
	A[3].nilai=sum_kom;
	A[4].nama ="Novel"; 
	A[4].nilai=sum_nov;
	
	bubbleSort3(A,5); //melakukan sorting
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),12);
		printf("\t\t--Laporan Penjualan Dengan Jumlah Produk Yang Terjual--\n\n");
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
		printf("\t\t   ");
		for(i=1;i<=10;i++){
			printf("_____");
		}
		puts("");
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),14);
		printf("\t\t   ");
		printf(" No\tJenis Buku\tJumlah Produk Terjual\n");
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
		printf("\t\t   ");
		for(i=1;i<=10;i++){
			printf("_____");
		}
		puts("");
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),14);
		
		for(i=0;i<5;i++){ //pengeluaran output terurut berdasarkan produk yang paling laku.
			printf("\t\t   ");
			if(A[i].nama!="Ensiklopedia"&&A[i].nama!="Biografi"){
				printf(" %d\t%s\t\t%d item\n",i+1,A[i].nama,A[i].nilai);
			}else
		printf(" %d\t%s\t%d item\n",i+1,A[i].nama,A[i].nilai);	
		}
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
		printf("\t\t   ");
		for(i=1;i<=10;i++){
			printf("_____");
		}
		puts("");
		puts("");
	}
	
}


int main(){
	printf("\t\t\t\t  APLIKASI PROGRAM THE GIFTED STORE\n");
	printf("\t\t  ===================================================================\n\n\n");
	int pilihan,j;
	printf("Berapa Banyak data yang ingin diakses: ");
	scanf("%d",&j);
	printf("PILIHAN IKON APLIKASI THE GIFTED STORE:\n");
	printf("1. Pendataan penjualan buku.\n");
	printf("2. Pencetakan laporan penjualan buku terurut berdasarkan tanggal transaksi.\n");
	printf("3. Pencetakan laporan penjualan buku terurut berdasarkan produk yang terjual paling banyak\n");
	printf("Masukan ikon yang ingin anda pilih (Nomor): "); scanf("%d",&pilihan); getchar();
	puts("");puts("");
	data_penjualan(pilihan,j);
	Laporan_penjualan_TT(pilihan,j);
	Laporan_penjualan_PB(pilihan,j);
	return 0;
}
