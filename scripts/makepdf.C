/*************************************************
Script for creating a pdf of specific ROOT plots
from files matching a given file structure

The input parameter for this function is the
directory where your files you're analyzing are

See line 40 for changing the input filename
structure
*************************************************/

#include "TFile.h"
#include "TCanvas.h"
#include "TH1.h"
#include "TLatex.h"
#include "TString.h"

void makepdf(const char* input_dir = ".") {
    // const int n_energies = 3; // Energy parameter commented out
    const int n_angles = 4;
    const int n_trans = 9;
    const int n_hists = 4;

    // int energies[n_energies] = {50, 100, 150}; // Energy array commented out
    // All incident angle parameters
    int angles[n_angles] = {0, 2, 5, 10}; // in degrees
    // All translation parameters across the crystal face 
    float trans[n_trans] = {-0.002, -0.0015, -0.001, -0.0005, 0., 0.0005, 0.001, 0.0015, 0.002}; // in cm
    // Histograms you want to draw, as an array
    TString hists[n_hists] = {"ehetrue", "CalEcalnscint", "CalEcalncer", "ehcEcalE"};
    // Final result output file name
    TString output_filename = "summary_plots.pdf";

    TCanvas *canvas = new TCanvas("canvas", "My Analysis Canvas", 800, 600);
    // Open the multi-page PDF file
    canvas->Print(output_filename + "[");

    // for (int i = 0; i < n_energies; ++i) { // Energy loop commented out
    for (int i = 0; i < n_angles; ++i) {
        for (int j = 0; j < n_trans; ++j) {
            // int current_energy = energies[i]; // Energy variable commented out
            int current_angle = angles[i];
            float current_trans = trans[j];

            // Construct the filename without the energy parameter.
            // This is where you change the input file name structure
            TString input_filename = TString::Format("%s/res_out_DRConly-dial_40GeV_e-_theta-%d_step-%.4f.root", input_dir, current_angle, current_trans);
            printf("Processing: %s\n", input_filename.Data());

            TFile *root_file = TFile::Open(input_filename);
            if (!root_file || root_file->IsZombie()) {
                printf("--> Error: Could not open %s. Skipping.\n", input_filename.Data());
                continue;
            }

            // Add a descriptive text page to the PDF for this file.
            canvas->Clear();
            TLatex *text = new TLatex();
            text->SetTextSize(0.04);
            text->DrawLatexNDC(0.15, 0.8, "Processing file:");
            text->DrawLatexNDC(0.20, 0.7, input_filename);
            // text->DrawLatexNDC(0.15, 0.5, TString::Format("Energy: %d GeV", current_energy)); // Energy line commented out
            text->DrawLatexNDC(0.15, 0.4, TString::Format("Angle: %d degrees", current_angle));
            text->DrawLatexNDC(0.15, 0.3, TString::Format("Translation: %.4f cm", current_trans));
            canvas->Print(output_filename);
            delete text;

            // Loop over the histogram names in the current file
            for (int k = 0; k < n_hists; ++k) {
                TString current_hist_name = hists[k];
                TH1* hist = (TH1*)root_file->Get(current_hist_name);

                if (!hist) {
                    printf("  --> Error: Could not find '%s'. Skipping plot.\n", current_hist_name.Data());
                    continue;
                }

                // Draw histogram with title
                canvas->Clear();
                hist->SetTitle(TString::Format("%s (A=%d, T=%.4f)", current_hist_name.Data(), current_angle, current_trans));
                hist->Draw("HIST");
                canvas->Print(output_filename);
            }

            // Unload the file.
            root_file->Close();
            delete root_file;
        }
    }
    // } // End of commented-out energy loop

    // Close the multi-page PDF file. The "]" is crucial.
    canvas->Print(output_filename + "]");
    delete canvas;

    printf("\n All plots saved to %s\n", output_filename.Data());
}
