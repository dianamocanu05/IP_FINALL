#include <iostream>
#include <graphics.h>
#include <winbgim.h>
#include <math.h>
#include "Piesa.h"
#include "Tabla.h"
#define screenWidth 1000
#define screenHeight 800
using namespace std;
bool amAles,amAles2,aFostPlasata;
int playerCurent, ok, x, y, marimePiesaAleasa,linie,coloana;
int matrice[3][3];
int culoare[2]= {4,1};

bool PotPunePiesa(int marime, int coloana, int linie)
{
    if(matrice[coloana][linie]>0)
        return (marime>matrice[coloana][linie]);
    else
        return(marime>(-1)*matrice[coloana][linie]);

}


bool win()
{
    for(size_t i=0; i<3; i++)
    {
        unsigned int s=0;
        for(size_t j=0; j<3; j++)
        {
            s+=matrice[i][j];
        }
        if(s==3)
            return true;
    }
    return false;
}

void PlaseazaPiesa(int marime, int x, int y, int culoare)
{
    setfillstyle(SOLID_FILL,culoare);
    int undex=tabla[x][y].x+(130-marime)/2;
    int undey=tabla[x][y].y+(130-marime)/2;
    rectangle(undex,undey,undex+marime,undey+marime);
    floodfill(undex+1,undey+1,15);
}

void StergePiesa(int marime,int coloana, int linie)
{
    setfillstyle(SOLID_FILL,BLACK);
    int undex=tabla[x][y].x+(130-marime)/2;
    int undey=tabla[x][y].y+(130-marime)/2;
    rectangle(undex,undey,undex+marime,undey+marime);
    floodfill(undex+1, undey+1, 15);

}


int main()
{
    //Pregatirea ecranului pentru joc
    initwindow(screenWidth,screenHeight);
    InitPiese();
    for(size_t i=0; i<3; i++)
        DeseneazaPiesa(player1[i]);
    for(size_t i=0; i<3; i++)
        DeseneazaPiesa(player2[i]);
    InitTabla();
    DeseneazaTabla(tabla);
    for(int i=0; i<3;i++)
        for(int j=0;j<3; j++)
    {
        matrice[i][j]=0;
    }

    //Joc
    playerCurent=0;
    while(1)
    {
        if(playerCurent==0)
            outtextxy(100,100,"player1");
        else
            outtextxy(100,100,"player2");
        amAles=false;
        amAles2=false;
        marimePiesaAleasa=0;
        linie=-1;
        coloana=-1;
        if(ok==0)
            {
            while(!ismouseclick(WM_LBUTTONDOWN)){}
            getmouseclick(WM_LBUTTONDOWN,x,y);
            marimePiesaAleasa=AlegePiesa(x,y,playerCurent);
            ok++;
            if(marimePiesaAleasa)
                amAles=true;
            //cout<<"1"<<'\n';
            }
        if(ok==1 && amAles)
        {
            while(!ismouseclick(WM_LBUTTONDOWN)){}
            getmouseclick(WM_LBUTTONDOWN,x,y);
            linie=UndePeTablaX(x);
            coloana=UndePeTablaY(y);
            ok++;
            if(linie>=0 && coloana>=0)
                amAles2=true;
           // cout<<linie<<' '<<coloana<<'\n';
        }
        if(ok==2 && amAles && amAles2)
        {
            if(PotPunePiesa(marimePiesaAleasa,coloana,linie))
                {
                if(matrice[coloana][linie]!=0)
                        PlaseazaPiesa(marimePiesaAleasa,coloana,linie,1);
                PlaseazaPiesa(marimePiesaAleasa,coloana,linie,culoare[playerCurent]);
                if(playerCurent==0)
                    matrice[coloana][linie]=(-1)*marimePiesaAleasa;
                else
                    matrice[coloana][linie]=marimePiesaAleasa;
                aFostPlasata=true;
                }

            //cout<<"3";
        }
        if(aFostPlasata)
        {
        playerCurent=(playerCurent+1)%2;
        ok=0;
        aFostPlasata=false;
        }
    }





    getch();

}
