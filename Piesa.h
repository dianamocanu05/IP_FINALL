#pragma once
#include <graphics.h>
#include <winbgim.h>

struct piesa{
unsigned int x,y;
unsigned int latura;
int culoare;}player1[3],player2[3];

bool Contine(int x, int y, int xx, int yy, int lat)
{
    return(x>=xx && x<=xx+lat && y>=yy && y<=yy+lat);
}

void InitPiese()
{
    player1[0].x=150;
    player1[0].y=200;
    player1[0].latura=60;
    player1[0].culoare=4;

    player1[1].x=150;
    player1[1].y=375;
    player1[1].latura=50;
    player1[1].culoare=4;

    player1[2].x=150;
    player1[2].y=500;
    player1[2].latura=40;
    player1[2].culoare=4;

    player2[0].x=720;
    player2[0].y=200;
    player2[0].latura=60;
    player2[0].culoare=1;

    player2[1].x=730;
    player2[1].y=375;
    player2[1].latura=50;
    player2[1].culoare=1;

    player2[2].x=740;
    player2[2].y=500;
    player2[2].latura=40;
    player2[2].culoare=1;

}

void DeseneazaPiesa(piesa p)
{
  setfillstyle(SOLID_FILL,p.culoare);
  rectangle(p.x,p.y,p.x+p.latura,p.y+p.latura);
  floodfill(p.x+1,p.y+1,15);
}

int AlegePiesa(int x, int y, int player)
{
    if(player==0)
    {
        for(size_t i=0; i<3; i++)
            if(Contine(x,y,player1[i].x,player1[i].y,player1[i].latura))
               return player1[i].latura;
    }
    else
    {
        for(size_t i=0; i<3; i++)
            if(Contine(x,y,player2[i].x,player2[i].y,player2[i].latura))
               return player2[i].latura;

    }
}



