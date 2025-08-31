import ROOT

def load_dd4hep_libraries():
    for lib in [
        "libDDCore",
        "libDDG4",
        "libDualTestBeam",
        "libDDG4IO",  # Optional, if used
    ]:
        if ROOT.gSystem.Load(lib) < 0:
            print(f"Warning: Failed to load {lib}")

