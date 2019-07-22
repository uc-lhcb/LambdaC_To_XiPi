#define UpdatedFigure2017_cxx
#include "UpdatedFigure2017.h"

#include <TH1D.h>
#include <TH2D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TF1.h>

#include "fit2MeV_Gaussian.C"

using namespace std;

#include <vector>
#include <algorithm>
#include <functional>
#include <chrono>
#include <thread>
#include <array>

std::array<std::array<TH1D*, 20>, 20> hists;
std::array<std::array<double, 20>, 20> fom;

TH2D * Figure = nullptr;
TFile * File = nullptr;
TCanvas * c1 = nullptr;

void UpdatedFigure2017::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void UpdatedFigure2017::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();

      for (double i = 0; i < 20; i++){
        for (double j = 0; j < 20; j++){

          hists[i][j] = new TH1D(TString::Format("hist_%f_%f", i, j), "Histograms", 100, 2185, 2385);
          hists[i][j]->GetXaxis()->SetTitle("Mass [MeV]");
          hists[i][j]->GetYaxis()->SetTitle("Events per 2 MeV");
   }}

   Figure = new TH2D("Figures of Merit", "Biased Multivariate Cut", 20, 0., 20., 20, 0., 1.);
   Figure->GetXaxis()->SetTitle("PromptPi Chi2");
   Figure->GetYaxis()->SetTitle("PromptPi_ProbNNpi");
   Figure->GetZaxis()->SetTitle("Signal Events / Signal Error");

   File = new TFile("NoMomentumPion.root", "RECREATE");
  gFile = File;

   c1 = new TCanvas("canvas", "Test Canvas");
}

Bool_t UpdatedFigure2017::Process(Long64_t entry)
{
  GetEntry(entry);
   fReader.SetEntry(entry);

//Conservation of Transverse Momentum in LambdaC Decay
double LambdaCTransverse = ((*Lambda_cplus_PT) - (*PromptK_PT) - (*PromptPi_PT) - (*Xi_PT));

//Corrected Xi Mass
double CorrectedXiMass = ((*Xi_MM) - (*Lambda_MM) + 1115.683);

//Corrected Lambda Mass
double CorrectedLambdaMass = ((*Lambda_cplus_MM) - (*Xi_MM) + (1321.71));

	bool MassCuts = (
		(*Lambda_cplus_MM > 2185. && *Lambda_cplus_MM < 2385.)
	&&	(CorrectedXiMass > 1310. && CorrectedXiMass < 1330.)
);

bool PrecisionCut = (
//      (LambdaCTransverse > -200. && LambdaCTransverse < 200.)
   (*PromptK_IPCHI2_OWNPV > 9.)
//	(*PromptPi_IPCHI2_OWNPV > 9.)
 &&	(*PromptK_ProbNNk > 0.4)
// &&	(*PromptPi_ProbNNpi > 0.4)
&&	(*Lambda_cplus_PT > 2000.)
);

  bool EvenPrecisionCut = (
    		(LambdaCTransverse > -200. && LambdaCTransverse < 200.)
// 	&&  (*PromptK_IPCHI2_OWNPV > 9.)
	&&	(*PromptPi_IPCHI2_OWNPV > 9.)
//	&&	(*PromptK_ProbNNk > 0.4)
	&&	(*PromptPi_ProbNNpi > 0.4)
 	&&	(*Lambda_cplus_PT > 2000.)
);

bool OddPrecisionCut = (
      (LambdaCTransverse > -200. && LambdaCTransverse < 200.)
  &&  	(*PromptK_IPCHI2_OWNPV > 8.)
//  &&	(*PromptPi_IPCHI2_OWNPV > 6.)
  &&	(*PromptK_ProbNNk > 0.7)
//  &&	(*PromptPi_ProbNNpi > 0.5)
&&	(*Lambda_cplus_PT > 2000.)
);

//even number = (*eventNumber % 2 == 0)
//odd number = (*eventNumber % 2 == 1)

   for (double i = 0; i < 20; i++){
     for (double j = 0; j < 20; j++){

       if (((*PromptPi_IPCHI2_OWNPV) >= i) && ((*PromptPi_ProbNNpi) >= j/20) && MassCuts && PrecisionCut){

         hists[i][j]->Fill(CorrectedLambdaMass);}}}

   return kTRUE;
}

void UpdatedFigure2017::SlaveTerminate()
{

}

void UpdatedFigure2017::Terminate()
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

 for (double i = 0; i < 20; i++){
   for (double j = 0; j < 20; j++){

     hists[i][j]->Fit("myLambdaFit", "Q");
     fom[i][j] = (myLambdaFit->GetParameter(0)/myLambdaFit->GetParError(0));

std::cout <<fom[i][j]<<" Signal:"<<myLambdaFit->GetParameter(0)<<" Error:"<<myLambdaFit->GetParError(0)<<" i="<<i<<" j="<<j<<" Fit Error:"<<myLambdaFit->GetParError(1)<< endl;
      hists[i][j]->Write();

     Figure->Fill(i, j/20, fom[i][j]);
}}

Figure->Draw("COLZ");
 c1->Write();
 File->Close();

}
