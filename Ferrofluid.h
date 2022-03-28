#pragma once
#ifndef Ferrofluid_H
#define Ferrofluid_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class FF
{
	double Wdv, Hdv, Tm, Tmf, FFcR,Np,wl,w;

public:

	FF(double WdvN = 0, double HdvN = 0, double TmN = 0, double TmfN = 0, double FFcRN = 0,double NpNew =0,double wlNew=0,double wNew=0) :
		Wdv(WdvN), Hdv(HdvN), Tm(TmN), Tmf(TmfN), FFcR(FFcRN), Np(NpNew),wl(wlNew),w(wNew) {}

	double VolumeDM(double a, double b);
	double VolumeMem(double a, double b);
	inline double getNp() const { return Np; }; //Acsessor Function 
	inline double getWl() const { return wl; };
	inline double getW() const { return w; }; //Acsessor Function 
	inline void setNp(const double NewNp) {Np = NewNp; return; }
	inline void setWl(const double NewWl) { wl = NewWl; return; }
	inline void setW(const double NewW) { w = NewW; return; }
	void DisplayAllInfo();
	inline void DisplayRatioInfo() { cout << "Nano Particles : "<< getNp() << " Grams\n" << "\n" << "Washing up Liquid : " << getWl() << " Litres\n" << "\n" << "Water: " << getW() << " Litres\n" << "************************" << endl; };
	
};


class FF_List {
	
	vector <FF> List;

public:
	double FFComp(double a);
	void DisplayVolumeList();
	inline double NanoP(double vol);
};
#endif
