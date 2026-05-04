/*************************************************
Script for creating a pdf of specific ROOT plots
overlaid by a given parameter from files matching 
a given file structure

In this case, it is taking files that vary with
energy, incident angle, and translated position
and combining all plots with the same energy
and angle
*************************************************/

#include "TSystemDirectory.h"
#include "TList.h"
#include "TFile.h"
#include "TH1.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TString.h"
#include "TSystemFile.h"

void overlay_pdf(const char* input_dir = ".") {
    // Config
    int energies[] = {10, 15, 20, 25, 30, 35, 40, 45, 50, 100};   // List of energies to loop over
    int angles[] = {0, 2, 5, 10};                                 // The angles to loop over
    TString output_filename = "overlay_summary.pdf";              // Final output file name
    TString plotname = "ehcEcalE";                                // Histogram name to plot

    auto canvas = new TCanvas("c_multi", "Multi-Overlay Canvas", 800, 600);
    canvas->Print(output_filename + "["); // Open the multi-page PDF

    // Nested loop for both energy and angle
    for (int current_energy : energies) {
        for (int current_angle : angles) {
            printf("--- Processing overlays for Energy: %d GeV, Angle: %d deg ---\n", current_energy, current_angle);
            
            // Filter for the unique energy-angle pair
            TString filter = TString::Format("%dGeV_e-_theta-%d", current_energy, current_angle);
            
            canvas->Clear();
            auto legend = new TLegend(0.65, 0.65, 0.9, 0.9);
	        legend->SetHeader("Step Value (cm)", "C");
	    
            TSystemDirectory dir(input_dir, input_dir);
            TList *files = dir.GetListOfFiles();
            int i = 0; // Reset file-counter for each new overlay plot

            if (files) {
                for (TObject* obj : *files) {
                    TSystemFile* file = dynamic_cast<TSystemFile*>(obj);
                    if (!file) continue;

                    TString fname = file->GetName();
                    if (file->IsDirectory() || !fname.Contains(filter)) {
                        continue;
                    }
                    
                    i++;
                    TFile *_file = TFile::Open(TString(input_dir) + "/" + fname);
                    if (!_file || _file->IsZombie()) continue;

		    // Declaring which histogram to get from the file
                    TH1F* th1 = (TH1F*)_file->Get(plotname);
                    if (!th1) { _file->Close(); delete _file; continue; }

                    th1->SetDirectory(0);
		            th1->SetStats(0);    // Turn off statistics box
                    th1->SetLineColor((i < 5 || i >= 9) ? i : i+1);  // Setting color palatte to skip color 5 (hard-to-see yellow)
                    th1->SetLineWidth(2);
                    
                    if (i == 1) {
                        // Update title 
                        th1->SetTitle(TString::Format(plotname + ": Overlay for E=%d GeV, Angle=%d deg", current_energy, current_angle));
                        th1->Draw("HIST");
                    } else {
                        th1->Draw("HIST SAME");
                    }

                    TString label = fname;
                    int pos = label.Index("step-");
                    if (pos != TString::kNPOS) {
		      label.Remove(0, pos);
		      label.ReplaceAll("step-", "");
		      label.ReplaceAll(".root","");
		    }
		    else{
		      label = "N/A";
		    }
                   legend->AddEntry(th1, label, "l");

                    _file->Close();
                    delete _file;
                }
            }
            
            // Only add a page to the PDF if at least one file was found
            if (i > 0) {
                legend->Draw();
                canvas->Print(output_filename);
            } else {
                 printf("    -> No files found for this combination. Skipping page.\n");
            }
            delete legend;
        }
    }

    canvas->Print(output_filename + "]"); // Close the PDF
    delete canvas;
    printf("\n PDF with controlled overlay plots created: %s\n", output_filename.Data());
}
