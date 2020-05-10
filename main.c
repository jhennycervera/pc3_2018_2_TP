/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Jhenny Cervera Vargas(20182841)
 *
 * Created on 9 de mayo de 2020, 20:02
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncAux.h"
/*
 * 
 */
int main(int argc, char** argv) {

    
    int codProdArt[250],stock[250], contArt;
    double pUnid[250], pDecen[250];
    
    int dd[300], mm[300], aa[300], hh[300], min[300], seg[300],dni[300];
    int contCompr;
    double totalComp[300]={0};
    
    LeerArticulos(codProdArt,stock,pUnid,pDecen,&contArt);
    OrdenarYReescribirArt(codProdArt,stock,pUnid,pDecen,contArt);
    ProcesarCompras(dd, mm, aa, hh, min, seg, dni,totalComp,&contCompr,
           codProdArt,stock,pUnid,pDecen,contArt );
    return (EXIT_SUCCESS);
}

