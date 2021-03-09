/*
Nama/NIM : Ridha Fatony Iswahyudi/16320099
Fakultas : FITB-G
Tugas    : Membuat sebuah program kalkulator yang mampu menghitung penjumlahan, pengurangan,
perkalian, pembagian, perpangkatan (pangkat>1), dan integral tentu menggunakan pendekatan
riemann metode trapesium.
*/

#include <iostream>
using namespace std;


float penjumlahan (float a, float b ) //Fungsi Penjumlahan
{
    int r;
    r=a+b;
    return r;
}

float pengurangan (float a, float b ) //Fungsi Pengurangan
{
    int r;
    r=a-b;
    return r;
}

float perkalian (float a, float b ) //Fungsi Perkalian
{
    int r;
    r=a*b;
    return r;
}
float pembagian (float a, float b ) //Fungsi Pembagian
{
    int r;
    r=a/b;
    return r;
}

float pangkat (float a, float b ) //Fungsi Perpangkat >1
{
    int r,z;
    for (int i=0;i<b; i++)
    {
        if (i>0)
        {
            r=z;
            r*=a;
            z=r;
        }
        else
        {
            r=a;
            z=r;
        }
    }
    return z;
}
