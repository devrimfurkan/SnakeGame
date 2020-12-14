#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>




struct yilan{
int x,y;

};
int len=4;
  int score=0;

  int col=20,row=10;

  char map[20][40];

  int tamammi_devammi(struct yilan snake[]){

      int i,k1=0,k2=0;

      if(snake[0].x==0||snake[0].x==19||snake[0].y==0||snake[0].y==39){

         k1=1;

      }

      for(i=1;i<len;i++){

         if(snake[0].x==snake[i].x&&snake[0].y==snake[i].y){

             k2=1;

             break;

         }

      }

      if(k1==1||k2==1) return 1;

      else return 0;

  }



  void yemleme(){

       srand(time(NULL));

       row=rand()%18+1;

       col=rand()%38+1;

  }

  void yem(char dizi[20][40],struct yilan snake[]){

       if(snake[len-1].x==row&&snake[len-1].y==col){

                     char cvp1;

                     system("CLS");

                    printf("     Dunyanini en kalabalik ulkesi hangisidr ?  \n\n");

                    printf("               a)Japonya      b)Cin     c)Somali     d)Hindistan\n\n");

                    printf("Cevap : "); scanf("%c",&cvp1);

                    if(cvp1=='b') {

                     snake[len].x=row;

                     snake[len].y=col;

                     len++;

                     score=score+10;

                     yemleme();

                     printf("\a");

                    }

       }

  }

  void duvar(char dizi[20][40]){

       int i,j;

       for(i=0;i<20;i++){

          if(i==0||i==19){

              for(j=0;j<40;j++){

                  dizi[i][j]='=';

              }

          }

          else{

               dizi[i][0]='|';

               for(j=1;j<39;j++){

                   dizi[i][j]=' ';

               }

               dizi[i][39]='|';

          }



       }

       map[row][col]='x';

  }

  void ciz(char dizi[20][40]){

       system("CLS");

       printf("Score: %d\n",score);

       int i,j;

       for(i=0;i<20;i++){

          for(j=0;j<40;j++){

              printf("%c",dizi[i][j]);

          }

          printf("\n");

       }



  }

  void baslangic(struct yilan yil[]){

       yil[0].x=1;

       yil[0].y=4;

       yil[1].x=1;

       yil[1].y=3;

       yil[2].x=1;

       yil[2].y=2;

       yil[3].x=1;

       yil[3].y=1;

  }

  void yilan (char dizi[20][40],struct yilan yil[]){

       yem(map,yil);

       int i;

       for(i=0;i<len;i++){

           dizi[yil[i].x][yil[i].y]='*';

       }

  }

  void sag(struct yilan snake[],int uzunluk){

       int i;

       for(i=uzunluk-1;i>0;i--){

               snake[i].x=snake[i-1].x;

               snake[i].y=snake[i-1].y;

               }

               snake[0].y++;

  }

  void sol(struct yilan snake[],int uzunluk){

       int i;

       for(i=uzunluk-1;i>0;i--){

               snake[i].x=snake[i-1].x;

               snake[i].y=snake[i-1].y;

               }

               snake[0].y--;

  }

  void yukari(struct yilan snake[],int uzunluk){

       int i;

       for(i=uzunluk-1;i>0;i--){

               snake[i].x=snake[i-1].x;

               snake[i].y=snake[i-1].y;

               }

               snake[0].x--;

  }

  void asagi(struct yilan snake[],int uzunluk){

       int i;

       for(i=uzunluk-1;i>0;i--){

               snake[i].x=snake[i-1].x;

               snake[i].y=snake[i-1].y;

       }

        snake[0].x++;



  }









  int main(){



      char right='d';

      char left='a';

      char up='w';

      char down='s';

      char yon;

      long i;

      int kontrol=0;

      struct yilan snake[100];



      duvar(map);

      baslangic(snake);

      yilan(map,snake);

      ciz(map);



       while(1){

          yon=getch();

          i=0;



          if(yon==right){

            while(i<100000){

             if(i%2000==0){

              if(tamammi_devammi(snake)){

                   ciz(map);

                   kontrol=1;

                   break;



               }



               sag(snake,len);

               duvar(map);

               yilan(map,snake);

               ciz(map);

             }

             i++;

             if(kbhit()) break;

            }



          }

          else if(yon==left){

            while(i<100000){

             if(i%2000==0){

              if(tamammi_devammi(snake)){

                   ciz(map);

                   kontrol=1;

                   break;

               }

               sol(snake,len);

               duvar(map);

               yilan(map,snake);

               ciz(map);

             }

             i++;

             if(kbhit()) break;

            }

          }

          else if(yon==up){

            while(i<100000){

             if(i%2000==0){

              if(tamammi_devammi(snake)){

                   ciz(map);

                   kontrol=1;

                   break;

               }

               yukari(snake,len);

               duvar(map);

               yilan(map,snake);

               ciz(map);

               }

             i++;

             if(kbhit()) break;

            }

          }

          else if(yon==down){

            while(i<100000){

             if(i%2000==0){

               if(tamammi_devammi(snake)){

                   kontrol=1;

                   ciz(map);

                   kontrol=1;

                   break;

               }

               asagi(snake,len);

               duvar(map);

               yilan(map,snake);

               ciz(map);

               }

             i++;

             if(kbhit()) break;

            }

          }

          if(kontrol==1) break;





      }







      getch();

  }
