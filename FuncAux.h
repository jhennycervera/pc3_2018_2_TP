/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FuncAux.h
 * Author: Admin
 *
 * Created on 9 de mayo de 2020, 20:02
 */

#ifndef FUNCAUX_H
#define FUNCAUX_H

void LeerArticulos(int *,int * ,double *,double*,
                    int*);
void OrdenarYReescribirArt(int *,int * ,double *,double*,
                    int);
void cambiarI(int *, int  ,int );
void  cambiarD(double *,int  ,int );
int BuscarProd(int ,int *,int );
void ProcesarCompras(int* , int *, int* ,int* ,int* ,int* ,int* ,
                 double *, int *, int*,
            int* ,double *,double *,int  );
#endif /* FUNCAUX_H */

