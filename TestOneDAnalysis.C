//Two Loops of Particles, First Loop assigning x,y,w,z value to particle number, Second Loop if x,y,w,z value is in range put particle into histogram

#define TestOneDAnalysis_cxx
#include "TestOneDAnalysis.h"

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
std::vector<std::vector<double >> VectorKPi;

TH1D * FourDimensional075 = nullptr;
TH1D * FourDimensional1 = nullptr;
TH1D * FourDimensional25 = nullptr;
TH1D * FourDimensional5 = nullptr;

TH1D * FOMKPi = nullptr;

TFile * File = nullptr;
TCanvas * c1 = nullptr;

std::vector<int> mm075;
std::vector<int> nn075;
std::vector<int> pp075;
std::vector<int> qq075;
std::vector<int> mm1;
std::vector<int> nn1;
std::vector<int> pp1;
std::vector<int> qq1;
std::vector<int> mm25;
std::vector<int> nn25;
std::vector<int> pp25;
std::vector<int> qq25;
std::vector<int> mm5;
std::vector<int> nn5;
std::vector<int> pp5;
std::vector<int> qq5;
std::vector<double> xf075;
std::vector<double> yf075;
std::vector<double> wf075;
std::vector<double> zf075;
std::vector<double> xf1;
std::vector<double> yf1;
std::vector<double> wf1;
std::vector<double> zf1;
std::vector<double> xf25;
std::vector<double> yf25;
std::vector<double> wf25;
std::vector<double> zf25;
std::vector<double> xf5;
std::vector<double> yf5;
std::vector<double> wf5;
std::vector<double> zf5;

void TestOneDAnalysis::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void TestOneDAnalysis::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();

   FourDimensional075 = new TH1D("Figures of Merit", "Mass of LambdaC - FOM Kaon & Pion > 0.075", 100, 2185, 2385);
   FourDimensional075->GetXaxis()->SetTitle("MeV");
   FourDimensional075->GetYaxis()->SetTitle("Events Per 2 MeV");

   FourDimensional1 = new TH1D("Figures of Merit", "Mass of LambdaC - FOM Kaon & Pion > 0.1", 100, 2185, 2385);
   FourDimensional1->GetXaxis()->SetTitle("MeV");
   FourDimensional1->GetYaxis()->SetTitle("Events Per 2 MeV");

   FourDimensional25 = new TH1D("Figures of Merit", "Mass of LambdaC - FOM Kaon & Pion > 0.25", 100, 2185, 2385);
   FourDimensional25->GetXaxis()->SetTitle("MeV");
   FourDimensional25->GetYaxis()->SetTitle("Events Per 2 MeV");

   FourDimensional5 = new TH1D("Figures of Merit", "Mass of LambdaC - FOM Kaon & Pion > 0.5", 100, 2185, 2385);
   FourDimensional5->GetXaxis()->SetTitle("MeV");
   FourDimensional5->GetYaxis()->SetTitle("Events Per 2 MeV");

   FOMKPi = new TH1D("Figures of Merit", "Frequency of Kaon/Pion S:B FOMs", 100, 0, 2);
   FOMKPi->GetXaxis()->SetTitle("FOM");
   FOMKPi->GetYaxis()->SetTitle("Events Per 0.2 S:B");

   File = new TFile("4DProjection.root", "RECREATE");
  gFile = File;

   c1 = new TCanvas("canvas", "Test Canvas");

             for (double m = 0; m < 15; m++){
               for (double n = 0; n < 15; n++){
                 for (double p = 0; p < 15; p++){
                   for (double q = 0; q < 15; q++){

                   double xf = 1 + (0.1 * m);
                   double yf = 0.42 + (0.04 * n);
                   double wf = 1 + (0.1 * p);
                   double zf = 0.42 + (0.04 * q);

                   double  SignalPi = (552.1 * TMath::Exp((-0.297 * xf) + (-0.2 * xf * xf)) * (86.72 + TMath::Exp(-15.86 + (24.19 * yf))));
                   double  BackgroundPi = ((71.24 + TMath::Exp(11.03 - (4.16 * xf))) * (365.75 + TMath::Exp(-3.49 + (11.61 * yf))));
                   double  SignalK = ((361.21 - (98.29 * wf)) * (103.74 + TMath::Exp(-20.93 + (29.44 * zf))));
                   double  BackgroundK = ((92.5 + TMath::Exp(10.54 - (3.76 * wf))) * (559.94 + TMath::Exp(-10.83 + (18.96 * zf))));

                   fomKPi[m][n][p][q] = ((SignalPi * SignalK) / (BackgroundPi * BackgroundK));

if (fomKPi[m][n][p][q] > 0.075) {
mm075.push_back(m);
nn075.push_back(n);
pp075.push_back(p);
qq075.push_back(q);
}

if (fomKPi[m][n][p][q] > 0.1) {
mm1.push_back(m);
nn1.push_back(n);
pp1.push_back(p);
qq1.push_back(q);
}

if (fomKPi[m][n][p][q] > 0.25) {
mm25.push_back(m);
nn25.push_back(n);
pp25.push_back(p);
qq25.push_back(q);
}

if (fomKPi[m][n][p][q] > 0.5) {
mm5.push_back(m);
nn5.push_back(n);
pp5.push_back(p);
qq5.push_back(q);
}

}}}}

int n075 = mm075.size();
int n1 = mm1.size();
int n25 = mm25.size();
int n5 = mm5.size();

//Conversion Into Real Parameter Coordinates

  for (int z = 0; z < n075; z++){

    xf075.push_back(1 + (0.1 * mm075[z]));
    yf075.push_back(0.42 + (0.04 * nn075[z]));
    wf075.push_back(1 + (0.1 * pp075[z]));
    zf075.push_back(0.42 + (0.04 * qq075[z]));}

  for (int z = 0; z < n1; z++){

    xf1.push_back(1 + (0.1 * mm1[z]));
    yf1.push_back(0.42 + (0.04 * nn1[z]));
    wf1.push_back(1 + (0.1 * pp1[z]));
    zf1.push_back(0.42 + (0.04 * qq1[z]));}

  for (int z = 0; z < n25; z++){

    xf25.push_back(1 + (0.1 * mm25[z]));
    yf25.push_back(0.42 + (0.04 * nn25[z]));
    wf25.push_back(1 + (0.1 * pp25[z]));
    zf25.push_back(0.42 + (0.04 * qq25[z]));}

  for (int z = 0; z < n5; z++){
    xf5.push_back(1 + (0.1 * mm5[z]));
    yf5.push_back(0.42 + (0.04 * nn5[z]));
    wf5.push_back(1 + (0.1 * pp5[z]));
    zf5.push_back(0.42 + (0.04 * qq5[z]));}

   std::cout <<n075<< endl;
   std::cout <<n1<< endl;
   std::cout <<n25<< endl;
   std::cout <<n5<< endl;
}

Bool_t TestOneDAnalysis::Process(Long64_t entry)
{
  GetEntry(entry);
   fReader.SetEntry(entry);

   int n075 = mm075.size();
   int n1 = mm1.size();
   int n25 = mm25.size();
   int n5 = mm5.size();

   //    Corrected Xi Mass
       double CorrectedXiMass = ((*Xi_MM) - (*Lambda_MM) + 1115.683);

   //    Corrected Lambda Mass
       double CorrectedLambdaMass = ((*Lambda_cplus_MM) - (*Xi_MM) + (1321.71));

bool AdditionalCuts = (
   (*Lambda_cplus_PT > 2000.)
&& (CorrectedXiMass > 1310. && CorrectedXiMass < 1330.)
);

  for (int z = 0; z < n075; z++){
            if((TMath::Log10(*PromptK_IPCHI2_OWNPV) > (xf075[z] - 0.05)) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < (xf075[z] + 0.05)) && ((*PromptK_MC15TuneV1_ProbNNk) > (yf075[z] - 0.02)) && ((*PromptK_MC15TuneV1_ProbNNk) < (yf075[z] + 0.02)) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) > (wf075[z] - 0.05)) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) < (wf075[z] + 0.05)) && ((*PromptPi_MC15TuneV1_ProbNNpi) > (zf075[z] - 0.02)) && ((*PromptPi_MC15TuneV1_ProbNNpi) < (zf075[z] + 0.02)) && AdditionalCuts)
              FourDimensional075->Fill(CorrectedLambdaMass);}

  for (int z = 0; z < n1; z++){
            if((TMath::Log10(*PromptK_IPCHI2_OWNPV) > (xf1[z] - 0.05)) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < (xf1[z] + 0.05)) && ((*PromptK_MC15TuneV1_ProbNNk) > (yf1[z] - 0.02)) && ((*PromptK_MC15TuneV1_ProbNNk) < (yf1[z] + 0.02)) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) > (wf1[z] - 0.05)) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) < (wf1[z] + 0.05)) && ((*PromptPi_MC15TuneV1_ProbNNpi) > (zf1[z] - 0.02)) && ((*PromptPi_MC15TuneV1_ProbNNpi) < (zf1[z] + 0.02)) && AdditionalCuts)
              FourDimensional1->Fill(CorrectedLambdaMass);}

  for (int z = 0; z < n25; z++){
            if((TMath::Log10(*PromptK_IPCHI2_OWNPV) > (xf25[z] - 0.05)) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < (xf25[z] + 0.05)) && ((*PromptK_MC15TuneV1_ProbNNk) > (yf25[z] - 0.02)) && ((*PromptK_MC15TuneV1_ProbNNk) < (yf25[z] + 0.02)) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) > (wf25[z] - 0.05)) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) < (wf25[z] + 0.05)) && ((*PromptPi_MC15TuneV1_ProbNNpi) > (zf25[z] - 0.02)) && ((*PromptPi_MC15TuneV1_ProbNNpi) < (zf25[z] + 0.02)) && AdditionalCuts)
              FourDimensional25->Fill(CorrectedLambdaMass);}

  for (int z = 0; z < n5; z++){
            if((TMath::Log10(*PromptK_IPCHI2_OWNPV) > (xf5[z] - 0.05)) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < (xf5[z] + 0.05)) && ((*PromptK_MC15TuneV1_ProbNNk) > (yf5[z] - 0.02)) && ((*PromptK_MC15TuneV1_ProbNNk) < (yf5[z] + 0.02)) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) > (wf5[z] - 0.05)) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) < (wf5[z] + 0.05)) && ((*PromptPi_MC15TuneV1_ProbNNpi) > (zf5[z] - 0.02)) && ((*PromptPi_MC15TuneV1_ProbNNpi) < (zf5[z] + 0.02)) && AdditionalCuts)
              FourDimensional5->Fill(CorrectedLambdaMass);}


   return kTRUE;
}

void TestOneDAnalysis::SlaveTerminate()
{
}

void TestOneDAnalysis::Terminate()
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

   FourDimensional1->Fit("myLambdaFit");
   FourDimensional1->SetMinimum(0);
   c1->Write("FourDimensional 0.1");

   FourDimensional25->Fit("myLambdaFit");
   FourDimensional25->SetMinimum(0);
   c1->Write("FourDimensional 0.25");

   FourDimensional5->Fit("myLambdaFit");
   FourDimensional5->SetMinimum(0);
   c1->Write("FourDimensional 0.5");

   FOMKPi->Draw();
   c1->Write("Kaon/Pion FOMs");

  File->Close();
}
