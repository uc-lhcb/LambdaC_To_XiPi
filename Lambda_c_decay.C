#define Lambda_c_decay_cxx
// The class definition in Lambda_c_decay.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("Lambda_c_decay.C")
// root> T->Process("Lambda_c_decay.C","some options")
// root> T->Process("Lambda_c_decay.C+")
//

TH1 * LambdaOriginal = nullptr;
TH1 * BackgroundSubCutLambdaCMass = nullptr;


TCanvas *c1 = new TCanvas("Histograms of LambdaC Mass", "", 1000, 500);
const int TRACK_LONG = 3;
const int TRACK_DOWN = 5;

#include "fit2MeV_Gaussian.C"
#include "Lambda_c_decay.h"
#include <TH2.h>
#include <TStyle.h>

void Lambda_c_decay::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

c1->Divide(2,1);

	LambdaOriginal = new TH1D ("Mass [MeV]", "Mass of LambdaC", 100, 2185, 2385);
	BackgroundSubCutLambdaCMass = new TH1D ("Mass [MeV]", "Mass of Background Subtracted LambdaC", 100, 2185, 2385);
	
}

void Lambda_c_decay::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t Lambda_c_decay::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetEntry(entry);
GetEntry(entry);

///////////////
//Definitions//
///////////////

//Conservation of Transverse Momentum in LambdaC Decay 
double LambdaCTransverse = ((*Lambda_cplus_PT) - (*PromptK_PT) - (*PromptPi_PT) - (*PromptXi_PT));

//Conservation of Momentum in Z direction of LambdaC Decay
double MomentumZ = ((*Lambda_cplus_PZ) - (*PromptK_PZ) - (*PromptPi_PZ) - (*PromptXi_PZ));

//Corrected Xi Mass
double CorrectedXiMass = ((*PromptXi_MM) - (*Lambda_MM) + 1115.683);

double LambdaC_PT = *Lambda_cplus_PT;

/////////////////////////////////////
//Histogram with Uncut LambdaC mass//
/////////////////////////////////////

LambdaOriginal->Fill(*Lambda_cplus_MM);

////////////////////////
//Cuts Based on Masses//
////////////////////////

	bool MassCuts = (
		(*Lambda_cplus_MM > 2185. && *Lambda_cplus_MM < 2385.)
	&&	(CorrectedXiMass > 1310. && CorrectedXiMass < 1330.)
);

////////////////////////////////////////////////////////////////////////
//Cut Based On Background Subtractions with LambdaC Mass Signal Region//
////////////////////////////////////////////////////////////////////////

///////////////////////////
//July 21, 2016 - MagDown//
///////////////////////////

//No Track Seperation// - GOOD CUT

	bool GoodBSubJuly21 = (
		(LambdaCTransverse > -200. && LambdaCTransverse < 200.)
	&&	(*PromptK_IPCHI2_OWNPV > 9.)
	&&	(*PromptPi_IPCHI2_OWNPV > 9.)
	&&	(*PromptK_ProbNNk < 0.2 | *PromptK_ProbNNk > 0.6)
	&&	(*PromptPi_ProbNNpi > 0.4)
);

//Long-Long Track Seperation//

	bool GoodLLBSubJuly21 = (
		(*LambdaPr_TRACK_Type == TRACK_LONG)
	&& 	(*LambdaPi_TRACK_Type == TRACK_LONG)
);

//Down-Down Track Seperation///

	bool GoodDDBSubJuly21 = (
		(*LambdaPr_TRACK_Type == TRACK_DOWN)
	&& 	(*LambdaPi_TRACK_Type == TRACK_DOWN)
);

///////////////////////////
//July 26, 2016 - MagDown//
///////////////////////////

//No Track Seperation// - GOOD CUT

	bool GoodBSubJuly26 = (
		(LambdaCTransverse > -100 && LambdaCTransverse < 100.)
	&&	(*PromptK_IPCHI2_OWNPV > 9.)
	&&	(*PromptPi_IPCHI2_OWNPV > 9.)
	&&	(*PromptK_ProbNNk > 0.6)
	&&	(*PromptPi_ProbNNpi > 0.3)
	&&	(*Lambda_cplus_PT > 500.)
);

//Long-Long Track Seperation//

	bool GoodLLBSubJuly26 = (
		(*LambdaPr_TRACK_Type == TRACK_LONG)
	&& 	(*LambdaPi_TRACK_Type == TRACK_LONG)
);

//Down-Down Track Seperation///

	bool GoodDDBSubJuly26 = (
		(*LambdaPr_TRACK_Type == TRACK_DOWN)
	&& 	(*LambdaPi_TRACK_Type == TRACK_DOWN)
);
	
///////////////////////////
//July 31, 2016 - MagDown//
///////////////////////////

//WEAK SIGNAL//

//No Track Seperation//

	bool GoodBSubJuly31 = (
		(LambdaCTransverse > -200. && LambdaCTransverse < 200.)
	&&	(*PromptK_ProbNNk > 0.3)
	&&	(*PromptPi_ProbNNpi > 0.3)
);

//Long-Long Track Seperation//

	bool GoodLLBSubJuly31 = (
		(*LambdaPr_TRACK_Type == TRACK_LONG)
	&& 	(*LambdaPi_TRACK_Type == TRACK_LONG)
);

//Down-Down Track Seperation///

	bool GoodDDBSubJuly31 = (
		(*LambdaPr_TRACK_Type == TRACK_DOWN)
	&& 	(*LambdaPi_TRACK_Type == TRACK_DOWN)
);

////////////////////////////
//August 2, 2016 - MagDown//
////////////////////////////

//WEAK SIGNAL//

//No Track Seperation//
	bool GoodBSubAugust2 = (
		(LambdaCTransverse > -200. && LambdaCTransverse < 200.)
	&&	(*PromptK_ProbNNk > 0.3)
	&&	(*PromptPi_ProbNNpi > 0.3)
);

//Long-Long Track Seperation//
///Low Amount of Data//
	bool GoodLLBSubAugust2 = (
		(*LambdaPr_TRACK_Type == TRACK_LONG)
	&& 	(*LambdaPi_TRACK_Type == TRACK_LONG)
);

//Down-Down Track Seperation///

	bool GoodDDBSubAugust2 = (
		(*LambdaPr_TRACK_Type == TRACK_DOWN)
	&& 	(*LambdaPi_TRACK_Type == TRACK_DOWN)
	&&	(*PromptK_IPCHI2_OWNPV > 3.)
	&&	(*PromptPi_IPCHI2_OWNPV > 3.)
	&&	(*PromptPi_ProbNNpi > 0.3)
	&&	(*PromptK_ProbNNk < 0.3 | *PromptK_ProbNNk > 0.7)
	&&	(LambdaCTransverse > -250. && LambdaCTransverse < 250.)
);

//////////////////////////////
//August 2, 2016 - MagDown#2//
//////////////////////////////

//No Track Seperation// - WORK IN PROGRESS
	bool GoodBSubAugust2_2 = (
		(LambdaCTransverse > -150 && LambdaCTransverse < 150.)
	&&	(*PromptK_IPCHI2_OWNPV > 4.)
	&&	(*PromptPi_IPCHI2_OWNPV > 4.)
	&&	(*PromptPi_ProbNNpi > 0.4)
	&&	(*Lambda_cplus_PT > 1750.)
	&&	(*Lambda_cplus_TAU < 0.0025)
	&&	(*PromptK_ProbNNk < 0.2 | *PromptK_ProbNNk > 0.6)
);

//Long-Long Track Seperation//

	bool GoodLLBSubAugust2_2 = (
		(*LambdaPr_TRACK_Type == TRACK_LONG)
	&& 	(*LambdaPi_TRACK_Type == TRACK_LONG)
);

//Down-Down Track Seperation// - WORK IN PROGRESS

	bool GoodDDBSubAugust2_2 = (
		(*LambdaPr_TRACK_Type == TRACK_DOWN)
	&& 	(*LambdaPi_TRACK_Type == TRACK_DOWN)
	&&	(LambdaCTransverse > -150 && LambdaCTransverse < 150.)
	&&	(*PromptK_IPCHI2_OWNPV > 4.)
	&&	(*PromptPi_IPCHI2_OWNPV > 4.)
	&&	(*Lambda_cplus_PT > 2000.)
);

/////////////////////////////
//August 15, 2016 - MagDown//
/////////////////////////////

//No Track Seperation// - WORK IN PROGRESS
	bool GoodBSubAugust15 = (
		(LambdaCTransverse > -200 && LambdaCTransverse < 200.)
	&&	(*PromptK_IPCHI2_OWNPV > 9.)
	&&	(*PromptPi_IPCHI2_OWNPV > 9.)
);

//Long-Long Track Seperation//

	bool GoodLLBSubAugust15 = (
		(*LambdaPr_TRACK_Type == TRACK_LONG)
	&& 	(*LambdaPi_TRACK_Type == TRACK_LONG)
);

//Down-Down Track Seperation///

	bool GoodDDBSubAugust15 = (
		(*LambdaPr_TRACK_Type == TRACK_DOWN)
	&& 	(*LambdaPi_TRACK_Type == TRACK_DOWN)
);


////////////////////////////////
//Fill Histogram with Cut Data//
////////////////////////////////

	if (GoodBSubJuly21 && MassCuts)
		BackgroundSubCutLambdaCMass->Fill(*Lambda_cplus_MM);
 
  return kTRUE;
}

void Lambda_c_decay::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void Lambda_c_decay::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
    Double_t sigma;
    Double_t deltaSigma;
    Double_t mu;
    Double_t deltaMu;
    Double_t total;
    Double_t deltaTotal;
    TString sigmaStr;
    TString deltaSigmaStr;
    TString muStr;
    TString deltaMuStr;
    TString totalStr;
    TString deltaTotalStr;
TF1 *myLambdaFit = new TF1("myLambdaFit",fit2MeV_Gaussian,2100.,2500.,5);
myLambdaFit->SetParameter(0,400.);
myLambdaFit->SetParameter(1,2286);
myLambdaFit->SetParameter(2, 6);
myLambdaFit->SetParLimits(2, 0.,20.);
myLambdaFit->SetParameter(3, 0.);
myLambdaFit->SetParameter(4, 0.);

c1->cd(1);
LambdaOriginal->GetXaxis()->SetTitle("MeV");
LambdaOriginal->GetYaxis()->SetTitle("Events Per 2 MeV");
LambdaOriginal->Draw();
c1->cd(2);
BackgroundSubCutLambdaCMass->GetXaxis()->SetTitle("MeV");
BackgroundSubCutLambdaCMass->GetYaxis()->SetTitle("Events Per 2 MeV");
BackgroundSubCutLambdaCMass->Fit("myLambdaFit");

}
