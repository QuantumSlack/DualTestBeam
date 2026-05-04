/************************************************
Script to check if a ROOT file has been properly
processed
*************************************************/

void check(const char* inputfilename){
  // Configuring global ROOT environment
  gROOT->ProcessLine("gErrorIgnoreLevel = 6001;");        // Sets error reporting level to nothing except fatal errors
  gROOT->ProcessLine("gPrintViaErrorHandler = kTRUE;");   // Redirects print statements through error handler

  // File processing
  TFile *_file0 = TFile::Open(inputfilename);
  TTree* et = (TTree*)_file0->Get("EVENT;1");
  TBranch* b_edge = et->GetBranch("EdgeDetNoSegment");
  TBranch* b_mc = et->GetBranch("MCParticles");
  std::cout << "Entries in MC and Edge:"
	    << b_mc->GetEntries() << " "
	    << b_edge->GetEntries() << std::endl;
  
}

