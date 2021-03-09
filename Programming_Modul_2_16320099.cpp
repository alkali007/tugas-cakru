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

float pangkat (float a, float b ) //Fungsi Perpangkatan
{
    int r,z;
    if (b==0) //Pangkat 0
    {
        z=1;
    }
    else if (b<0)//Pangkat bilangan negatif
    {
       b*=-1;
    }

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



int main()
{
    cout<<"Pilih jenis kalkulator: "<<"\n";
    cout<<"Kalkulator biasa (+,-,*,/,**): A"<<"\n"<<"Kalkulator integral tentu: B"<<"\n";
    cout<<"Masukkan kode huruf: "<<"\n";
    string kodehuruf;
    cin>>kodehuruf;
    if (kodehuruf=="A")
    {
        float a,b,hasil;
        int n;
        string op;
        string nop[n];
        float simpan[n];
        cout<<"Masukkan jumlah bilangan: ";
        cin>>n;

        for (int i=0; i<n; i++){
            cout<<"Masukkan bilangan: ";
            cin>>a;
            simpan[i]=a;
            cout<<"\n";


            if (i>0)
            {
                if (nop[i-1]=="+")
                {
                    simpan[i] = penjumlahan(simpan[i-1], simpan[i]);
                    hasil = simpan[i];
                    cout<<"Hasil perhitungan: ";
                    cout<<hasil;
                    cout<<"\n";
                }
                if (nop[i-1]=="-")
                {
                    simpan[i] = pengurangan(simpan[i-1], simpan[i]);
                    hasil = simpan[i];
                    cout<<"Hasil perhitungan: ";
                    cout<<hasil;
                    cout<<"\n";
                }
                if (nop[i-1]=="*")
                {
                    simpan[i] = perkalian(simpan[i-1], simpan[i]);
                    hasil = simpan[i];
                    cout<<"Hasil perhitungan: ";
                    cout<<hasil;
                    cout<<"\n";
                }
                if (nop[i-1]=="/")
                {
                    simpan[i] = pembagian(simpan[i-1], simpan[i]);
                    hasil = simpan[i];
                    cout<<"Hasil perhitungan: ";
                    cout<<hasil;
                    cout<<"\n";
                }
                if (nop[i-1]=="**")
                {
                    if (simpan[i]<0)//Pangkat bilangan negatif
                    {
                        float baru;
                        baru =pangkat(simpan[i-1], simpan[i]);
                        simpan[i] = 1/baru;
                        hasil = simpan[i];
                        cout<<"Hasil perhitungan: ";
                        cout<<hasil;
                        cout<<"\n";
                    }
                    else//Pangkat bilangan positif atau 0
                    {
                        simpan[i] = pangkat(simpan[i-1], simpan[i]);
                        hasil = simpan[i];
                        cout<<"Hasil perhitungan: ";
                        cout<<hasil;
                        cout<<"\n";
                    }

                }            
            }
            if (i!=(n-1))
            {
                cout<<"Operator: +, -, *, /, dan **"<<".\n";
                cout<<"Penjelasan"<<"\n"<<"+: Penjumlahan"<<"\n"<<"-: Pengurangan"<<"\n"<<"*: Perkalian"<<"\n"<<"/: Pembagian"<<"\n"<<"**: Pangkat"<<"\n";
                cout<<"Untuk mengakhiri gunakan '='"<<".\n";
                cout<<"Pilih operator perhitungan: ";
                cin>>op;
                if (op=="=")//Mengakhiri kalkulator sebelum maksimum attempt angka
                {
                    hasil = simpan[i];
                    cout<<"Hasil perhitungan: ";
                    cout<<hasil;
                    cout<<"\n";
                    break;
                }
                nop[i]= op;
            }
        }
    }
    else
    {
        float bawah,atas,partisi,deltax,akhir;
        cout<<"\n"<<"Masukkan batas bawah dari integral: ";
        cin>>bawah;
        cout<<"\n"<<"Masukkan batas atas dari integral: ";
        cin>>atas;
        float newatas,newbawah;
        newatas=-1;
        newbawah=0;
        if (atas<bawah)
        {
            newatas=bawah;
            newbawah=atas;
            atas=newatas;
            bawah=newbawah;
        }
        cout<<"\n"<<"Masukkan jumlah partisi: ";
        cin>>partisi;
        if (partisi<1)
        {
            cout<<"Partisi >0 !"<<"\n";
            exit(0);
        }
        deltax=((atas-bawah)/partisi);

        int jlv;
        cout<<"Jumlah variabel: "<<"\n";
        cin>>jlv;
        float k[jlv],p[jlv];
        for (int i=0;i<jlv;i++)
        {
            cout<<"\n"<<"Konstanta variabel ke-"<<(i+1)<<": "<<"\n";
            cin>>k[i];
            cout<<"Pangkat variabel ke-"<<(i+1)<<": "<<"\n";
            cin>>p[i];
            cout<<"Variabel ke-"<<(i+1)<<" "<<k[i]<<"x^"<<p[i];
        }

        float f7,f8,hasilbawah=0,reversebawah,reversebawah1,balik;
        for (int h=0;h<jlv;h++) //Perhitungan Fungsi f(bawah)
        {
            if (p[h]==0)
            {
                f7=1;
                reversebawah=-1;
                reversebawah1=0;
            }
            else if(p[h]<0)
            {
                reversebawah=0;
                reversebawah1=-1;
                balik=p[h];
                p[h]*=-1;
            }
            else if (p[h]>0)
            {
                reversebawah=-1;
                reversebawah1=0;
            }
            for (int j=0;j<p[h];j++)
            {
                if (j>0)
                {
                    f8=f7;
                    f8*=bawah;
                    f7=f8;

                }
                else
                {
                    f8=bawah;
                    f7=f8;

                }
            }
            if (balik<0)
            {
                p[h]*=-1;
            }

            if (k[h]==0)        
            {
                hasilbawah+=0;
            }
            else
            {
                if (reversebawah==0 & reversebawah1==1)
                {
                    hasilbawah += (k[h])/f7;
                }
                else
                {
                    hasilbawah += k[h]*f7;
                }
            }

        }

        float f5,f6,hasilatas=0,reverseatas,reverseatas1,balik1;
        for (int h=0;h<jlv;h++) //Perhitungan Fungsi f(atas)
        {
            if (p[h]==0)
            {
                f5=1;
                reverseatas=-1;
                reverseatas1=0;
            }
            else if (p[h]<0)
            {
                reverseatas=0;
                reverseatas1=-1;
                balik1=p[h];
                p[h]*=-1;
            }
            else if (p[h]>0)
            {
                reverseatas=-1;
                reverseatas1=0;
            }
            for (int j=0;j<p[h];j++)
            {
                if (j>0)
                {
                    f6=f5;
                    f6*=atas;
                    f5=f6;

                }
                else
                {
                    f6=atas;
                    f5=f6;

                }
            }
            if (balik1<0)
            {
                p[h]*=-1;
            }
            if (k[h]==0)        
            {
                hasilatas+=0;
            }
            else
            {
                if (reverseatas==0 & reverseatas1==-1)
                {
                    hasilatas+=(k[h])/f5;
                }
                else
                {
                    hasilatas += k[h]*f5;
                }
            }

        }

        float hasilsigma=0,reverse,reverse1,balik2;
        for (float i=bawah+deltax; i<atas;i=i+deltax) // Perhitungan Fungsi (bawah+deltax) + ...+ fungsi(atas-deltax)
        {        
            for (int h=0;h<jlv;h++)
            {           
                float f2,f3;
                if (p[h]==0)
                {
                    f2=1;
                    reverse=-1;
                    reverse1=0;
                }
                else if (p[h]<0)
                {
                    reverse=0;
                    reverse1=-1;
                    balik2=p[h];
                    p[h]*=-1;
                }
                else if (p[h]>0)
                {
                    reverse=-1;
                    reverse1=0;
                }
                for (int j=0;j<p[h];j++)
                {
                    if (j>0)
                    {
                        f3=f2;
                        f3*=i;
                        f2=f3;

                    }
                    else
                    {
                        f3=i;
                        f2=f3;

                    }
                }

                if (balik2<0)
                {
                    p[h]*=-1;
                }

                float m;
                if (k[h]==0)        
                {
                    hasilsigma+=0;
                }
                else
                {
                    if (reverse==0 & reverse1==-1)
                    {
                        m=(k[h])/f2;
                    }
                    else
                    {
                        m = k[h]*f2;
                    }
                    hasilsigma+=m;
                }

            }
        }

        akhir = (deltax/2)*(hasilbawah+hasilatas+(2*hasilsigma));
        if (newbawah<newatas)
        {
            akhir*=-1;
        }
        cout<<"\n"<<"Hasil dari integral: "<<akhir<<"\n";
    }
        
}
