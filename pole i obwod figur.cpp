/* 
 * File:   main.cpp
 * Author: rafastan
 *
 * Created on 23 paŸdziernik 2017, 15:16
 */

#include <stdlib.h>
#include <iostream>
#include <math.h>
/*
 * 
 */


class Wielokat{									//klasa wirtualna, do dziedziczenia
public:
    virtual double polePowierzchni() const=0;
    virtual double obwod() const=0;
};

class Punkt{									// klasa punkt odpowiedzialna za podanie odleglosci
public:
        double x,y;

        double odl(Punkt p) const{
            return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
        }

        Punkt(){
            x=0;
            y=0;
        }
};

class Kwadrat:public Wielokat{					//klasa KWADRAT z dziedziczeniem od klasy wirtualnej WIELOKAT
	Punkt Ak,Bk,Ck,Dk;							//deklaracja zmiennych naszych boków
	public:										
		double obwod() const{					//funkcja liczaca obwod
		return Bk.odl(Ak)+Ck.odl(Bk)+Dk.odl(Ck)+Ak.odl(Dk);
	}
	
	double polePowierzchni() const{				//funkcja licz. pole pow.
		double zk=(Bk.x-Ak.x)*(Bk.x-Ak.x);		// wzor na pole a*a
		if(zk<0) zk= -zk;						//wartosc bezwzgledna (jesli z ujemne, zmien znak)
		return zk;								//wyswietl polePowierzchni
	}
    Kwadrat(double x1,double y1,double x2,double y2,double x3,double y3,double y4, double x4){	//deklaracja x i y punktow Ak -> Dk
        this->Ak.x=x1;
        this->Bk.x=x2;
        this->Ck.x=x3;
        this->Dk.x=x4;
        this->Ak.y=y1;
        this->Bk.y=y2;
        this->Ck.y=y3;
        this->Dk.y=y4;
    };
    Kwadrat(){
        Ak.x=1;
        Ak.y=1;
        Bk.x=3;
        Bk.y=1;				// przypisanie wartosci
        Ck.x=2;
        Ck.y=2;
        Dk.x=4;
        Dk.y=2;
    };


};

class Prostokat:public Wielokat{
	Punkt Ap,Bp,Cp,Dp;
	public:
		double obwod() const{
		return Bp.odl(Ap)+Cp.odl(Bp)+Dp.odl(Cp)+Ap.odl(Dp);
	}
	
	double polePowierzchni() const{
		double zp=(Bp.x-Ap.x)*(Dp.x-Cp.x);
		if(zp<0) zp= -zp;
		return zp;
	}
    Prostokat(double x1,double y1,double x2,double y2,double x3,double y3,double y4, double x4){
        this->Ap.x=x1;
        this->Bp.x=x2;
        this->Cp.x=x3;
        this->Dp.x=x4;
        this->Ap.y=y1;
        this->Bp.y=y2;
        this->Cp.y=y3;
        this->Dp.y=y4;
    }
    Prostokat(){
        Ap.x=1;
        Ap.y=1;
        Bp.x=3;
        Bp.y=1;
        Cp.x=2;
        Cp.y=2;
        Dp.x=4;
        Dp.y=2;
    }


};


class Trojkat:public Wielokat{

    //double x1,x2,x3,y1,y2,y3;
    Punkt A,B,C;

public:
    double obwod() const{
        return B.odl(A)+C.odl(B)+A.odl(C);
    }
    double polePowierzchni() const{
        double z=(0.5*(B.x-A.x)*(C.y-B.y)-(B.y-A.y)*(C.x-A.x));
        if (z<0) z=-z; 
        return z;
    }

    Trojkat(double x1,double y1,double x2,double y2,double x3,double y3){
        this->A.x=x1;
        this->B.x=x2;
        this->C.x=x3;
        this->A.y=y1;
        this->B.y=y2;
        this->C.y=y3;
    }
    Trojkat(){
        A.x=1;
        A.y=1;
        B.x=3;
        B.y=1;
        C.x=2;
        C.y=2;
    }
};


int main(int argc, char** argv) {


//    Zwierze z1;

    //Wielokat ff;
    
//    Kwadrat k1;

    Trojkat t1;  //deklaracja zmiennej t1 dla klasy TROJKAT
	Kwadrat k1;
	Prostokat p1;

    std::cout<<" Pole powierzchni trojkata="<<t1.polePowierzchni()<<" obwod="<<t1.obwod()<<"\n"; // wyswietlenie pola t1.polePowierchni() i obwodu  t1.obwod()
    std::cout<<" Pole powierzchni kwadratu="<<k1.polePowierzchni()<<" obwod="<<k1.obwod()<<"\n";
	std::cout<<" Pole powierzchni prostokata="<<p1.polePowierzchni()<<" obwod="<<p1.obwod()<<"\n";

    return (EXIT_SUCCESS);
}
