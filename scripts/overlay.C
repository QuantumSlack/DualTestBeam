/******************************************************
Script for creating a plot overlay of specific 
ROOT plots from files matching a given file structure
******************************************************/

#include "TSystemDirectory.h"
#include "TList.h"
#include "TFile.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TString.h"
#include "TSystemFile.h"

void overlay(const char* infolder, const char* filter) {
    auto canvas = new TCanvas("c_overlay", "Overlay Canvas", 800, 600);
    auto legend = new TLegend(0.65, 0.65, 0.9, 0.9); // Adjusted legend position

    TSystemDirectory dir(infolder, infolder);
    TList *files = dir.GetListOfFiles();

    int i = 0; // Counter for colors and drawing order
    if (files) {
      for (TObject* obj : *files) {
            TSystemFile* file = dynamic_cast<TSystemFile*>(obj);
            if (!file) continue; // Skip if it's not a file object

            TString fname = file->GetName();
            if (file->IsDirectory() || !fname.Contains(filter)) {
                continue; // Skip subdirectories and files that don't match the filter
            }

            i++; // Increment counter for each valid file
            std::cout << "Processing file " << i << ": " << fname << std::endl;

            TFile *_file = TFile::Open(infolder + fname);
            if (!_file || _file->IsZombie()) continue;

            TH1F* th1 = (TH1F*)_file->Get("ehcEcalE");
            if (!th1) {
                _file->Close(); delete _file; // Clean up before skipping
                continue;
            }

            // 2.) Reformat the color handling
            th1->SetLineColor(i);
            th1->SetLineWidth(2);

            if (i == 1) {
                th1->SetTitle(TString::Format("Overlay for: %s", filter));
                th1->Draw("HIST");
            } else {
                th1->Draw("HIST SAME");
            }
            
            // 4.) Parse the filename for a clean legend entry
            TString label = fname;
            int pos = label.Index("step-");
            if (pos != TString::kNPOS) { // Check if "step-" was found
                 label.Remove(0, pos);
            }
            label.ReplaceAll(".root", ""); // Remove file extension
            legend->AddEntry(th1, label, "l");

            // 3.) Close and delete the file at the end of the loop
            _file->Close();
            delete _file;
        }
    }
    legend->Draw();
    
    // Save the final canvas as an image
    canvas->SaveAs(TString::Format("overlay_%s.pdf", filter));
}
