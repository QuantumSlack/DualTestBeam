import argparse
import ROOT
import math
from pyroot_setup import load_dd4hep_libraries
load_dd4hep_libraries()

def rotate_coordinates(x_0, y_0, x, y, angle):
    if(angle < 0):
        x_n = x_0 + (x-x_0)*math.cos(angle) - (y-y_0)*math.sin(angle)
        y_n = y_0 + (x-x_0)*math.sin(angle) + (y-y_0)*math.cos(angle)
        return x_n, y_n 
    x_n = x_0 + (x-x_0)*math.cos(angle) + (y-y_0)*math.sin(angle)
    y_n = y_0 - (x-x_0)*math.sin(angle) + (y-y_0)*math.cos(angle)
    return x_n, y_n 

arg_parse = argparse.ArgumentParser()
arg_parse.add_argument("-f", "--file")
arg_parse.add_argument("-E", "--energy")
args_parser = arg_parse.parse_args()
beamEnergy = args_parser.energy
fileName = args_parser.file
c = ROOT.TCanvas("c", "Canvas for TH2F", 800, 600)

file = ROOT.TFile.Open(fileName)
hist = file.Get("phcHcalNsNc")

if not hist:
    print("Histogram not found!")
    exit()
else:
    print("Found histogram:", hist.GetName(), "-", hist.GetTitle())

nx = hist.GetNbinsX()
ny = hist.GetNbinsY()
rotated_plot = ROOT.TH2F("rotated", "Rotated histogram", hist.GetNbinsX(), hist.GetXaxis().GetXmin(), hist.GetXaxis().GetXmax(), 
                         hist.GetNbinsY(), hist.GetYaxis().GetXmin(), hist.GetYaxis().GetXmax())
x_0 = 1
y_0 = 1
angle = math.pi / 2 
for i in range(1, nx+1):
    for j in range(1, ny+1):
        xlow  = hist.GetXaxis().GetBinLowEdge(i)
        xhigh = hist.GetXaxis().GetBinUpEdge(i)
        ylow  = hist.GetYaxis().GetBinLowEdge(j)
        yhigh = hist.GetYaxis().GetBinUpEdge(j)
        content = hist.GetBinContent(i, j)
        x = hist.GetXaxis().GetBinCenter(i)
        y = hist.GetYaxis().GetBinCenter(j)
        x_new, y_new = rotate_coordinates(x_0, y_0, x, y, angle)
        rotated_plot.Fill(x_new, y_new, content)
    # print(content, "\t")   
    #print(f"Bin x:[{xlow},{xhigh}), y:[{ylow},{yhigh}) → {content}")
hist.Draw()
c.SaveAs("unrotated_plot.pdf")
rotated_plot.Draw()
c.Update()
c.SaveAs("rotated_plot.pdf")
