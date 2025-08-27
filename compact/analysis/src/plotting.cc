#include "../include/plotting.h"

void SCEDraw1 (TCanvas* canv,  const char* name,TH1F* h1, const char* outfile, bool logy) {

  canv= new TCanvas(name,name,200,10,700,500);


  //canv = new TCanvas(canvName,canvName,50,50,W,H);
  canv->SetFillColor(0);
  canv->SetBorderMode(0);
  canv->SetFrameFillStyle(0);
  canv->SetFrameBorderMode(0);
  canv->SetTickx(0);
  canv->SetTicky(0);
  gStyle->SetOptFit();
  gStyle->SetPalette(1,0);
  if(logy) canv->SetLogy();

  h1->SetLineColor(kGreen);
  h1->SetLineWidth(1);
  h1->SetStats(111111);
  h1->Draw("HIST");



  canv->Print(outfile,".png");
  canv->Update();

  return;
}
void SCEDraw1tp (TCanvas* canv,  const char* name,TProfile* h1, const char* outfile) {

  canv= new TCanvas(name,name,200,10,700,500);


  //canv = new TCanvas(canvName,canvName,50,50,W,H);
  canv->SetFillColor(0);
  canv->SetBorderMode(0);
  canv->SetFrameFillStyle(0);
  canv->SetFrameBorderMode(0);
  canv->SetTickx(0);
  canv->SetTicky(0);

  h1->SetLineColor(kGreen);
  h1->SetLineWidth(kGreen);
  h1->SetStats(111111);
  h1->Draw("HIST");



  canv->Print(outfile,".png");
  canv->Update();

  return;
}

void SCEDrawp (TCanvas* canv,  const char* name,TProfile* h1, const char* outfile) {

  canv= new TCanvas(name,name,200,10,700,500);


  //canv = new TCanvas(canvName,canvName,50,50,W,H);
  canv->SetFillColor(0);
  canv->SetBorderMode(0);
  canv->SetFrameFillStyle(0);
  canv->SetFrameBorderMode(0);
  canv->SetTickx(0);
  canv->SetTicky(0);

  h1->SetLineColor(kGreen);
  h1->SetLineWidth(kGreen);
  h1->SetStats(111111);
  h1->SetMarkerSize(20);
  h1->SetMarkerStyle(4);
  h1->SetMarkerColor(6);
  gStyle->SetOptFit();
  h1->Draw("*");



  canv->Print(outfile,".png");
  canv->Update();

  return;
}


void SCEDraw1_2D (TCanvas* canv,  const char* name,TH2F* h1, const char* outfile, bool doline, float eohS, float eohC) {

  canv= new TCanvas(name,name,200,10,700,500);


  //canv = new TCanvas(canvName,canvName,50,50,W,H);
  canv->SetFillColor(0);
  canv->SetBorderMode(0);
  canv->SetFrameFillStyle(0);
  canv->SetFrameBorderMode(0);
  canv->SetTickx(0);
  canv->SetTicky(0);

  h1->SetLineColor(kGreen);
  h1->SetLineWidth(kGreen);
  h1->SetMarkerSize(0.2);
  h1->SetMarkerColor(kMagenta);
  h1->SetStats(111111);
  h1->Draw("colz");

  TLine line = TLine(eohS,eohC,1.,1.);
  line.SetLineColor(kBlue);
  line.SetLineWidth(2);
  if(doline) line.Draw("same");


  canv->Print(outfile,".png");
  canv->Update();

  return;
}

void SCEDraw2_2D (TCanvas* canv,  const char* name,TH2F* h1, TH2F* h2, const char* outfile, bool doline, float eohS, float eohC) {

  canv= new TCanvas(name,name,200,10,700,500);


  //canv = new TCanvas(canvName,canvName,50,50,W,H);
  canv->SetFillColor(0);
  canv->SetBorderMode(0);
  canv->SetFrameFillStyle(0);
  canv->SetFrameBorderMode(0);
  canv->SetTickx(0);
  canv->SetTicky(0);

  h1->SetLineColor(kGreen);
  h1->SetLineWidth(kGreen);
  h1->SetMarkerColor(kGreen);
  h1->SetStats(111111);
  h1->Draw("colz");

  h2->SetLineColor(kBlue);
  h2->SetLineWidth(kBlue);
  h2->SetMarkerColor(kBlue);
  h2->SetStats(111111);
  h2->Draw("same");

  TLine line = TLine(eohS,eohC,1.,1.);
  line.SetLineColor(kCyan);
  line.SetLineWidth(2);
  if(doline) line.Draw("same");


  canv->Print(outfile,".png");
  canv->Update();

  return;
}


void SCEDraw2 (TCanvas* canv,  const char* name, TH1F* h1, TH1F* h2, const char* outfile, bool logy) {

  canv= new TCanvas(name,name,200,10,700,500);


  //canv = new TCanvas(canvName,canvName,50,50,W,H);
  canv->SetFillColor(0);
  canv->SetBorderMode(0);
  canv->SetFrameFillStyle(0);
  canv->SetFrameBorderMode(0);
  canv->SetTickx(0);
  canv->SetTicky(0);
  if(logy) canv->SetLogy();

  float max = std::max(h1->GetMaximum(),h2->GetMaximum());
  h1->SetMaximum(max*1.3);



  h1->SetLineColor(kGreen);
  h1->SetLineWidth(3);
  h1->SetStats(111111);
  h1->Draw("HIST");



  h2->SetLineColor(kRed);
  h2->SetLineWidth(3);
  h2->SetStats(111111);
  h2->Draw("HIST same");


  canv->Print(outfile,".png");
  canv->Update();

  return;
}


void SCEDraw3 (TCanvas* canv,  const char* name, TH1F* h1, TH1F* h2, TH1F* h3, const char* outfile,bool logy) {

  canv= new TCanvas(name,name,200,10,700,500);


  //canv = new TCanvas(canvName,canvName,50,50,W,H);
  canv->SetFillColor(0);
  canv->SetBorderMode(0);
  canv->SetFrameFillStyle(0);
  canv->SetFrameBorderMode(0);
  canv->SetTickx(0);
  canv->SetTicky(0);
  if(logy) canv->SetLogy();

  float max = std::max(h1->GetMaximum(),h2->GetMaximum());
  h1->SetMaximum(max*1.3);



  h1->SetLineColor(kGreen);
  h1->SetLineWidth(3);
  h1->SetStats(111111);
  h1->Draw("HIST");



  h2->SetLineColor(kRed);
  h2->SetLineWidth(3);
  h2->SetStats(111111);
  h2->Draw("HIST same");



  h3->SetLineColor(kBlue);
  h3->SetLineWidth(3);
  h3->SetStats(111111);
  h3->Draw("HIST same");


  canv->Print(outfile,".png");
  canv->Update();

  return;
}