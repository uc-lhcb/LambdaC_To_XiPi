#define BackgroundSubtraction_cxx
// The class definition in BackgroundSubtraction.h has been generated automatically
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
// root> T->Process("BackgroundSubtraction.C")
// root> T->Process("BackgroundSubtraction.C","some options")
// root> T->Process("BackgroundSubtraction.C+")
//


#include "BackgroundSubtraction.h"
#include <TH2.h>
#include <TStyle.h>

TH1 *Variable = nullptr;
TH1 *Signal = nullptr;
TH1 *Lower = nullptr;
TH1 *Upper = nullptr;
TH1 *bkgd = nullptr;
TH1 *BSVariable = nullptr;
TCanvas *c1 = new TCanvas("Background Subtraction","Histograms",1000,500);
THStack *hs = new THStack("hs","Background Subtraction on Lambda Mass");
double UB = 0.5;
double LB = 0.;
const int Bin = 10;

void BackgroundSubtraction::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void BackgroundSubtraction::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
   TH1::SetDefaultSumw2(kTRUE);
   Variable = new TH1D("Variable", "Lambda Mass", Bin, LB, UB);
   Signal = new TH1D("Variable", " Lambda Mass - Signal", Bin, LB, UB);
   Lower = new TH1D("Variable", "Lambda Mass", Bin, LB, UB);
   Upper = new TH1D("Variable", "Lambda Mass", Bin, LB, UB);
   bkgd = new TH1D("Variable", "Lambda Mass - Background", Bin, LB, UB);
   BSVariable = new TH1D("Variable", "Subtracted Lambda Mass", Bin, LB, UB);
   Signal->SetLineColor(kBlue);
   bkgd->SetLineColor(kRed);
   BSVariable->SetLineColor(kGreen+3);
}

Bool_t BackgroundSubtraction::Process(Long64_t entry)
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

   double VariableCut = *XiPi_ProbNNpi;

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

   bool SignalRegion = CorrectedLambdaMass > 2270. && CorrectedLambdaMass < 2306.;
   bool LowerSideband = CorrectedLambdaMass > 2185. && CorrectedLambdaMass < 2203.;
   bool UpperSideband = CorrectedLambdaMass > 2367. && CorrectedLambdaMass < 2385.;

   	if (SignalRegion && MassCutsOdd && OddNoMomentumCut)
   	    Signal->Fill(VariableCut);
   	if (LowerSideband && MassCutsOdd && OddNoMomentumCut)
        Lower->Fill(VariableCut);
   	if (UpperSideband && MassCutsOdd && OddNoMomentumCut)
   	    Upper->Fill(VariableCut);

   bkgd->Add(Upper,Lower,1.,1.);
   BSVariable->Add(Signal,bkgd,1.0,-1.0);

   return kTRUE;
}

void BackgroundSubtraction::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void BackgroundSubtraction::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
   hs->Add(Signal);
   hs->Add(bkgd);
   hs->Add(BSVariable);
   BSVariable->GetPainter()->PaintStat(1,0);
   hs->Draw("nostack");
   hs->GetYaxis()->SetTitle("Events");
   c1->Modified();
   gPad->BuildLegend(0.78,0.5,0.98,0.75);
}
