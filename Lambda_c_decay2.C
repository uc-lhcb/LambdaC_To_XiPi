#define Lambda_c_decay2_cxx
#include "Lambda_c_decay2.h"
#include <TH2.h>
#include <TStyle.h>
#include "fit2MeV_Gaussian.C"

TH1 * Histogram = nullptr;

TCanvas *c1 = new TCanvas("Histograms of LambdaC Mass", "", 750, 500);


void Lambda_c_decay2::Begin(TTree * /*tree*/)
{

   TString option = GetOption();
}

void Lambda_c_decay2::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();

 	Histogram = new TH1D ("Mass [MeV]", "LambdaC Mass", 100, 2185, 2385);
 Histogram->SetLineColor(kBlue);
}

Bool_t Lambda_c_decay2::Process(Long64_t entry)
{

   fReader.SetEntry(entry);

   GetEntry(entry);

   //Corrected Xi Mass
   double CorrectedXiMass = ((*Xi_MM) - (*Lambda_MM) + 1115.683);

   //Corrected Lambda Mass
   double CorrectedLambdaMass = ((*Lambda_cplus_MM) - (*Xi_MM) + (1321.71));



   bool MassCuts = (
      (*Lambda_cplus_MM > 2185. && *Lambda_cplus_MM < 2385.)
     && (CorrectedXiMass > 1316. && CorrectedXiMass < 1328.)
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
  &&  (*Xi_PT > 1250.)
  &&  (*Lambda_PT > 1000.)
 );

 bool OddNoMomentumCut = (
    (*Lambda_cplus_PT > 2000.)
&&  (*PromptK_IPCHI2_OWNPV > 8.)
&&	(*PromptPi_IPCHI2_OWNPV > 6.)
&&	(*PromptK_MC15TuneV1_ProbNNk > 0.7)
&&	(*PromptPi_MC15TuneV1_ProbNNpi > 0.7)
&&  (*Xi_PT > 1250.)
&&  (*Lambda_PT > 1000.)
);

   	if (OddNoMomentumCut && MassCuts)
         Histogram->Fill(CorrectedLambdaMass);

   return kTRUE;
}

void Lambda_c_decay2::SlaveTerminate()
{

}

void Lambda_c_decay2::Terminate()
{
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
Histogram->SetMinimum(0);
Histogram->GetXaxis()->SetTitle("MeV");
Histogram->GetYaxis()->SetTitle("Events Per 2 MeV");
Histogram->Fit("myLambdaFit");
//c1->SaveAs("FinalLambda3.pdf");
}
