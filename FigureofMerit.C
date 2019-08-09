#define FigureofMerit_cxx
#include "FigureofMerit.h"

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

std::array<std::array<TH1D*, 9>, 9> hists;
std::array<std::array<TH1D*, 9>, 9> BackgroundR;
std::array<std::array<TH1D*, 9>, 9> SignalR;
std::array<std::array<double, 9>, 9> fom;

TH2D * Figure = nullptr;
TFile * File = nullptr;
TCanvas * c1 = nullptr;
TH1D * AddedHistogram = nullptr;

void FigureofMerit::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void FigureofMerit::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();

            for (int i = 0; i < 9; i++){
              for (int j = 0; j < 9; j++){

                hists[i][j] = new TH1D(TString::Format("Mass[MeV]_%d_%d", i, j), "LambdaC Mass - Odd Data", 100, 2185, 2385);
                hists[i][j]->GetXaxis()->SetTitle("Mass [MeV]");
                hists[i][j]->GetYaxis()->SetTitle("Events per 2 MeV");
                BackgroundR[i][j] = new TH1D(TString::Format("Mass[MeV]_%d_%d", i, j), "LambdaC Mass - Odd Data", 100, 2185, 2385);
                SignalR[i][j] = new TH1D(TString::Format("Mass[MeV]_%d_%d", i, j), "LambdaC Mass - Odd Data", 100, 2185, 2385);
         }}

         Figure = new TH2D("Figures of Merit", "Color Plot of LambdaC Mass - Odd Data", 9, 0.5, 3.2, 9, 0.1, 1.);
         Figure->GetXaxis()->SetTitle("Log(PromptK Chi2)");
         Figure->GetYaxis()->SetTitle("PromptK_ProbNNk");
         Figure->GetZaxis()->SetTitle("Signal Events / Background Events");

         AddedHistogram = new TH1D("Mass [MeV]", "LambdaC Mass of Passing Boxes", 100, 2185, 2385);
         AddedHistogram->GetXaxis()->SetTitle("Mass [MeV]");
         AddedHistogram->GetYaxis()->SetTitle("Events Per 2 MeV");

         File = new TFile("SignalDTotalKaon.root", "RECREATE");
        gFile = File;

         c1 = new TCanvas("canvas", "Test Canvas");
}

Bool_t FigureofMerit::Process(Long64_t entry)
{
  GetEntry(entry);
   fReader.SetEntry(entry);

//Corrected Xi Mass
double CorrectedXiMass = ((*Xi_MM) - (*Lambda_MM) + 1115.683);

//Corrected Lambda Mass
double CorrectedLambdaMass = ((*Lambda_cplus_MM) - (*Xi_MM) + (1321.71));

double EvenNumber = (*eventNumber % 2 == 0);

double OddNumber = (*eventNumber % 2 == 1);

  bool MassCuts = (
    (*Lambda_cplus_MM > 2185. && *Lambda_cplus_MM < 2385.)
  &&	(CorrectedXiMass > 1310. && CorrectedXiMass < 1330.)
);

bool MultivariateCut = (
    (*Lambda_cplus_PT > 2000.)
//&&  (*PromptK_IPCHI2_OWNPV > 8.)
//&&	(*PromptK_MC15TuneV1_ProbNNk > 0.7)
&&  (*PromptPi_IPCHI2_OWNPV > 6.)
&&	(*PromptPi_MC15TuneV1_ProbNNpi > 0.7)
);

bool KaonMutuallyExclusive = (
    (TMath::Log10(*PromptK_IPCHI2_OWNPV) > 1.1 && TMath::Log10(*PromptK_IPCHI2_OWNPV) < 3.2  && *PromptK_MC15TuneV1_ProbNNk > 0.9)
||  (TMath::Log10(*PromptK_IPCHI2_OWNPV) > 1.4 && TMath::Log10(*PromptK_IPCHI2_OWNPV) < 2. && *PromptK_MC15TuneV1_ProbNNk > 0.8 && *PromptK_MC15TuneV1_ProbNNk < 0.9)
||  (TMath::Log10(*PromptK_IPCHI2_OWNPV) > 2.9 && TMath::Log10(*PromptK_IPCHI2_OWNPV) < 3.2 && *PromptK_MC15TuneV1_ProbNNk > 0.8 && *PromptK_MC15TuneV1_ProbNNk < 0.9)
||  (TMath::Log10(*PromptK_IPCHI2_OWNPV) > 2.3 && TMath::Log10(*PromptK_IPCHI2_OWNPV) < 2.6 && *PromptK_MC15TuneV1_ProbNNk > 0.7 && *PromptK_MC15TuneV1_ProbNNk < 0.8)
);

bool PionMutuallyExclusive = (
        (TMath::Log10(*PromptPi_IPCHI2_OWNPV) > 0.8 && TMath::Log10(*PromptPi_IPCHI2_OWNPV) < 2.9 && *PromptPi_ProbNNpi > 0.9)
||      (TMath::Log10(*PromptPi_IPCHI2_OWNPV) > 1.1 && TMath::Log10(*PromptPi_IPCHI2_OWNPV) < 2.9 && *PromptPi_ProbNNpi > 0.8 && *PromptPi_ProbNNpi < 0.9)
||      (TMath::Log10(*PromptPi_IPCHI2_OWNPV) > 1.4 && TMath::Log10(*PromptPi_IPCHI2_OWNPV) < 2.0 && *PromptPi_ProbNNpi > 0.6 && *PromptPi_ProbNNpi < 0.8)
);

   for (int i = 0; i < 9; i++){
     for (int j = 0; j < 9; j++){

       bool SignalRegion = CorrectedLambdaMass > 2274. && CorrectedLambdaMass < 2300.;
       bool BackgroundRegion = (CorrectedLambdaMass > 2185. && CorrectedLambdaMass < 2211.) || (CorrectedLambdaMass > 2359. && CorrectedLambdaMass < 2385.);

       double x = Figure->GetXaxis()->GetBinLowEdge(i + 1);
       double xx = Figure->GetXaxis()->GetBinLowEdge(i + 2);
    	 double y = Figure->GetYaxis()->GetBinLowEdge(j + 1);
    	 double yy = Figure->GetYaxis()->GetBinLowEdge(j + 2);

       if ((TMath::Log10(*PromptK_IPCHI2_OWNPV) > x) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < xx) && ((*PromptK_MC15TuneV1_ProbNNk) > y) && ((*PromptK_MC15TuneV1_ProbNNk) < yy) && MassCuts && MultivariateCut && SignalRegion && OddNumber){
         SignalR[i][j]->Fill(CorrectedLambdaMass);}

         if ((TMath::Log10(*PromptK_IPCHI2_OWNPV) > x) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < xx) && ((*PromptK_MC15TuneV1_ProbNNk) > y) && ((*PromptK_MC15TuneV1_ProbNNk) < yy) && MassCuts && MultivariateCut && BackgroundRegion && OddNumber){
           BackgroundR[i][j]->Fill(CorrectedLambdaMass);}

       if ((TMath::Log10(*PromptK_IPCHI2_OWNPV) > x) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < xx) && ((*PromptK_MC15TuneV1_ProbNNk) > y) && ((*PromptK_MC15TuneV1_ProbNNk) < yy) && MassCuts && MultivariateCut && OddNumber){
         hists[i][j]->Fill(CorrectedLambdaMass);}}}

   return kTRUE;
}

void FigureofMerit::SlaveTerminate()
{
}

void FigureofMerit::Terminate()
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
myLambdaFit->SetParLimits(2, 0.,10.);
myLambdaFit->SetParameter(3, 0.);
myLambdaFit->SetParameter(4, 0.);

 for (double i = 0; i < 9; i++){
   for (double j = 0; j < 9; j++){

     double x = Figure->GetXaxis()->GetBinLowEdge(i + 1);
     double y = Figure->GetYaxis()->GetBinLowEdge(j + 1);

double  Signal = (SignalR[i][j]->GetEntries() - round(BackgroundR[i][j]->GetEntries()/2));
double  Background = (hists[i][j]->GetEntries() - Signal);

     fom[i][j] = (Signal / Background);
//      fom[i][j] = (Signal / TMath::Sqrt(hists[i][j]->GetEntries()));

std::cout <<fom[i][j]<<" Signal Events:"<<Signal<<" Background Events:"<<Background<<" i="<<i<<" j="<<j<< endl;
      hists[i][j]->Write();
      BackgroundR[i][j]->Write();
      SignalR[i][j]->Write();
     Figure->Fill(x, y, fom[i][j]);

     if (fom[i][j] > 0.1)
     AddedHistogram->Add(hists[i][j], 1);
}}

Figure->Draw("COLZ");
 c1->Write();
 AddedHistogram->Fit("myLambdaFit");
 c1->Write();
 File->Close();
}
