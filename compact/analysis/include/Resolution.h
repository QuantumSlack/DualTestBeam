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
#include "DD4hep/Printout.h"
#include "DD4hep/Objects.h"
#include "DD4hep/Factories.h"
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

void getStuff(map<string, int> mapsampcalslice, int gendete, int gendeth, int ievt, bool doecal, bool dohcal, int hcaltype, bool doedge,TBranch* &b_ecal,TBranch* &b_hcal,TBranch*  &b_edge,CalHits* &ecalhits, CalHits* &hcalhits, CalHits* &edgehits, float &timecut, bool &fillhists,
	      float  &eesum,float &eesumcal,float &eesumem, float &eesumair,float &eesumdead, float &eesumcrystal,float &eesumPDe,float &eesumfiber1,float &eesumfiber2,float &eesumabs,float &eesumPDh,float &eesumairem, float &eesumdeadem, float &eesumcrystalem,float &eesumPDeem,float &eesumfiber1em, float &eesumfiber2em,float &eesumabsem,float &eesumPDhem,float &eesumedge,float &eesumedgerel, float &necertotecal,float &nescinttotecal,float &necertothcal,float &nescinttothcal,float &eecaltimecut, float &ehcaltimecut,float &erelecaltimecut, float &erelhcaltimecut,int &nine,int &ninh);

void FillTime(map<string, int> mapsampcalslice, int gendete, int gendeth, int ievt, bool doecal, bool dohcal, int hcaltype, bool doedge,TBranch* &b_ecal,TBranch* &b_hcal,TBranch*  &b_edge,CalHits* &ecalhits, CalHits* &hcalhits, CalHits* &edgehits, float &timecut,
	      TH1F* eecaltime, TH1F* ehcaltime, TH1F *ecalpd1scint,TH1F *ecalpd1cer,TH1F *ecalpd2scint,TH1F *ecalpd2cer,TH1F *hcalpd1scint,TH1F *hcalpd1cer,TH1F *hcalpd2scint,TH1F *hcalpd2cer);

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
