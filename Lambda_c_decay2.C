#define Lambda_c_decay2_cxx
// The class definition in Lambda_c_decay2.h has been generated automatically
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
// root> T->Process("Lambda_c_decay2.C")
// root> T->Process("Lambda_c_decay2.C","some options")
// root> T->Process("Lambda_c_decay2.C+")
//


#include "Lambda_c_decay2.h"
#include <TH2.h>
#include <TStyle.h>
#include "fit2MeV_Gaussian.C"

TH1 * Histogram = nullptr;

TCanvas *c1 = new TCanvas("Histograms of LambdaC Mass", "", 750, 500);


void Lambda_c_decay2::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void Lambda_c_decay2::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

 	Histogram = new TH1D ("Mass [MeV]", "LambdaC Mass", 100, 2185, 2385);
 Histogram->SetLineColor(kBlue);
}

Bool_t Lambda_c_decay2::Process(Long64_t entry)
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

   //Corrected Xi Mass
   double CorrectedXiMass = ((*Xi_MM) - (*Lambda_MM) + 1115.683);

   //Corrected Lambda Mass
   double CorrectedLambdaMass = ((*Lambda_cplus_MM) - (*Xi_MM) + (1321.71));

   	bool MassCutsOdd = (
   		 (*Lambda_cplus_MM > 2185. && *Lambda_cplus_MM < 2385.)
    && (*Lambda_MM > 1110. && *Lambda_MM < 1120.)
    && (CorrectedXiMass > 1312. && CorrectedXiMass < 1328.)
   );

   bool MassCutsEven = (
       (*Lambda_cplus_MM > 2185. && *Lambda_cplus_MM < 2385.)
    && (*Lambda_MM > 1110 && *Lambda_MM < 1122.)
    && (CorrectedXiMass > 1312. && CorrectedXiMass < 1326.)
);

     bool PrecisionCut = (
      	(*PromptK_IPCHI2_OWNPV > 9.)
   	&&	(*PromptPi_IPCHI2_OWNPV > 9.)
   	&&	(*PromptK_MC15TuneV1_ProbNNk > 0.4)
   	&&	(*PromptPi_MC15TuneV1_ProbNNpi > 0.4)
  	&&	(*Lambda_cplus_PT > 2000.)
   );

   bool EvenNoMomentumCut = (
    	(*Lambda_cplus_PT > 2000.)
  &&  (*PromptK_IPCHI2_OWNPV > 7.)
  &&	(*PromptPi_IPCHI2_OWNPV > 7.)
  &&	(*PromptK_MC15TuneV1_ProbNNk > 0.7)
  &&	(*PromptPi_MC15TuneV1_ProbNNpi > 0.75)
 );

 bool OddNoMomentumCut = (
    (*Lambda_cplus_PT > 2000.)
&&  (*PromptK_IPCHI2_OWNPV > 8.)
&&	(*PromptPi_IPCHI2_OWNPV > 6.)
&&	(*PromptK_MC15TuneV1_ProbNNk > 0.7)
&&	(*PromptPi_MC15TuneV1_ProbNNpi > 0.7)
);

   	if (OddNoMomentumCut && MassCutsOdd)
         Histogram->Fill(CorrectedLambdaMass);

   return kTRUE;
}

void Lambda_c_decay2::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void Lambda_c_decay2::Terminate()
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
Histogram->GetXaxis()->SetTitle("MeV");
Histogram->GetYaxis()->SetTitle("Events Per 2 MeV");
Histogram->Fit("myLambdaFit");
//c1->SaveAs("FinalLambda3.pdf");
}
