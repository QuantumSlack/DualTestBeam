import ROOT
import argparse
from pyroot_setup import load_dd4hep_libraries
import os
load_dd4hep_libraries()

argparser = argparse.ArgumentParser()
argparser.add_argument("-g", "--geometry")
argparser.add_argument("-E", "--energy")
argparser.add_argument("-p", "--particle")
args = argparser.parse_args()
geo = args.geometry
beamEnergy = args.energy
beamParticle = args.particle

file_path = "/home/atlas/DD4hep/examples/DualTestBeam/compact/output/FSCEPonly/"
filename = "out_"+geo+"_"+beamEnergy+"GeV_"+beamParticle+".root"

file = ROOT.TFile.Open(os.path.join(file_path, filename))

tree = file.Get("EVENT")
hitScin_arrival_times = []
hitScin_wavelength = []
hitCer_arrival_times = []
hitCer_wavelength = []

for event in tree:
    for hit in event.DRFNoSegment:
        hit_Cer = hit.HitCer
        for pair in hit_Cer:
            hitCer_arrival_times.append(pair.first)
            hitCer_wavelength.append(pair.second)
        hitScin = hit.HitScin
        for pair in hitScin:
            hitScin_arrival_times.append(pair.first)
            hitScin_wavelength.append(pair.second)
if(len(hitScin_arrival_times) == 0 or len(hitCer_arrival_times) == 0):
    arrivaltime_hist_scint = ROOT.TH1F("arrivaltimehist_scintillation", "Energy of Scintillation photons vs Arrival Time for 10GeV pion beam ; t; #lambda", 100, 0, 100)
    arrivaltime_hist_cer = ROOT.TH1F("arrivaltimehist_cerenkov", "Energy of Cerenkov photons vs Arrival Time for 10GeV pion beam ; t; #lambda", 100, 0, 100)
else:
    arrivaltime_hist_scint = ROOT.TH1F("arrivaltimehist_scintillation", "Energy of Scintillation photons vs Arrival Time for 10GeV pion beam ; t; #lambda", int(max(hitScin_arrival_times))+100, 0, max(hitScin_arrival_times)+100)
    arrivaltime_hist_cer = ROOT.TH1F("arrivaltimehist_cerenkov", "Energy of Cerenkov photons vs Arrival Time for 10GeV pion beam ; t; #lambda", int(max(hitCer_arrival_times))+100, 0, max(hitCer_arrival_times)+100)

for index in range(len(hitScin_arrival_times)):
    arrivaltime_hist_scint.Fill(hitScin_arrival_times[index], hitScin_wavelength[index])
canvas = ROOT.TCanvas("Canvas", "Energy vs Arrival Time", 800, 600)
arrivaltime_hist_scint.Draw()
canvas.Draw()
canvas.SaveAs(beamParticle+"_"+beamEnergy+"GeV_scintillation_photonarrival_times.pdf")
print(hitScin_arrival_times)
            
for index in range(len(hitCer_arrival_times)):
    arrivaltime_hist_cer.Fill(hitCer_arrival_times[index], hitCer_wavelength[index])
arrivaltime_hist_cer.Draw()
canvas.Draw()
canvas.SaveAs(beamParticle+"_"+beamEnergy+"GeV_cerenkov_photonarrival_times.pdf")