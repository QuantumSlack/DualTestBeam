import ROOT
import array
from pyroot_setup import load_dd4hep_libraries
import numpy as np
import math
import argparse
load_dd4hep_libraries()
### extracting file names from the arguments
arg_parser = argparse.ArgumentParser()
arg_parser.add_argument("-g", "--geometry")
arg_parser.add_argument("-E", "--beam_energy")
args = arg_parser.parse_args()
detector_geo = args.geometry
beam_energy = args.beam_energy
file_dir = "/eos/user/a/adagarwa/DD4hep/examples/DualTestBeam/compact/output/"+detector_geo+"/"
electron_file = file_dir+"out_"+detector_geo+"_"+beam_energy+"GeV_e-.root"
pion_file = file_dir+"out_"+detector_geo+"_"+beam_energy+"GeV_pi-.root"
### for electron beam 
file_e = ROOT.TFile.Open(electron_file)
tree_e = file_e.Get("EVENT")
num_e = tree_e.GetEntries()

nceren_e_arr = []
nscint_e_arr = []
energy_deposit_e = []
edgerelativistic_e = []
ncerenkov_e = 0
nscintillation_e = 0
energydeposit_e = 0
edge_rel_e = 0
i = 0
### for pion beam
file_pi = ROOT.TFile.Open(pion_file)
tree_pi = file_pi.Get("EVENT")
num_pi = tree_pi.GetEntries()
nceren_pi_arr = []
nscint_pi_arr = []
energy_deposit_pi = []
edgerelativistic_pi = []
energydeposit_pi = 0
edge_rel_pi = 0
ncerenkov_pi = 0
nscintillation_pi = 0
j = 0
### Creating the plots

### for electrons
for event in tree_e:
    for hit in event.DRFNoSegment:
          ncerenkov_e+=hit.ncerenkov
          nscintillation_e+=hit.nscintillator
          energydeposit_e+=hit.energyDeposit
          edge_rel_e+=hit.edeprelativistic
    nceren_e_arr.append(ncerenkov_e)
    nscint_e_arr.append(nscintillation_e)
    energy_deposit_e.append(energydeposit_e)
    edgerelativistic_e.append(edge_rel_e)
    ncerenkov_e = 0
    nscintillation_e = 0
    energydeposit_e = 0
    edge_rel_e = 0
nceren_e = array.array("i", nceren_e_arr)
nscint_e = array.array("i", nscint_e_arr)
eDeposit_e = array.array("f", energy_deposit_e)
edge_relativistic_e = array.array("f", edgerelativistic_e)

cerenkov_e = array.array("i", [0])
scintillation_e = array.array("i", [0])
energydeposit_hist_e = array.array("f", [0.])
edge_hist_e = array.array("f", [0.])
canvas = ROOT.TCanvas()

### declare histograms for plotting
f1 = ROOT.TFile.Open("hists_electronbeam_"+beam_energy+"GeV.root", "RECREATE")
ncer_e = ROOT.TH1I("ncer_hist", detector_geo+": cherenkov histogram for electron beam of energy"+beam_energy+" GeV", 500, 0, 2 * np.mean(nceren_e))
nscinthist_e = ROOT.TH1I("nscint_hist", detector_geo+": scintillation histogram for electron beam of energy"+beam_energy+" GeV", 500 , 0, 2 * np.mean(nscint_e))
### declare files for storing raw data ###
f_out = ROOT.TTree("electronbeam_"+detector_geo+"_"+beam_energy+"GeV_rawdata", "Raw Measurments")
f_out.Branch("cerenkov_data_e", cerenkov_e, "nceren_e/I")
f_out.Branch("scintillation_data_e", scintillation_e,  "nscint_e/I")
f_out.Branch("energydeposit_e", energydeposit_hist_e, "energydeposit_e/F")
f_out.Branch("edeprelativistic_e", edge_hist_e, "edeprelativistic_e/F")
fitFunction = ncer_e.GetFunction("gaus")
f_out.Branch("mean", fitFunction.GetParameter(1), "mean/F")
f_out.Branch("std", fitFunction.GetParameter(2), "std/F")
for i in range(num_e):
     ncer_e.Fill(nceren_e[i])
     nscinthist_e.Fill(nscint_e[i])
     energydeposit_hist_e[0] = eDeposit_e[i]
     edge_hist_e[0] = edge_relativistic_e[i]
     cerenkov_e[0] = nceren_e[i]
     scintillation_e[0] = nscint_e[i]
     f_out.Fill()
#f_out.Fill(fitFunction.GetParameter(1))
#f_out.Fill(fitFunction.GetParameter(2))
ncer_e.Fit("gaus")
ncer_e.Draw()
nscinthist_e.Fit("gaus")
nscinthist_e.Draw("SAME")
canvas.SaveAs(detector_geo+"_e-_"+beam_energy+"GeV.pdf")
print("Histogram for electron beam is done")
f_out.Write()
f1.Write()
f1.Close()

### for pions 
for event in tree_pi:
    for hit in event.DRFNoSegment:
        ncerenkov_pi+=hit.ncerenkov
        nscintillation_pi+=hit.nscintillator
        energydeposit_pi+=hit.energyDeposit
        edge_rel_pi+=hit.edeprelativistic
    nceren_pi_arr.append(ncerenkov_pi)
    nscint_pi_arr.append(nscintillation_pi)
    energy_deposit_pi.append(energydeposit_pi)
    edgerelativistic_pi.append(edge_rel_pi)
    ncerenkov_pi = 0
    nscintillation_pi = 0
    energydeposit_pi = 0
    edge_rel_pi = 0
nceren_pi = array.array("i", nceren_pi_arr)
nscint_pi = array.array("i", nscint_pi_arr)
cerenkov_pi = array.array("i", [0])
scintillation_pi = array.array("i", [0])
energydeposit_hist_pi = array.array("f", [0.])
edge_hist_pi = array.array("f", [0.])
eDeposit_pi = array.array("f", energy_deposit_pi)
edge_relativistic_pi = array.array("f", edgerelativistic_pi)

f2 = ROOT.TFile.Open("hists_pionbeam_"+beam_energy+"GeV.root", "RECREATE")
ncer_pi = ROOT.TH1I("ncer_hist_pi", detector_geo+": cherenkov histogram for pion- beam of"+beam_energy+" GeV", 500, 0, 2 * np.mean(nceren_pi))
nscint_pi_hist = ROOT.TH1I("nscint_hist_pi", detector_geo+": scintillation histogram for pion- beam of"+beam_energy+" GeV", 500, 0, 2 * np.mean(nscint_pi))
f_out_pi = ROOT.TTree("pionbeam_"+detector_geo+"_"+beam_energy+"GeV_rawdata", "Raw Data")
f_out_pi.Branch("cerenkov_data_pi", cerenkov_pi, "nceren_pi/I")
f_out_pi.Branch("scintillation_data_pi", scintillation_pi, "nscint_pi/I")
f_out_pi.Branch("energydeposit_pi", energydeposit_hist_pi, "energydeposit_pi/F")
f_out_pi.Branch("edeprelativistic_pi", edge_hist_pi, "edeprelativistic_pi/F")
fitFunc_pi = ncer_pi.GetFunction("gaus")
f_out_pi.Branch("mean", fitFunc_pi.GetParameter(1), "mean/F")
f_out_pi.Branch("std", fitFunc_pi.GetParameter(2), "std/F")
for k in range(num_pi):
    ncer_pi.Fill(nceren_pi[k])
    nscint_pi_hist.Fill(nscint_pi[k])
    energydeposit_hist_pi[0] = eDeposit_pi[k]
    edge_hist_pi[0] = edge_relativistic_pi[k]
    cerenkov_pi[0] = nceren_pi[k]
    scintillation_pi[0] = nscint_pi[k]
    f_out_pi.Fill()

#ncer_pi.SetLineColor(ROOT.kRed)
ncer_pi.Fit("gaus")
ncer_pi.Draw()
nscint_pi_hist.Fit("gaus")
#nscint_pi_hist.SetLineColor(ROOT.kBlue)
nscint_pi_hist.Draw("SAME")
canvas.SaveAs(detector_geo+"_pi-_"+beam_energy+"GeV.pdf")
print("Created histogram for pion- beam")
f_out_pi.Write()
f2.Write()
f2.Close()
