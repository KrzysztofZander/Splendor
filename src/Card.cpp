#include "Card.h"




Card::Card(int poi,int val,int whi,int re,int bla,int gre,int blu)
{
    white=whi;
    red=re;
    black=bla;
    green=gre;
    blue=blu;
    points=poi;
    value=val;
}

Card::~Card()
{
    //dtor
}

