#define BackgroundSubTemplate_cxx
// The class definition in BackgroundSubTemplate.h has been generated automatically
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
// root> T->Process("BackgroundSubTemplate.C")
// root> T->Process("BackgroundSubTemplate.C","some options")
// root> T->Process("BackgroundSubTemplate.C+")
//


#include "BackgroundSubTemplate.h"
#include <TH2.h>
#include <TStyle.h>
TH1 *Variable = nullptr;
TH1 *Signal = nullptr;
TH1 *Lower = nullptr;
TH1 *Upper = nullptr;
TH1 *bkgd = nullptr;
TH1 *BSVariable = nullptr;
TCanvas *c1 = new TCanvas("Background Subtraction","Histograms",1000,500);
THStack *hs = new THStack("hs","Background Subtracted Lambda_M on LambdaC Endvertex");
double UB = 0.1;
double LB = 0.;
const int Bin = 50;
void BackgroundSubTemplate::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void BackgroundSubTemplate::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
TH1::SetDefaultSumw2(kTRUE);
Variable = new TH1D("Variable", "Endvertex of LambdaC", Bin, LB, UB);
Signal = new TH1D("Variable", " Endvertex of LambdaC- Signal", Bin, LB, UB);
Lower = new TH1D("Variable", "Endvertex of LambdaC", Bin, LB, UB);
Upper = new TH1D("Variable", "Endvetex of LambdaC", Bin, LB, UB);
bkgd = new TH1D("Variable", "Endvertex of LambdaC - Background", Bin, LB, UB);
BSVariable = new TH1D("Variable", "Subtracted Endvertex of LambdaC", Bin, LB, UB);
Signal->SetLineColor(kBlue);
bkgd->SetLineColor(kRed);
BSVariable->SetLineColor(kGreen+3);
}

Bool_t BackgroundSubTemplate::Process(Long64_t entry)
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

double VariableCut = *PromptK_ProbNNk;

bool SignalRegion = *Lambda_cplus_MM > 2261. && *Lambda_cplus_MM < 2311.; 
bool LowerSideband = *Lambda_cplus_MM > 2185. && *Lambda_cplus_MM < 2210.;
bool UpperSideband = *Lambda_cplus_MM > 2360. && *Lambda_cplus_MM < 2385.;

	if (SignalRegion)
	    Signal->Fill(VariableCut);
	if (LowerSideband)
            Lower->Fill(VariableCut);
	if (UpperSideband)
	    Upper->Fill(VariableCut);

bkgd->Add(Upper,Lower,1.,1.);
BSVariable->Add(Signal,bkgd,1.0,-1.0);

   return kTRUE;
}

void BackgroundSubTemplate::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void BackgroundSubTemplate::Terminate()
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
