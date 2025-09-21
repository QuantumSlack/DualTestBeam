import ROOT
from pyroot_setup import load_dd4hep_libraries
from collections import Counter
from particle import Particle
import pandas as pd
import argparse
load_dd4hep_libraries()

neutron_pdgID = 2112
photon_pdgID = 22

def return_times(tree, time_db):
    for event in tree:
        for particle in event.MCParticles:
            ### record the time for neutrons
            print("Reason:- ", particle.reason)
            print("Status:- ", particle.status)
            print("genStatus:- ", particle.genStatus)
            if particle and particle.pdgID == photon_pdgID:
                print("Process = ", particle.photonProcess)
            if particle and particle.pdgID == neutron_pdgID:
                time_db.append(round(particle.time,3))

argparser = argparse.ArgumentParser()
argparser.add_argument("-g", "--geometry")
argparser.add_argument("-E", "--energy")
argparser.add_argument("-p", "--particle")
arg_parse = argparser.parse_args()
geo = arg_parse.geometry
beamEnergy = arg_parse.energy
beamParticle = arg_parse.particle
fileName = "out_"+geo+"_"+beamEnergy+"GeV_"+beamParticle+".root"
file = ROOT.TFile.Open("out_FSCEPonly_10GeV_e-.root")
tree = file.Get("EVENT")
data = []
time_db = []
return_times(tree, time_db)
counts = Counter(time_db)
#print(counts)
for keys in counts:
    data.append({
        "time": keys,
        "counts": counts[keys]
    })
df = pd.DataFrame(data)
### contains the number of neutrons deposited at an instance of time
df_sorted = df.sort_values(by="time", ascending=True)

### plot a histogram for this counts 

neutron_hist = ROOT.TH1F("hist_time", "Neutron Arrival Times for "+beamEnergy+" GeV "+beamParticle+" beam; Time; Counts", 100, 0, 100)

for _, rows in df_sorted.iterrows():
    neutron_hist.Fill(rows["time"], rows["counts"])
canvas = ROOT.TCanvas("canvas", "Neutron Times", 800, 600)
neutron_hist.Draw()
canvas.Draw()

canvas.SaveAs("neutron_time_hist"+beamEnergy+"_"+beamParticle+".pdf")
