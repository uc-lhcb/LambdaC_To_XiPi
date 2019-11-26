#define Fast4DAnalysis_cxx
#include "Fast4DAnalysis.h"

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

std::array<std::array<std::array<std::array<double, 15>, 15>, 15>, 15> fomKPi;

TH1D * FourDimensional075 = nullptr;
TH1D * FourDimensional25 = nullptr;
TH1D * FourDimensional6 = nullptr;

TH1D * FOMKPi = nullptr;

TFile * File = nullptr;
TCanvas * c1 = nullptr;

void Fast4DAnalysis::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void Fast4DAnalysis::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();

   FourDimensional075 = new TH1D("Figures of Merit", "Mass of LambdaC - FOM Kaon & Pion > 0.075", 100, 2185, 2385);
   FourDimensional075->GetXaxis()->SetTitle("MeV");
   FourDimensional075->GetYaxis()->SetTitle("Events Per 2 MeV");

   FourDimensional25 = new TH1D("Figures of Merit", "Mass of LambdaC - FOM Kaon & Pion > 0.25", 100, 2185, 2385);
   FourDimensional25->GetXaxis()->SetTitle("MeV");
   FourDimensional25->GetYaxis()->SetTitle("Events Per 2 MeV");

   FourDimensional6 = new TH1D("Figures of Merit", "Mass of LambdaC - FOM Kaon & Pion > 0.6", 100, 2185, 2385);
   FourDimensional6->GetXaxis()->SetTitle("MeV");
   FourDimensional6->GetYaxis()->SetTitle("Events Per 2 MeV");

      FOMKPi = new TH1D("Figures of Merit", "Frequency of Kaon/Pion S:B FOMs", 100, 0, 2);
      FOMKPi->GetXaxis()->SetTitle("FOM");
      FOMKPi->GetYaxis()->SetTitle("Events Per 0.2 S:B");

      File = new TFile("4DFast.root", "RECREATE");
     gFile = File;

      c1 = new TCanvas("canvas", "Test Canvas");

                for (double m = 0; m < 15; m++){
                  for (double n = 0; n < 15; n++){
                    for (double p = 0; p < 15; p++){
                      for (double q = 0; q < 15; q++){

                      double xf = 1. + (0.1 * m);
                      double yf = 0.42 + (0.04 * n);
                      double wf = 1. + (0.1 * p);
                      double zf = 0.42 + (0.04 * q);

                      double  SignalPi = (552.1 * TMath::Exp((-0.297 * xf) + (-0.2 * xf * xf)) * (86.72 + TMath::Exp(-15.86 + (24.19 * yf))));
                      double  BackgroundPi = ((71.24 + TMath::Exp(11.03 - (4.16 * xf))) * (365.75 + TMath::Exp(-3.49 + (11.61 * yf))));
                      double  SignalK = ((361.21 - (98.29 * wf)) * (103.74 + TMath::Exp(-20.93 + (29.44 * zf))));
                      double  BackgroundK = ((92.5 + TMath::Exp(10.54 - (3.76 * wf))) * (559.94 + TMath::Exp(-10.83 + (18.96 * zf))));

                      fomKPi[m][n][p][q] = ((SignalPi * SignalK) / (BackgroundPi * BackgroundK));}}}}

}

Bool_t Fast4DAnalysis::Process(Long64_t entry)
{
  GetEntry(entry);
   fReader.SetEntry(entry);

      //    Corrected Xi Mass
          double CorrectedXiMass = ((*Xi_MM) - (*Lambda_MM) + 1115.683);

      //    Corrected Lambda Mass
          double CorrectedLambdaMass = ((*Lambda_cplus_MM) - (*Xi_MM) + (1321.71));

   bool AdditionalCuts = (
      (*Lambda_cplus_PT > 2000.)
   && (CorrectedXiMass > 1310. && CorrectedXiMass < 1330.)
   );

int   m = floor(abs(TMath::Log10(*PromptPi_IPCHI2_OWNPV) - 0.95)/(0.1));
int   n = floor(abs(*PromptPi_MC15TuneV1_ProbNNpi - 0.40)/(0.04));
int   p = floor(abs(TMath::Log10(*PromptK_IPCHI2_OWNPV) - 0.95)/(0.1));
int   q = floor(abs(*PromptK_MC15TuneV1_ProbNNk - 0.40)/(0.04));


double FOM = fomKPi[m][n][p][q];

if (FOM > 0.075 && AdditionalCuts && TMath::Log10(*PromptPi_IPCHI2_OWNPV) > 0.9 && TMath::Log10(*PromptPi_IPCHI2_OWNPV) < 2.45 && TMath::Log10(*PromptK_IPCHI2_OWNPV) > 0.9 && TMath::Log10(*PromptK_IPCHI2_OWNPV) < 2.45 && *PromptPi_MC15TuneV1_ProbNNpi > 0.4 && *PromptK_MC15TuneV1_ProbNNk > 0.4){
FourDimensional075->Fill(CorrectedLambdaMass);}

if (FOM > 0.25 && AdditionalCuts && TMath::Log10(*PromptPi_IPCHI2_OWNPV) > 0.9 && TMath::Log10(*PromptPi_IPCHI2_OWNPV) < 2.45 && TMath::Log10(*PromptK_IPCHI2_OWNPV) > 0.9 && TMath::Log10(*PromptK_IPCHI2_OWNPV) < 2.45 && *PromptPi_MC15TuneV1_ProbNNpi > 0.4 && *PromptK_MC15TuneV1_ProbNNk > 0.4){
FourDimensional25->Fill(CorrectedLambdaMass);}

if (FOM > 0.6 && AdditionalCuts && TMath::Log10(*PromptPi_IPCHI2_OWNPV) > 0.9 && TMath::Log10(*PromptPi_IPCHI2_OWNPV) < 2.45 && TMath::Log10(*PromptK_IPCHI2_OWNPV) > 0.9 && TMath::Log10(*PromptK_IPCHI2_OWNPV) < 2.45 && *PromptPi_MC15TuneV1_ProbNNpi > 0.4 && *PromptK_MC15TuneV1_ProbNNk > 0.4){
FourDimensional6->Fill(CorrectedLambdaMass);}

   return kTRUE;
}

void Fast4DAnalysis::SlaveTerminate()
{
}

void Fast4DAnalysis::Terminate()
{
  for (double m = 0; m < 15; m++){
    for (double n = 0; n < 15; n++){
      for (double p = 0; p < 15; p++){
        for (double q = 0; q < 15; q++){

FOMKPi->Fill(fomKPi[m][n][p][q]);
}}}}


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

FourDimensional075->Fit("myLambdaFit");
FourDimensional075->SetMinimum(0);
c1->Write("FourDimensional 0.075");

FourDimensional25->Fit("myLambdaFit");
FourDimensional25->SetMinimum(0);
c1->Write("FourDimensional 0.25");

FourDimensional6->Fit("myLambdaFit");
FourDimensional6->SetMinimum(0);
c1->Write("FourDimensional 0.6");

FOMKPi->Draw();
c1->Write("Kaon/Pion FOMs");

File->Close();
}
