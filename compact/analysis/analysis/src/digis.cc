#include "../include/digis.h"

double int_charge(TH1F* out, double pre, double window ) {
  double charge=0;

  if(window<pre) {
    std::cout<<" illegal arguments to int_charge pre window "<<pre<<" "<<window<<std::endl;
  } else {
    //std::cout<<"entering int_charge"<<std::endl;
    int imax=out->GetMaximumBin();
    //std::cout<<" max ibin is "<<imax<<std::endl;
    double amax = out->GetBinLowEdge(imax);
    //std::cout<<"  which is at time "<<amax<<std::endl;
    int ilow=std::max(0,imax-(out->GetBin(amax-pre)));
    int ihigh=std::min(out->GetNbinsX(),out->GetBin(amax+(window-pre)));
    //std::cout<<" integrating from bin "<<ilow<<" to bin "<<ihigh<<std::endl;

    charge=0;
    for(int i=ilow;i<ihigh;i++ ) {
      charge+=out->GetBinContent(i);
    }
  }
  //std::cout<<" charge is "<<charge<<std::endl;
  return charge;
}



  // take histogram of true arrival times at photodetector and produce output signal
void Elec_Sim(TH1F* In, TH1F* Out) {
  int nbin = In->GetNbinsX();
  //  std::cout<<std::endl<<"elec_sim input nbin is "<<nbin<<std::endl;
  double amin = In->GetBinLowEdge(1);
  double amax = In->GetBinLowEdge(nbin)+In->GetBinWidth(nbin);
  double awidth=(amax-amin)/nbin;
  //  std::cout<<"  In min max awidth are "<<amin<<" "<<amax<<" "<<awidth<<std::endl;
  for (int i=0;i<nbin;i++) {  // for each bin in pe creation time
    int npe=In->GetBinContent(i);
    if(npe>0) {
      for ( int j=0;j<npe;j++) {  // for each pe in that bin
	for (int k=0;k<finenbin;k++ ) {   // for each bin in time frame
	  float petime = (amin+(i-0.5)*awidth);
	  float bintime = (timemin+(k-0.5)*timebinsize);
	  float localtime= bintime-petime;
	  float charge=SPR(localtime);
	  if(localtime>0) {
	    //	    std::cout<<"petime k bintime  localtime charge is "<<petime<<" "<<k<<" "<<bintime<<" "<<localtime<<" "<<charge<<std::endl;        
	    Out->Fill(bintime, charge);
	  }
	}
      }
    }
  }
}



// electronics response to a single photoelectron
double SPR(double tNow)
{
        /*
        * This example of SPR corresponds to Calvision TB at FNAL in 2023
        */
  //double tMin_  = 0.0;
  //double tMax_  = 1000.0;

  double tRise       = 0.853;
  double tDecay      = 6.538;
  double tUnderShoot = 101.7;
  //double norm        = 0.111051;


  double a = 1./ tRise;
  double b = 1./ tDecay;
  double A = -a * b / (a - b);
  double B = -A;
  double result = A * exp(-a*tNow) + B * exp(-b*tNow);
    
  double g = 1./ tUnderShoot;
  double Atmp = -A * g / ( a - g);
  double Btmp = -B * g / ( b - g);
  double G = - Atmp - Btmp ;
  A = Atmp;
  B = Btmp;
  result -= A * exp(-a*tNow) + B * exp(-b*tNow) + G * exp(-g*tNow);
    
  return result;

}

// sipm QE versus wavelength
double sipmpde(int isipm, double wavelength) {

double UV_sipm_QE_x[23] = {361.161, 364.766, 379.794, 387.614,
                           396.624, 406.226, 411.617, 426.594, 436.769, 455.931, 477.492,
                           496.061, 517.627, 547.583, 573.349, 598.521, 615.299, 649.46,
                           671.039, 705.202, 755.548, 773.531, 798.108};
double UV_sipm_QE_y[23] = {0.770120854, 0.787348933, 0.879304547,
                           0.942520324, 0.982752141, 1, 0.982752141, 0.942520324, 0.890796527,
                           0.816088771, 0.741381015, 0.683901339, 0.620685563, 0.545977807,
                           0.488498131, 0.448266313, 0.413790375, 0.356330478, 0.32759064,
                           0.275866843, 0.201139308, 0.178155349, 0.149415511};
double RGB_sipm_QE_x[29] = {305.28, 318.47, 334.67, 352.06,
                            370.06, 396.44, 416.23, 443.81, 466.6, 477.39, 491.78, 515.17,
                            529.56, 556.53, 582.91, 610.49, 636.26, 663.24, 684.22, 712.39,
                            738.76, 755.55, 774.73, 795.11, 825.68, 850.26, 874.23, 894.61, 900.61};
double RGB_sipm_QE_y[29] = {0.034678173, 0.144499016, 0.271678829,
                            0.427750492, 0.525998688, 0.635839415, 0.705195761, 0.786124754,
                            0.87860651, 0.907518244, 0.936410093, 0.994213676, 1, 0.97687459,
                            0.942196417, 0.90173192, 0.849714661, 0.78033843, 0.734107494, 0.664731264,
                            0.583802271, 0.520232248, 0.485554075, 0.427750492, 0.364160585, 0.289017916,
                            0.225428009, 0.167624426, 0.144499016};


 double prob=1;
 int j=0;

 
 switch (isipm) {
 case 0:
   j=0;
   while(j<23) {
     if(wavelength<UV_sipm_QE_x[j]) break;
     j++;
   }
   switch (j) {
   case 0:
   case 22:
     prob=0.;
     break;
   default:
     prob=UV_sipm_QE_y[j];
     break;
   }
   break;
 case 1:
   j=0;
   while(j<23) {
     if(wavelength<RGB_sipm_QE_x[j]) break;
     j++;
   }
   switch (j) {
   case 0:
     prob=0.;
     break;
   case 22:
     prob=0.;
     break;
   default:
     prob=RGB_sipm_QE_y[j];
     break;
   }
   break;
 default:
   std::cout<<"   you messed up the input to AFILTER"<<std::endl;
   break;
 }

 
  return prob;
}


// probability a photon ejects a photoelectron and gets through any wavelength filters
double AFILTER(int ifilter, double wavelength) {
  double passprob=1.;
  
  switch (ifilter) {
  case 0:  // no filter
    break;
  case 1:  // ecal entrance sipm scint
    passprob*=sipmpde(0,wavelength);
    break;
  case 2: // ecal entrance sipm cer
    passprob*=sipmpde(0,wavelength);
    break;
  case 3:  // ecal exit sipm scint
    passprob*=sipmpde(0,wavelength);
    break;
  case 4: // ecal exit sipm cer
    passprob*=sipmpde(0,wavelength);
    break;
  default:
    std::cout<<"   you messed up the input to AFILTER"<<std::endl;
    break;
  }
      
  return passprob;
    
}