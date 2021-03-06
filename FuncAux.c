/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include "FuncAux.h"

void LeerArticulos(int *codProdArt,int * stock,double *pUnid,double*pDecen,
                    int*contArt){
    
    FILE*archArt;
    archArt=fopen("articulos.txt", "r");
    if(archArt==NULL){
        printf("No se puede abrir el archivo articulos.txt\n");
        exit(1);
    }
    (*contArt)=0;
    int codProd, stockarch;
    double  pu, pd;
    while(1){
        fscanf(archArt,"%d %lf %lf %d",&codProd, &pu, &pd, &stockarch);
         if(feof(archArt)) break;
        codProdArt[*contArt]=codProd;
        pUnid[*contArt]=pu;
        pDecen[*contArt]=pd;
        stock[*contArt]=stockarch;
        
      //  printf("%d %lf %lf %d\n", codProdArt[*contArt], pUnid[*contArt],pDecen[*contArt],stock[*contArt]);
        (*contArt)++;
       
    }
    
    fclose(archArt);
    
}

  void OrdenarYReescribirArt(int *codProdArt,int * stock,double *pUnid,double*pDecen,
                    int contArt){
      
      
    FILE*archArt;
    archArt=fopen("articulos.txt", "w");
    if(archArt==NULL){
        printf("No se puede abrir el archivo articulos.txt\n");
        exit(1);
    }
    
    for(int i=0;  i<contArt-1; i++) {
        for(int j=i+1 ; j<contArt; j++){
            if(codProdArt[i]>codProdArt[j]){
                cambiarI(codProdArt,i , j);
                cambiarI(stock, i , j);
                cambiarD(pUnid, i , j);
                cambiarD(pDecen, i , j);
            }
        }
    }
    
   
    for(int i=0; i<contArt; i++){
        fprintf(archArt, "%d %lf %lf %d\n", codProdArt[i], pUnid[i],
                pDecen[i],stock[i]);
/*
        printf("%d %lf %lf %d\n", codProdArt[i], pUnid[i],
                pDecen[i],stock[i]);
*/
    }
    
    
    fclose(archArt);
  }
  
  
 void cambiarI(int *arr, int i ,int j){
     
     int aux;
     aux= arr[i];
     arr[i]=arr[j];
     arr[j]=aux;
     
 }
void  cambiarD(double *arr,int i ,int j){
     double aux;
     aux= arr[i];
     arr[i]=arr[j];
     arr[j]=aux;
}


void ProcesarCompras(int* dd, int *mm, int* aa,int* hh,int* min,int* seg,int* dni,
                 double *totalComp, int *contCompr, int*codProdArt,
            int* stock,double *pUnid,double *pDecen,int contArt ){
    
     FILE*archComp;
    archComp=fopen("compras.txt", "r");
    if(archComp==NULL){
        printf("No se puede abrir el archivo compras.txt\n");
        exit(1);
    }
    
    (*contCompr)=0;
    int dia, mes, anho, hora, minu, segu, dniarch, codPr, cant;
    int pos;
    double costoComp;
    while(1){
        fscanf(archComp, "%d/%d/%d %d:%d:%d %d",&dia, &mes, &anho, &hora, &minu,
                            &segu, &dniarch );
        if(feof(archComp)) break;
        int cantArti;
        dd[*contCompr]=dia;
        mm[*contCompr]=mes;
        aa[*contCompr]=anho;
        hh[*contCompr]= hora;
        min[*contCompr]=minu;
        seg[*contCompr]=segu;
        dni[*contCompr]=dniarch;
        while(1){
            fscanf(archComp, "%d %d",&codPr,&cant);
            if(fgetc(archComp)=='\n') break;
            pos=BuscarProd(codPr,codProdArt,contArt);
            if(pos!=-1){
                if(cant>stock[pos]){
                    cantArti=stock[pos];
                    stock[pos]=0;
                }
                else{
                    cantArti=cant;
                    stock[pos]-=cant;
                }
                if(cantArti%12==0) costoComp=cantArti*pDecen[pos];  
                else costoComp=cantArti*pUnid[pos];
            } 
            totalComp[*contCompr]+=costoComp;
        }
        
        printf("%d/%d/%d %d:%d:%d %d %lf\n",dd[*contCompr],mm[*contCompr],
        aa[*contCompr],hh[*contCompr],min[*contCompr],seg[*contCompr],
        dni[*contCompr], totalComp[*contCompr]);
        (*contCompr)++;
    }
    fclose(archComp);
}

int BuscarProd(int codPr,int *codProdArt,int contArt){
   for(int i=0; i<contArt; i++){
       if(codPr==codProdArt[i]) return i;
   }
   return -1;
}