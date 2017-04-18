//MUHAMMED SARA   -   Programlama Lab2 1.ödev
#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include <string.h>
#include <allegro.h>
#define SONSUZ 99999
    BITMAP *Resim;
    int MAX=81;
    void dosya();
    void matrix();
    void  dijkstra();
    void cizim();

   FILE *dosya1,*dosya2,*dosya3;

  char sehir1[81][20];
  char sehir2[81][20];
  char mesafe[81][20];
  int mesafe_int[81];
  char satir[200][60];
  char sehir[81][20];
  char sehirk[81][20];
  char x_noktasi[81][20];
  char y_noktasi[81][20];
  int x_noktasi_int[81];
  int y_noktasi_int[81];
  char sehir_kod[81][20];
  int sehir_kod_int[81];
  int matris[81][81];
  int gecilendugum[81];
  int y_sayisi=0,x_sayisi=0,sonuc=0,sayac=0;
  int i=0, a=0, k=0, j=0, u=0, g=0,s=0;
  int sehir_kordinat=0;
  int x_koor,y_koor,x_koor2,y_koor2;
  char d1[20]="sehir mesafe.txt",d2[20]="sehir kod.txt";

int main()
{

    setlocale(LC_ALL, "Turkish");


   printf("\n\tSehir Mesafe Dosyanizin Adini Giriniz ==> ");
    gets(d1);

    printf("\n\tSehir Kod Dosyanizin Adini Giriniz ==> ");
    gets(d2);

system("cls");
int n=5,n2=7,n3=30;
      dosya();
      matrix();
      gidir:

    printf("\n\nBir sehirden baska bir sehire en kisa yolu(gecilen sehirleri) ve toplam mesafeyi bulmak icin --> 1\n\n");
     printf("Iki sehir arasindaki en kisa yolun(gecilen sehirleri) ve mesafeyi bulmak icin--> 2  Giriniz...\n\n");
        printf("Girdi ==> ");
      scanf("%d",&g);
     if(g==1){
            printf("\n\nBaslangic Sehrin Kodu ==> ");
            scanf("%d",&u);
            u--;
            printf("Girilen Sehirin Ismi    ==> %s \n",sehir[u]);

            dijkstra(matris,u,1);
     }
     else if(g==2){
            printf("\n\Baslangic Sehrin Kodu ==> ");
            scanf("%d",&u);
            u--;
            printf("Girilen Sehirin Ismi    ==> %s \n",sehir[u]);

            printf("\n\Bitis Sehrin Kodu    ==> ");
            scanf("%d",&s);
            s--;
            printf("Girilen Sehirin Ismi ==> %s \n",sehir[s]);

            dijkstra(matris,u,s);
     }
     else{
        printf("Hatali Giris...");
     }


int f=0;
    printf("\n\n",sehir_kordinat);
     int h=0;
    printf("\n\n------------------Haritada gormek icin 1 Basa donmek icin 2 giriniz...------------------>>>  ");

    scanf("%d",&h);
    if(h==1)
         cizim();
    else if(h==2)
       goto gidir;
    else
        printf("Hatali giris yaptiniz...");

   for(i=sayac-1;i>=0;i--){


        for(k=0;k<sehir_kordinat;k++){

         sonuc=strcmp(sehir[gecilendugum[i]],sehirk[k]);
         if(sonuc==0){

                    x_koor=x_noktasi_int[k];
                    y_koor=y_noktasi_int[k];

            }

        }
        f++;
   n=n+(2*i);
   n2=n2+(2*i);
   n3=n3+(2*i);


        if(f>1)
        line(screen,x_koor,y_koor,x_koor2,y_koor2,makecol(n,n2,n3));

      x_koor2=x_koor;
      y_koor2=y_koor;


   }

int m;
scanf("%d",&m);
}
//Dijkstra algoritmasý veri yapýlarý dersi gecen senenin örnek sorularýndan yardým aldým http://embedded.kocaeli.edu.tr/veriyapilari-ve-algoritmalar/   ve
//internette http://www.thecrazyprogrammer.com/2014/03/dijkstra-algorithm-for-finding-shortest-path-of-a-graph.html adresinden
//uygun bölümlerde yardým aldým
void dijkstra(int gelen[MAX][MAX],int baslangic_dugum, int bitis_dugum)
{
   int il_sayisi=y_sayisi;

     int maliyet[MAX][MAX],mesafesi[MAX],deger[MAX];

     int ziyaret[MAX],say,enaz_mesafe,sonraki_dugum,i,j;


    for(i=0;i<il_sayisi;i++)
        for(j=0;j<il_sayisi;j++)
            if(gelen[i][j]==0)
                maliyet[i][j]=SONSUZ;
            else
                maliyet[i][j]=gelen[i][j];
  i=0;
    while(i<il_sayisi){

         mesafesi[i]=maliyet[baslangic_dugum][i];
        deger[i]=baslangic_dugum;
        ziyaret[i]=0 ;
        i++;
    }


    mesafesi[baslangic_dugum]=0;
    ziyaret[baslangic_dugum]=1;
    say=1;

    while(say<il_sayisi-1)
    {
        enaz_mesafe=SONSUZ;

        for(i=0;i<il_sayisi;i++)
            if(mesafesi[i]<enaz_mesafe&&!ziyaret[i])
            {

                enaz_mesafe=mesafesi[i];
                sonraki_dugum=i;
            }

            ziyaret[sonraki_dugum]=1;
            for(i=0;i<il_sayisi;i++)
                if(!ziyaret[i])
                    if(enaz_mesafe+maliyet[sonraki_dugum][i]<mesafesi[i])
                    {
                        mesafesi[i]=enaz_mesafe+maliyet[sonraki_dugum][i];
                        deger[i]=sonraki_dugum;
                    }
        say++;
    }

    if(g==1){
            for(i=0;i<il_sayisi;i++)
        if(i!=baslangic_dugum)
        {   j=baslangic_dugum;
            printf("\n\n%s <-> %s arasindaki en kisa mesafe  = %d",sehir[j],sehir[i],mesafesi[i]);
            printf("\n%s <-> %s arasindaki en kisa yol =  ");


            j=i;
    gecilendugum[sayac]=j;
                sayac++;
                char dizi[81][20]={"",""};
                int hes=1;
            do
            {

                j=deger[j];
                strcpy(dizi[hes],sehir[j]);
                hes++;
               gecilendugum[sayac]=j;
                sayac++;
             }while(j!=baslangic_dugum);
             int z;
            for(z=hes-1;z>0;z--)
                 printf(" %s -> ",dizi[z]);

 printf(" %s ",sehir[i]);
    }

    }
    if(g==2){

      sayac=0;

        for(i=0;i<il_sayisi;i++)
        if(i!=baslangic_dugum)
        {
            if(i==bitis_dugum){
                     j=baslangic_dugum;
                printf("\n\n%s <-> %s arasindaki en kisa mesafe = %d",sehir[j],sehir[i],mesafesi[i]);
             printf("\n%s <-> %s arasindaki en kisa yol = ");

            j=i;
             gecilendugum[sayac]=bitis_dugum;
             sayac++;
             char dizi[81][20]={"",""};
                int hes=1;
            do
            {
                j=deger[j];
                 strcpy(dizi[hes],sehir[j]);
                hes++;
                gecilendugum[sayac]=j;
                sayac++;
            }while(j!=baslangic_dugum);

int z;
            for(z=hes-1;z>0;z--)
                 printf(" %s -> ",dizi[z]);

 printf(" %s ",sehir[i]);
            }

    }

    }

}
 void cizim(){

  allegro_init();
        install_keyboard();
        set_gfx_mode( GFX_AUTODETECT_WINDOWED,1000,495,0,0);
        Resim = load_bitmap( "image.bmp", NULL);
        draw_sprite( screen, Resim, 0, 0);
        release_screen();

 }

END_OF_MAIN();

void matrix(){
     int i=0,j=0;

        for(i=0;i<y_sayisi;i++)
            for(j=0;j<y_sayisi;j++)
                    matris[i][j]=0;

    for(i=0; i<x_sayisi;i++){

            int t=0;
           for(t=0;t<y_sayisi;t++) {
            if(strcmp(sehir1[i],sehir[t])==0){
                break;
        }
           }

           int z=0;
           for(z=0;z<y_sayisi;z++) {
            if(strcmp(sehir2[i],sehir[z])==0){
            break;
        }
           }

        matris[t][z]=mesafe_int[i];
        matris[z][t]=mesafe_int[i];

        }
}

void dosya()
{

     if((dosya1=fopen(d1,"r"))!=NULL)
   {

   while(!feof(dosya1))
       {

           fscanf(dosya1,"%s",satir[i]);
          // printf("%s\n",satir[i]);
           strcpy(sehir1[i],strtok(satir[i],"-"));
          // printf("%s ",sehir1[i]);
           strcpy(sehir2[i],strtok(NULL,"-"));
          // printf("%s ",sehir2[i]);
           strcpy(mesafe[i],strtok(NULL,"-"));
          //printf("%s\n",mesafe[i]);
           //mesafe[i]=atoi(mesafesi[i]);



           i++;

       }
x_sayisi=i;
        int d=0;
      for(d=0;d<i;d++){
            mesafe_int[d]=atoi(mesafe[d]);

    }
   }
   else{
    printf("Sehir Mesafe Dosyasi bulunamadi...");
   }
printf("\n");


   if((dosya2=fopen(d2,"r"))!=NULL)
   {

   while(!feof(dosya2))
       {

           fscanf(dosya2,"%s",satir[a]);
         //  printf("%s\n",satir[i]);
           strcpy(sehir[a],strtok(satir[a],"-"));
          // printf("%s ",sehir[a]);
           strcpy(sehir_kod[a],strtok(NULL,"-"));
          //  printf("%s\n",sehir_kod[a]);
           a++;

       }

       y_sayisi=a;
        int d=0;
      for(d=0;d<a;d++){
        sehir_kod_int[d]=atoi(sehir_kod[d]);

    }
      printf("KOD  SEHIR\n");
       int o=0;
       for(o=0; o<a;o++){
            if(o%5==0)
            printf("\n");
        printf("%d -> %s\t",sehir_kod_int[o],sehir[o]);

       }

   }
   else{
    printf("Sehir Kod Dosyasi bulunamadi...");
   }

      if((dosya3=fopen("koordinat.txt","r"))!=NULL)
   {
a=0;
   while(!feof(dosya3))
       {

           fscanf(dosya3,"%s",satir[a]);

           strcpy(sehirk[a],strtok(satir[a],"-"));
          // printf("%s\n",sehirk[a]);
           strcpy(x_noktasi[a],strtok(NULL,"-"));
           //printf("%s\n",x_noktasi[a]);
           strcpy(y_noktasi[a],strtok(NULL,"-"));
          // printf("%s\n",y_noktasi[a]);
           a++;

       }

 sehir_kordinat=a;
        int d=0;
      for(d=0;d<a;d++){
        x_noktasi_int[d]=atoi(x_noktasi[d]);
        y_noktasi_int[d]=atoi(y_noktasi[d]);
    }


   }
   else{
    printf("Koordinat Dosyasi bulunamadi...");
   }
}
