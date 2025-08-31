#ifndef RESOLUTION_H
#define RESOLUTION_H

#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBranch.h"
#include "TBrowser.h"
#include "TH2.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TProfile.h"
#include "TRandom.h"
#include "TSystem.h"
#include "TStyle.h"
#include "TLine.h"
#include "TMath.h"
#include "/home/atlas/DD4hep/install/include/DD4hep/Printout.h"
#include "/home/atlas/DD4hep/install/include/DD4hep/Objects.h"
#include "/home/atlas/DD4hep/install/include/DD4hep/Factories.h"
#include "../../../include/DualCrysCalorimeterHit.h"
#include "timeFrames.h"
#include "ecalProcessing.h"
#include "hcalProcessing.h"
#include "plotting.h"
#include "globals.h"

#include <vector>
#include <functional>
#include <map>
#include <algorithm>

#include <iostream>
#include <sstream> // for ostringstream
#include <string>

using namespace std;


//TRandom3 aar;

//int SCECOUNT=5;
//int SCECOUNT2=20;
//int icount777=0;
//int SCECOUNT3=10;
//int SCECOUNTHITHIT=1;
///int ihitcounts=0;
//int ihitcountc=0;

//float timecut=10;
//float betacut=1/1.5;
//const int finenbin=100;
//const float timemin=0.;
//const float timemax=100.;

//const float timebinsize=(timemax-timemin)/float(finenbin);


// float kappaEcal(1.),kappaHcal(1.);
//float biggesttime=0.;
//map<string, int> mapsampcalslice;

typedef std::vector<dd4hep::sim::Geant4Particle*> GenParts;
//typedef std::vector<CalVision::DualCrysCalorimeterHit*> CalHits;
//typedef dd4hep::sim::Geant4HitData::MonteCarloContrib Contribution;
//typedef std::vector<dd4hep::sim::Geant4HitData::MonteCarloContrib> Contributions;




// void SCEDraw1 (TCanvas* canv, const char* name, TH1F* h1, const char* outfile, bool logy);
// void SCEDraw1tp (TCanvas* canv, const char* name, TProfile* h1, const char* outfile);
// void SCEDraw1_2D (TCanvas* canv, const char* name, TH2F* h1, const char* outfile,bool dline, float eohS,float eohC);
// void SCEDraw2_2D (TCanvas* canv, const char* name, TH2F* h1, TH2F* h2, const char* outfile,bool doline, float eohS,float eohC);
// void SCEDraw2 (TCanvas* canv,  const char* name, TH1F* h1, TH1F* h2, const char* outfile,bool logy);
// void SCEDraw3 (TCanvas* canv,  const char* name, TH1F* h1, TH1F* h2, TH1F* h3, const char* outfile, bool logy);

// void PrepareEcalTimeFrames(int ievt, TBranch* &b_ecal,CalHits* &ecalhits);


void getStuff(map<string, int> mapsampcalslice, int gendete, int gendeth, int ievt, bool doecal, bool dohcal, int hcaltype, bool doedge,TBranch* &b_ecal,TBranch* &b_hcal,TBranch*  &b_edge,CalHits* &ecalhits, CalHits* &hcalhits, CalHits* &edgehits, float &timecut, bool &fillhists,
	      float  &eesum,float &eesumcal,float &eesumem, float &eesumair,float &eesumdead, float &eesumcrystal,float &eesumPDe,float &eesumfiber1,float &eesumfiber2,float &eesumabs,float &eesumPDh,float &eesumairem, float &eesumdeadem, float &eesumcrystalem,float &eesumPDeem,float &eesumfiber1em, float &eesumfiber2em,float &eesumabsem,float &eesumPDhem,float &eesumedge,float &eesumedgerel, float &necertotecal,float &nescinttotecal,float &necertothcal,float &nescinttothcal,float &eecaltimecut, float &ehcaltimecut,float &erelecaltimecut, float &erelhcaltimecut,int &nine,int &ninh);

void FillTime(map<string, int> mapsampcalslice, int gendete, int gendeth, int ievt, bool doecal, bool dohcal, int hcaltype, bool doedge,TBranch* &b_ecal,TBranch* &b_hcal,TBranch*  &b_edge,CalHits* &ecalhits, CalHits* &hcalhits, CalHits* &edgehits, float &timecut,
	      TH1F* eecaltime, TH1F* ehcaltime, TH1F *ecalpd1scint,TH1F *ecalpd1cer,TH1F *ecalpd2scint,TH1F *ecalpd2cer,TH1F *hcalpd1scint,TH1F *hcalpd1cer,TH1F *hcalpd2scint,TH1F *hcalpd2cer);
// void Elec_Sim(TH1F* In, TH1F* Out);  // take histogram of true arrival times at photodetector and produce output signal
//double int_charge(TH1F* out, double pre, double window );
//double SPR(double tNow);  // response of electronics to a photoelectron
//double AFILTER(int ifilter, double wavelength);  // get probability to pass sipm pde and any wavelength filters
//double sipmpde(int isipm, double wavelength);  // sipmm qe as a function of wavelength

void getStuffDualCorr(bool domissCorr, float beamE, map<string, int> mapsampcalslice, int gendete, int gendeth, float kappaecal, float kappahcal, float meanscinEcal, float meancerEcal, float meanscinHcal, float meancerHcal, int  ievt,bool doecal,bool dohcal, int hcaltype, bool doedge,float &eesumedge, float &eesumedgerel, TBranch* &b_ecal,TBranch* &b_hcal, TBranch* &b_edge,CalHits* &ecalhits, CalHits* &hcalhits,CalHits* &edgehits,float &EEcal, float &EHcal,float &timecut, float &eecaltimecut, float &ehcaltimecut, float &erelecaltimecut, float &erelhcaltimecut);

void getMeanPhot(map<string, int> mapsampcalslice, int gendete, int gendeth, int ievt, bool doecal, bool dohcal, int hcaltype, TBranch* &b_ecal,TBranch* &b_hcal,CalHits* &ecalhits, CalHits* &hcalhits,
		 float &meanscinEcal, float &meanscinHcal, float &meancerEcal, float &meancerHcal,float &timecut, float &eecaltimecut, float &ehcaltimecut, float &erelecaltimecut, float &erelhcaltimecut);

void CalibRefine(map<string, int> mapsampcalslice,  int gendete, int gendeth, int ievt, bool doecal, bool dohcal, int hcaltype, TBranch* &b_ecal,TBranch* &b_hcal,CalHits* &ecalhits, CalHits* &hcalhits, float &meanscinEcal, float &meanscinHcal, float &meancerEcal, float &meancerHcal,TH1F *CalEcalncer, TH1F *CalEcalnscint, TH1F *CalHcalncer, TH1F *CalHcalnscint
);
#ifdef __cplusplus 
extern "C" 
	{ 
		void Resolution(int num_evtsmax, const char* einputfilename, const char* piinputfilename,
		const char* hcalonlyefilename, const char* hcalonlypifilename,
		const float beamEE, bool doecal, bool dohcal, int hcaltype, bool doedge, bool domissCorr,bool doedgecut, float edgecut,int gendete, int gendeth, const char* outputfilename,const char* ECALleaf, const char* HCALleaf,bool doplots, bool dotimingplots,bool dodualcorr, bool twocalecalcorr);
	}
#endif
#endif 
