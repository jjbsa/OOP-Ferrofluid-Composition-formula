#include "Ferrofluid.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <numeric>

void FF::DisplayAllInfo() {

	//Width of domain viewr viwer = 8.4cm
	//Height of domain viewr viwer = 0.5mm
	//Membrane Thickness = 0.5mm
	//Membrance flex height = 0.1mm

	double Wdm = 8.4;
	double Hdm = 0.5, r;
	double Tm = 0.5;
	double Tmf = 0.1;

	double Vdm, Vm, Vtot;
		
	FF Value; FF_List FFcR;
	

	//1. Convert width to radius in m
	r = (Wdm / 2) / 100;

	cout << "Dimmesnion Values" << "\n" << endl;
	cout << "*****************" << endl;
	cout << "Radius used (m): " << r << endl; //cin >> Wdm;
	cout << "Height used (mm): " << Hdm << endl; //cin >> Hdm;
	cout << "Height of Membrane flex (mm): " << Tmf << endl; //cin >> Hdm;
	cout << "*****************" << endl;


	Hdm = Hdm / 1000; //convert Hight from mm to m
	Tmf = Tmf / 1000; //convert membrane flex hight from mm to m


	cout << "Volume Function:" << endl;
	Vdm = Value.VolumeDM(r, Hdm);
	Vm = Value.VolumeMem(r, Tmf); //Total Volume
	cout << "*****************" << endl;


	Vtot = Vdm + Vm;//Total Volume
	cout << "Total Volume of solution: " << Vtot << endl;
	cout << "*****************" << endl;


	//Ferrofluid composition ratio
	FFcR.FFComp(Vtot);

	//VolumeList
	cout << "*****Per one Batch******" << endl;
	FFcR.DisplayVolumeList();
}



double FF::VolumeDM(double Wdm, double h) {
	
	double Area, Volume, pi = 3.14;
		
	Area = pi * (Wdm * Wdm);
	cout << "\n" <<  "Area of Cylender = " << Area << " m^2" << endl;
	Volume = Area * h;
	cout << "Volume of Domain Viewer is: " << Volume << " m^3" << endl;

	return Volume;
}

double FF::VolumeMem(double r, double h) {
	
	//V(r,h) = 1/6*pi*h*(3r^2+h^2)
	double Area = 0, Volume, pi = 3.14;
	Volume = 0.1666 * pi * h * (3 * (r * r) + (h * h));
	cout << "Volume of membrane is: " << Volume << endl;

	return Volume;
}

double FF_List::FFComp(double Vtot) {
	FF FFcR; FF_List NanoPart; 	double np, wl, w;

	cout << "What is the composition ratio of the ferrofluid? (in percengtage)" << endl;
	cout << "Np: "; cin >> np; 	cout << "Wl: "; cin >> wl;	cout << "Water: "; cin >> w;
	//Percentage
	np /= 100; wl /= 100; w /= 100;
	np = Vtot * np;	wl = Vtot * wl;	w = Vtot * w;


	/*cout << "in m^3" << endl;
	cout << "Np = " << np << endl;
	cout << "wl = " << wl << endl;
	cout << "w = " << w << endl;*/
	//m^3 to Litres 
	wl *= 1000; w *= 1000;

	FFcR.setWl(wl); FFcR.setW(w); 
	np = NanoPart.NanoP(np); FFcR.setNp(np); 

	List.push_back(FFcR);
	cout << "\n";
	return np, wl, w;
}

void FF_List::DisplayVolumeList() {
	int N{}, D{}, i = 0;
	while (i < List.size()) { List[i].DisplayRatioInfo();	i++; }
}

double FF_List::NanoP(double vol) {

	double Mass, Density=5.25; //density of iron III in cm^3
	
	Density = Density; //um^3
	Mass = Density * vol;
	
	return Mass;
}

