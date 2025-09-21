import ROOT
from pyroot_setup import load_dd4hep_libraries
import argparse
from particle import Particle
load_dd4hep_libraries()

neutron_pdgID = 2112

def return_name(parents, particle, pdgDB):
    parents_list = []
    for index in parents:
        parent_particle = particle[index]
        pdg = parent_particle.pdgID
        pinfo= pdgDB.GetParticle(int(pdg))
        if pinfo is not None:
            name = pinfo.GetName()
            parents_list.append(name)
        else: 
            name = f"Unknown(PDG={pdg})"
            parents_list.append(name)
    return parents_list

argparser = argparse.ArgumentParser()
argparser.add_argument("-g", "--geometry")
argparser.add_argument("-E", "--energy")
argparser.add_argument("-p", "--particle")
arg_parse = argparser.parse_args()
geo = arg_parse.geometry
beamEnergy = arg_parse.energy
beamParticle = arg_parse.particle
pdgDB = ROOT.TDatabasePDG.Instance()
fileName = "out_"+geo+"_"+beamEnergy+"GeV_"+beamParticle+".root"
file = ROOT.TFile.Open("out_FSCEPonly_10GeV_e-.root")
tree = file.Get("EVENT")
i = 0
for event in tree:
    for particle in event.MCParticles:
        print("Reason:-", particle.reason, "\n")
        if particle.pdgID == neutron_pdgID:
            print("Particle ", i, " PDG:", particle.pdgID, " Name:", (Particle.from_pdgid(particle.pdgID)).name, " Parents:",return_name(particle.parents, event.MCParticles, pdgDB) , " Daughters:", return_name(particle.daughters, event.MCParticles, pdgDB))
            i +=1
