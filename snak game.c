#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <unistd.h>

int hight=20,weight=20,row,col;
int x,y,fruitx,fruity,gameover,score,flag,counttail=0;
int tailx[100],taily[100],provx,provy,prov2x,prov2y,f,l;
void loading()
{
    system("cls");
    int a,k,c;
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");

    printf("  Loading");
    for(c=1; c<7; c++)
    {
        for(k=1; k<1000000000; k++)

            a=k;
        printf(".");

    }
    usleep(300000);
}
void myself()
{
       int u;
          system("cls");
printf("\n\n\n    This Game Was Developed \n        By \n    Rifat Hasan Priyo");

usleep(2000000);


}
void presskey()
{
      system("cls");
      printf("\n\n\n    Press 'ENTER' To Start");
      getch();


}
void waiting()
{
        system("cls");
    int q,w,e;

    printf("\n\n\n    Starting");
    for(q=1; q<7; q++)
    {
        for(w=1; w<1000000000; w++)

            e=w;
        printf(".");

    }
    usleep(300000);

}
void setup()
{
    gameover=0;
    x=hight/2;
    y=weight/2;
label1:
    fruitx=rand()%20;
    if(fruitx==0)
    {
        goto label1;
    }
label2:
    fruity=rand()%20;
    if(fruity==0)
    {
        goto label2;
    }
    score=0;
}


void draw()
{
    system("cls");
    for(row=0; row<=hight; row++)
    {
        for(col=0; col<=weight; col++)
        {
            if(row==0 || row==hight || col==0 || col==weight)
            {
                printf("#");
            }
            else
            {
                if(row==x && col==y)
                {
                    printf("0");
                }
                else if(row==fruitx && col==fruity)
                {
                    printf("*");
                }
                else
                {
                    int ch=0;
                    for(l=0; l<counttail; l++)
                    {
                        if(row==tailx[l]&& col==taily[l])
                        {
                            printf("o");
                            ch=1;
                            break;

                        }

                    }
                    if(!ch)
                    {
                        printf(" ");

                    }
                }
            }
        }
        printf("\n");

    }
    printf("\nScore= %d",score);
}
void input()
{
    if(kbhit())
    {
        switch(getch())
        {
        case 'a':
            flag=1;
            break;
        case 'd':
            flag=2;
            break;
        case 'w':
            flag=3;
            break;
        case 's':
            flag=4;
            break;
        case 'x':
            flag=5;
            break;
        }
    }

}
void makelogic()
{
    tailx[0]=x;
    taily[0]=y;
    provx=tailx[0];
    provy=taily[0];


    for(row=1; row<counttail; row++)
    {
        prov2x=tailx[row];
        prov2y=taily[row];
        tailx[row]=provx;
        taily[row]=provy;
        provx=prov2x;
        provy=prov2y;
    }

    switch(flag)
    {
    case 1:
        y--;
        break;
    case 2:
        y++;
        break;
    case 3:
        x--;
        break;
    case 4:
        x++;
        break;
    default:
        break;
    }
    if(x<0 ||x>weight||y<0 ||y>hight)
    {
        gameover=1;
    }
    for(row=0; row<counttail; row++)
    {
        if(x==tailx[row]&&y==taily[row])
            gameover=1;

    }
    if(x==fruitx && y==fruity)
    {
label3:
        fruitx=rand()%20;
        if(fruitx==0)
        {
            goto label3;
        }
label4:
        fruity=rand()%20;
        if(fruity==0)
        {
            goto label4;
        }
        score=score+10;
        counttail++;
    }

}

int main()
{
    int m,n;
    char y;
    loading();
    myself();
    presskey();
    waiting();
    do
    {

        setup();
        while(!gameover)
        {
            draw();
            input();
            makelogic();
            /* for(m=0;m<10000;m++)
             {
                    for(n=0;n<10000;n++)
                    {

                    }
             }*/
            usleep(107000);

        }
        system("cls");
        for(row=0; row<50; row++)
        {
            if(row==10)
            {

                printf("\n   You Die\n\n\nPress Y Try Again= ");
                scanf(" %c",&y);
            }

            else
            {
                printf("\n");
            }
        }


    }
    while(y=='y' ||y=='Y');

    return 0;
}
