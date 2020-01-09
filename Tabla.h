#pragma once
#include <graphics.h>
#include <winbgim.h>
#include "Piesa.h"

struct celula{
    unsigned int x,y;
    unsigned int latura;
}tabla[3][3];

void InitTabla()
{
    for(size_t i=0; i<3; i++)
        for(size_t j=0; j<3; j++)
            {
             tabla[i][j].latura=130;
             tabla[i][j].x=270+ j*130;
             tabla[i][j].y=175+ i*130;
            }
}

void DeseneazaCelula(celula c)
{
    rectangle(c.x, c.y, c.x+c.latura, c.y+c.latura);
}

void DeseneazaTabla(celula M[3][3])
{
    for(size_t i=0; i<3; i++)
        for(size_t j=0; j<3; j++)
           DeseneazaCelula(M[i][j]);
}

int UndePeTablaX(int xx)  //pe ce coloana
{
    /*if(xx>=400 && xx<=780)
    {for(int i=0; i<3; i++)
        if(xx>=tabla[0][i].x && xx<=tabla[0][i].x+tabla[0][i].latura)
            return i;
    }*/

    if(xx>=270 && xx<400)
        return 0;
    if(xx>=400 && xx<530)
        return 1;
    if(xx>=530 && xx<=660)
        return 2;
}

int UndePeTablaY(int yy)  //pe ce linie
{
    /*if(yy>=175 && yy<=435)
   {
    for(int i=0; i<3; i++)
        if(yy>=tabla[i][0].y && yy<=tabla[i][0].y+tabla[i][0].latura)
            return i;
   }*/

   if(yy>=175 && yy<305)
        return 0;
    if(yy>=305 && yy<435)
        return 1;
    if(yy>=435 && yy<=565)
        return 2;


}
