#ifndef PLOTTING_H
#define PLOTTING_H

#include "TCanvas.h"
#include "TProfile.h"
#include "TH2.h"
#include "TStyle.h"
#include "TLine.h"
#include "TH1.h"

void SCEDraw1 (TCanvas* canv,  const char* name,TH1F* h1, const char* outfile, bool logy);

void SCEDraw1tp (TCanvas* canv,  const char* name,TProfile* h1, const char* outfile);

void SCEDrawp (TCanvas* canv,  const char* name,TProfile* h1, const char* outfile);

void SCEDraw1_2D (TCanvas* canv,  const char* name,TH2F* h1, const char* outfile, bool doline, float eohS, float eohC);

void SCEDraw2_2D (TCanvas* canv,  const char* name,TH2F* h1, TH2F* h2, const char* outfile, bool doline, float eohS, float eohC);

void SCEDraw2 (TCanvas* canv,  const char* name, TH1F* h1, TH1F* h2, const char* outfile, bool logy);

void SCEDraw3 (TCanvas* canv,  const char* name, TH1F* h1, TH1F* h2, TH1F* h3, const char* outfile,bool logy);


#endif 
