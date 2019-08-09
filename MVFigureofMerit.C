#define MVFigureofMerit_cxx
#include "MVFigureofMerit.h"

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
//Beginning of Change
std::array<std::array<std::array<std::array<TH1D*, 6>, 6>, 6>, 6> hists;
std::array<std::array<std::array<std::array<TH1D*, 6>, 6>, 6>, 6> histstest;
std::array<std::array<std::array<std::array<TH1D*, 6>, 6>, 6>, 6> BackgroundR;
std::array<std::array<std::array<std::array<TH1D*, 6>, 6>, 6>, 6> SignalR;
std::array<std::array<std::array<std::array<double, 6>, 6>, 6>, 6> fom;

TFile * File = nullptr;
TCanvas * c1 = nullptr;
TH1D * AddedHistogram = nullptr;

void MVFigureofMerit::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void MVFigureofMerit::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();

               for (int i = 0; i < 6; i++){
                 for (int j = 0; j < 6; j++){
                   for (int k = 0; k < 6; k++){
                     for (int l = 0; l < 6; l++){
                   hists[i][j][k][l] = new TH1D(TString::Format("Mass[MeV]_%d_%d_%d_%d", i, j, k, l), "LambdaC Mass - Odd Data", 100, 2185, 2385);
                   hists[i][j][k][l]->GetXaxis()->SetTitle("Mass [MeV]");
                   hists[i][j][k][l]->GetYaxis()->SetTitle("Events per 2 MeV");
                   BackgroundR[i][j][k][l] = new TH1D(TString::Format("Mass[MeV]_%d_%d_%d_%d", i, j, k, l), "LambdaC Mass - Odd Data", 100, 2185, 2385);
                   histstest[i][j][k][l] = new TH1D(TString::Format("Mass[MeV]_%d_%d_%d_%d", i, j, k, l), "LambdaC Mass - Odd Data", 100, 2185, 2385);
                   SignalR[i][j][k][l] = new TH1D(TString::Format("Mass[MeV]_%d_%d_%d_%d", i, j, k, l), "LambdaC Mass - Odd Data", 100, 2185, 2385);
            }}}}

            AddedHistogram = new TH1D("Mass [MeV]", "LambdaC Mass of Passing Boxes", 100, 2185, 2385);
            AddedHistogram->GetXaxis()->SetTitle("Mass [MeV]");
            AddedHistogram->GetYaxis()->SetTitle("Events Per 2 MeV");

            File = new TFile("MVFigure.root", "RECREATE");
           gFile = File;

            c1 = new TCanvas("canvas", "Test Canvas");
   }

Bool_t MVFigureofMerit::Process(Long64_t entry)
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
   );

   for (int i = 0; i < 6; i++){
     for (int j = 0; j < 6; j++){
       for (int k = 0; k < 6; k++){
         for (int l = 0; l < 6; l++){

          bool SignalRegion = CorrectedLambdaMass > 2274. && CorrectedLambdaMass < 2300.;
          bool BackgroundRegion = (CorrectedLambdaMass > 2185. && CorrectedLambdaMass < 2237.) || (CorrectedLambdaMass > 2333. && CorrectedLambdaMass < 2385.);

          double x = 0.7 + (0.4 * i);
          double xx = 1.1 + (0.4 * i);
       	 double y = 0.4 + (0.1 * j);
       	 double yy = 0.5 + (0.1 * j);
         double z = 0.7 + (0.4 * k);
          double zz = 1.1 + (0.4 * k);
          double w = 0.4 + (0.1 * l);
        	 double ww = 0.5 + (0.1 * l);

          if ((TMath::Log10(*PromptK_IPCHI2_OWNPV) > x) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < xx) && ((*PromptK_MC15TuneV1_ProbNNk) > y) && ((*PromptK_MC15TuneV1_ProbNNk) < yy) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) > z) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) < zz) && ((*PromptPi_MC15TuneV1_ProbNNpi) > w) && ((*PromptPi_MC15TuneV1_ProbNNpi) < ww) && MassCuts && MultivariateCut && SignalRegion && OddNumber){
            SignalR[i][j][k][l]->Fill(CorrectedLambdaMass);}

            if ((TMath::Log10(*PromptK_IPCHI2_OWNPV) > x) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < xx) && ((*PromptK_MC15TuneV1_ProbNNk) > y) && ((*PromptK_MC15TuneV1_ProbNNk) < yy) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) > z) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) < zz) && ((*PromptPi_MC15TuneV1_ProbNNpi) > w) && ((*PromptPi_MC15TuneV1_ProbNNpi) < ww) && MassCuts && MultivariateCut && BackgroundRegion && OddNumber){
              BackgroundR[i][j][k][l]->Fill(CorrectedLambdaMass);}

          if ((TMath::Log10(*PromptK_IPCHI2_OWNPV) > x) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < xx) && ((*PromptK_MC15TuneV1_ProbNNk) > y) && ((*PromptK_MC15TuneV1_ProbNNk) < yy) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) > z) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) < zz) && ((*PromptPi_MC15TuneV1_ProbNNpi) > w) && ((*PromptPi_MC15TuneV1_ProbNNpi) < ww) && MassCuts && MultivariateCut && OddNumber){
            hists[i][j][k][l]->Fill(CorrectedLambdaMass);}

            if ((TMath::Log10(*PromptK_IPCHI2_OWNPV) > x) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < xx) && ((*PromptK_MC15TuneV1_ProbNNk) > y) && ((*PromptK_MC15TuneV1_ProbNNk) < yy) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) > z) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) < zz) && ((*PromptPi_MC15TuneV1_ProbNNpi) > w) && ((*PromptPi_MC15TuneV1_ProbNNpi) < ww) && MassCuts && MultivariateCut){
              histstest[i][j][k][l]->Fill(CorrectedLambdaMass);}}}}}

      return kTRUE;
}

void MVFigureofMerit::SlaveTerminate()
{
}

void MVFigureofMerit::Terminate()
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

for (int i = 0; i < 6; i++){
  for (int j = 0; j < 6; j++){
    for (int k = 0; k < 6; k++){
      for (int l = 0; l < 6; l++){

double  Signal = (SignalR[i][j][k][l]->GetEntries() - round(BackgroundR[i][j][k][l]->GetEntries()/4));
double  Background = (hists[i][j][k][l]->GetEntries() - Signal);

     fom[i][j][k][l] = (Signal / Background);
//5      fom[i][j] = (Signal / TMath::Sqrt(hists[i][j]->GetEntries()));

//std::cout <<fom[i][j][k][l]<<" Signal Events:"<<Signal<<" Background Events:"<<Background<<" i="<<i<<" j="<<j<< endl;
      hists[i][j][k][l]->Write();
      BackgroundR[i][j][k][l]->Write();
      SignalR[i][j][k][l]->Write();

     if (fom[i][j][k][l] > 0.2)
     AddedHistogram->Add(histstest[i][j][k][l], 1);
}}}}

 AddedHistogram->Fit("myLambdaFit");
 c1->Write();
 File->Close();
}
