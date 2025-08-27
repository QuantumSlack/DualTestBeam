#include "../include/ecalProcessing.h"

void DecodeEcal(long long int ihitchan, int& idet, int& ix, int& iy, int& islice, int& ilayer, int& wc, int& type) {
  idet = (ihitchan) & 0x07;
  ix = (ihitchan >>3) & 0x3F ;  // is this right?
  if(ix>32) ix=ix-64;
  iy =(ihitchan >>10) & 0x3F ; // is this right?
  if(iy>32) iy=iy-64;
  islice = (ihitchan >>17) & 0x07;
  ilayer = (ihitchan>> 20) & 0x07;
  wc=  (ihitchan>> 23) & 0x07;
  type=0;
  if((ilayer==0)&&(islice==1))  type=1;  //pd
  if((ilayer==0)&&(islice==2))  type=4;  //resin
  if((ilayer==0)&&(islice==3))  type=4;  //cookie
  if((ilayer==0)&&(islice==4))  type=2;  //crystal
  if((ilayer==0)&&(islice==5))  type=3;  //air


  if((ilayer==1)&&(islice==1))  type=2;  //crystal
  if((ilayer==1)&&(islice==2))  type=4;  //cookie
  if((ilayer==1)&&(islice==3))  type=4;  //resin
  if((ilayer==1)&&(islice==4))  type=1;  //pd
  if((ilayer==1)&&(islice==5))  type=3;  //air

  return;
}


void calibrateEcalGendeteThreeAndFour(int gendete, int idet, int type, CalVision::DualCrysCalorimeterHit* &aecalhit) {
    Contributions zxzz = aecalhit->truth;
    if (idet == 5) {
        if(type==2 ) {  // crystal
	      meanscinEcal+=aecalhit->energyDeposit;
	      if(gendete==3) meancerEcal+=aecalhit->edeprelativistic;
	      if(gendete==4) meancerEcal+=aecalhit->energyDeposit;

	      for(size_t j=0;j<zxzz.size(); j++) {
		    if( (zxzz.at(j)).time>biggesttime) biggesttime=(zxzz.at(j)).time;
		    if((zxzz.at(j)).time<timecut) {
		        eecaltimecut+=(zxzz.at(j)).deposit;
		        if(((aecalhit->contribBeta)[j])>betacut) {
                    erelecaltimecut+=(zxzz.at(j)).deposit;
                }
		    }
	      }
        }
    }
}

void calibrateEcalGendeteFive() {
    for (int i=0;i<tfnx;i++ ) {
	  for (int j=0;j<tfny;j++ ) {
	    for (int k=0;k<tfndepth;k++ ) {
	      meanscinEcal+=(timeframe_true_pd1_s[i][j][k]->Integral());
	      meancerEcal+=(timeframe_true_pd1_c[i][j][k]->Integral());
	      meanscinEcal+=(timeframe_true_pd2_s[i][j][k]->Integral());
	      meancerEcal+=(timeframe_true_pd2_c[i][j][k]->Integral());
	    }
	  }
    }
}

void calibrateEcalGendeteSix() {
    for (int i=0;i<tfnx;i++ ) {
	  for (int j=0;j<tfny;j++ ) {
	    for (int k=0;k<tfndepth;k++ ) {
	      meanscinEcal+=int_charge(timeframe_elec_pd1_s[i][j][k],10.,100.);
	      meancerEcal+=int_charge(timeframe_elec_pd1_c[i][j][k],10.,100.);
	      meanscinEcal+=int_charge(timeframe_elec_pd2_s[i][j][k],10.,100.);
	      meancerEcal+=int_charge(timeframe_elec_pd2_c[i][j][k],10.,100.);
	    }
	  }
	}
}

void calibrateEcalGendete(int gendete, CalHits* &ecalhits, int ievt, TBranch* &b_ecal, int index) {
    CalVision::DualCrysCalorimeterHit* aecalhit =ecalhits->at(index);
	  long long int ihitchan=aecalhit->cellID;
	  int idet,ix,iy,islice,ilayer,wc,type;
    DecodeEcal(ihitchan,idet,ix,iy,islice,ilayer,wc,type );
    Contributions zxzz=aecalhit->truth;
    switch(gendete) {
      case 1:
        if (type==2) {
          meancerEcal+=aecalhit->ncerenkov;
	        meanscinEcal+=aecalhit->nscintillator;
        } break;
      case 2:
        if (type==1) {
          meancerEcal+=aecalhit->ncerenkov;
	        meanscinEcal+=aecalhit->nscintillator;
        } break;
        case 3:
        case 4: 
          calibrateEcalGendeteThreeAndFour(gendete, idet, type, aecalhit);
          break;
        default:std::cout << "Wrong option" << std::endl;
          break;
    }
}

void calibrateEcal(int ievt, int gendete, CalHits* &ecalhits, TBranch* &b_ecal){
  switch(gendete) {
    case 1:
    case 2:
    case 3:
    case 4:
      nbyteecal = b_ecal->GetEntry(ievt);
      if(ievt<SCECOUNT) std::cout<<std::endl<<" number of ecal hits is "<<ecalhits->size()<<std::endl;
      for (int i = 0; i < ecalhits->size(); i++) {
        calibrateEcalGendete(gendete, ecalhits, ievt, b_ecal, i);
      }
      break;
    case 5: calibrateEcalGendeteFive(); break;
    case 6: calibrateEcalGendeteSix(); break;
    default: std::cout << "invalid value gendete"<<std::endl;
          break;
      
  }
}