//Extend the log(IPCHI2) beyond 3.5


#define OneDMVAnalysis_cxx
#include "OneDMVAnalysis.h"

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

std::array<std::array<double, 30>, 30> fomKSignal;
std::array<std::array<double, 30>, 30> fomKBackground;
std::array<std::array<double, 30>, 30> fomK;

std::array<std::array<double, 30>, 30> fomPiSignal;
std::array<std::array<double, 30>, 30> fomPiBackground;
std::array<std::array<double, 30>, 30> fomPi;

std::array<std::array<std::array<std::array<double, 15>, 15>, 15>, 15> fomKPi;

TH2D * FigureK = nullptr;
TH2D * SignalKPlot = nullptr;
TH2D * BackgroundKPlot = nullptr;
TH1D * HistogramK3 = nullptr;
TH1D * HistogramK4 = nullptr;
TH1D * HistogramK5 = nullptr;
TH1D * HistogramK7 = nullptr;
TH1D * HistogramK9 = nullptr;
TH1D * FOMKaon = nullptr;

TH2D * FigurePi = nullptr;
TH2D * SignalPiPlot = nullptr;
TH2D * BackgroundPiPlot = nullptr;
TH1D * HistogramPi3 = nullptr;
TH1D * HistogramPi4 = nullptr;
TH1D * HistogramPi5 = nullptr;
TH1D * HistogramPi7 = nullptr;
TH1D * HistogramPi9 = nullptr;
TH1D * FOMPion = nullptr;

TH1D * FourDimensional = nullptr;
TH1D * FourDimensional2 = nullptr;
TH1D * FOMKPi = nullptr;

TFile * File = nullptr;
TCanvas * c1 = nullptr;

void OneDMVAnalysis::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void OneDMVAnalysis::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();

SignalKPlot = new TH2D("Figures of Merit", "Color Plot of LambdaC Mass - Signal*Signal", 30, 0.7, 3.7, 30, 0.4, 1.0);
SignalKPlot->GetXaxis()->SetTitle("Log(PromptK_IPCHI2_OWNPV)");
SignalKPlot->GetYaxis()->SetTitle("PromptK_MC15TuneV1_ProbNNk");
SignalKPlot->GetZaxis()->SetTitle("Signal*Signal");

BackgroundKPlot = new TH2D("Figures of Merit", "Color Plot of LambdaC Mass - Background*Background", 30, 0.7, 3.7, 30, 0.4, 1.0);
BackgroundKPlot->GetXaxis()->SetTitle("Log(PromptK_IPCHI2_OWNPV)");
BackgroundKPlot->GetYaxis()->SetTitle("PromptK_MC15TuneV1_ProbNNk");
BackgroundKPlot->GetZaxis()->SetTitle("Background*Background");

   FigureK = new TH2D("Figures of Merit", "Color Plot of LambdaC Mass - One Dimensional Projections", 30, 0.7, 3.7, 30, 0.4, 1.0);
   FigureK->GetXaxis()->SetTitle("Log(PromptK_IPCHI2_OWNPV)");
   FigureK->GetYaxis()->SetTitle("PromptK_MC15TuneV1_ProbNNk");
   FigureK->GetZaxis()->SetTitle("Signal*Signal / Background*Background");

   SignalPiPlot = new TH2D("Figures of Merit", "Color Plot of LambdaC Mass - Signal*Signal", 30, 0.7, 3.7, 30, 0.4, 1.0);
   SignalPiPlot->GetXaxis()->SetTitle("Log(PromptK_IPCHI2_OWNPV)");
   SignalPiPlot->GetYaxis()->SetTitle("PromptK_MC15TuneV1_ProbNNk");
   SignalPiPlot->GetZaxis()->SetTitle("Signal*Signal");

   BackgroundPiPlot = new TH2D("Figures of Merit", "Color Plot of LambdaC Mass - Background*Background", 30, 0.7, 3.7, 30, 0.4, 1.0);
   BackgroundPiPlot->GetXaxis()->SetTitle("Log(PromptK_IPCHI2_OWNPV)");
   BackgroundPiPlot->GetYaxis()->SetTitle("PromptK_MC15TuneV1_ProbNNk");
   BackgroundPiPlot->GetZaxis()->SetTitle("Background*Background");

   FigurePi = new TH2D("Figures of Merit", "Color Plot of LambdaC Mass - One Dimensional Projections", 30, 0.7, 3.7, 30, 0.4, 1.0);
   FigurePi->GetXaxis()->SetTitle("Log(PromptPi_IPCHI2_OWNPV)");
   FigurePi->GetYaxis()->SetTitle("PromptPi_MC15TuneV1_ProbNNpi");
   FigurePi->GetZaxis()->SetTitle("Signal*Signal / Background*Background");

   HistogramK3 = new TH1D("Figures of Merit", "Mass of LambdaC - FOM Kaon > 0.3", 100, 2185, 2385);
   HistogramK3->GetXaxis()->SetTitle("MeV");
   HistogramK3->GetYaxis()->SetTitle("Events Per 2 MeV");

   HistogramK4 = new TH1D("Figures of Merit", "Mass of LambdaC - FOM Kaon > 0.4", 100, 2185, 2385);
   HistogramK4->GetXaxis()->SetTitle("MeV");
   HistogramK4->GetYaxis()->SetTitle("Events Per 2 MeV");

   HistogramK5 = new TH1D("Figures of Merit", "Mass of LambdaC - FOM Kaon > 0.5", 100, 2185, 2385);
   HistogramK5->GetXaxis()->SetTitle("MeV");
   HistogramK5->GetYaxis()->SetTitle("Events Per 2 MeV");

   HistogramK7 = new TH1D("Figures of Merit", "Mass of LambdaC - FOM Kaon > 0.7", 100, 2185, 2385);
   HistogramK7->GetXaxis()->SetTitle("MeV");
   HistogramK7->GetYaxis()->SetTitle("Events Per 2 MeV");

   HistogramK9 = new TH1D("Figures of Merit", "Mass of LambdaC - FOM Kaon > 0.9", 100, 2185, 2385);
   HistogramK9->GetXaxis()->SetTitle("MeV");
   HistogramK9->GetYaxis()->SetTitle("Events Per 2 MeV");

   HistogramPi3 = new TH1D("Figures of Merit", "Mass of LambdaC - FOM Pion > 0.3", 100, 2185, 2385);
   HistogramPi3->GetXaxis()->SetTitle("MeV");
   HistogramPi3->GetYaxis()->SetTitle("Events Per 2 MeV");

   HistogramPi4 = new TH1D("Figures of Merit", "Mass of LambdaC - FOM Pion > 0.4", 100, 2185, 2385);
   HistogramPi4->GetXaxis()->SetTitle("MeV");
   HistogramPi4->GetYaxis()->SetTitle("Events Per 2 MeV");

   HistogramPi5 = new TH1D("Figures of Merit", "Mass of LambdaC - FOM Pion > 0.5", 100, 2185, 2385);
   HistogramPi5->GetXaxis()->SetTitle("MeV");
   HistogramPi5->GetYaxis()->SetTitle("Events Per 2 MeV");

   HistogramPi7 = new TH1D("Figures of Merit", "Mass of LambdaC - FOM Pion > 0.7", 100, 2185, 2385);
   HistogramPi7->GetXaxis()->SetTitle("MeV");
   HistogramPi7->GetYaxis()->SetTitle("Events Per 2 MeV");

   HistogramPi9 = new TH1D("Figures of Merit", "Mass of LambdaC - FOM Pion > 0.9", 100, 2185, 2385);
   HistogramPi9->GetXaxis()->SetTitle("MeV");
   HistogramPi9->GetYaxis()->SetTitle("Events Per 2 MeV");

   FourDimensional = new TH1D("Figures of Merit", "Mass of LambdaC - FOM Kaon & Pion > 0.25", 100, 2185, 2385);
   FourDimensional->GetXaxis()->SetTitle("MeV");
   FourDimensional->GetYaxis()->SetTitle("Events Per 2 MeV");

   FourDimensional2 = new TH1D("Figures of Merit", "Mass of LambdaC - FOM Kaon & Pion > 0.1", 100, 2185, 2385);
   FourDimensional2->GetXaxis()->SetTitle("MeV");
   FourDimensional2->GetYaxis()->SetTitle("Events Per 2 MeV");

   FOMKaon = new TH1D("Figures of Merit", "Frequency of Kaon S:B FOMs", 100, 0, 2);
   FOMKaon->GetXaxis()->SetTitle("FOM");
   FOMKaon->GetYaxis()->SetTitle("Events Per 0.2 S:B");

   FOMPion = new TH1D("Figures of Merit", "Frequency of Pion S:B FOMs", 100, 0, 2);
   FOMPion->GetXaxis()->SetTitle("FOM");
   FOMPion->GetYaxis()->SetTitle("Events Per 0.2 S:B");

   FOMKPi = new TH1D("Figures of Merit", "Frequency of Kaon/Pion S:B FOMs", 100, 0, 2);
   FOMKPi->GetXaxis()->SetTitle("FOM");
   FOMKPi->GetYaxis()->SetTitle("Events Per 0.2 S:B");

   File = new TFile("1DColorPlotsWithHistogram.root", "RECREATE");
  gFile = File;

   c1 = new TCanvas("canvas", "Test Canvas");

   for (double i = 0; i < 30; i++){
     for (double j = 0; j < 30; j++){

             double x = 0.75 + (0.1 * i);
             double y = 0.41 + (0.02 * j);

             double  SignalK = ((361.21 - (98.29 * x)) * (103.74 + TMath::Exp(-20.93 + (29.44 * y))));
             double  BackgroundK = ((92.5 + TMath::Exp(10.54 - (3.76 * x))) * (559.94 + TMath::Exp(-10.83 + (18.96 * y))));
             fomK[i][j] = (SignalK / BackgroundK);
             fomKSignal[i][j] = SignalK;
             fomKBackground[i][j] = BackgroundK;

//             std::cout <<fomK[i][j]<<" x="<<x<<" y="<<y<< endl;
           }}

   for (double k = 0; k < 30; k++){
     for (double l = 0; l < 30; l++){

             double w = 0.75 + (0.1 * k);
             double z = 0.41 + (0.02 * l);

             double  SignalPi = (552.1 * TMath::Exp((-0.297 * w) + (-0.2 * w * w)) * (86.72 + TMath::Exp(-15.86 + (24.19 * z))));
             double  BackgroundPi = ((71.24 + TMath::Exp(11.03 - (4.16 * w))) * (365.75 + TMath::Exp(-3.49 + (11.61 * z))));
             fomPi[k][l] = (SignalPi / BackgroundPi);
             fomPiSignal[k][l] = SignalPi;
             fomPiBackground[k][l] = BackgroundPi;

//             std::cout <<fomPi[k][l]<<" w="<<w<<" z="<<z<< endl;
           }}


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

//                                std::cout <<fomKPi[m][n][p][q]<<" x="<<xf<<" y="<<yf<<" w="<<wf<<" z="<<zf<< endl;
}}}}

}

Bool_t OneDMVAnalysis::Process(Long64_t entry)
{

  GetEntry(entry);
   fReader.SetEntry(entry);

   //    Corrected Xi Mass
       double CorrectedXiMass = ((*Xi_MM) - (*Lambda_MM) + 1115.683);

   //    Corrected Lambda Mass
       double CorrectedLambdaMass = ((*Lambda_cplus_MM) - (*Xi_MM) + (1321.71));

   bool AdditionalCutsKaon = (
     (TMath::Log10(*PromptPi_IPCHI2_OWNPV) > 0.7)
  && (*PromptPi_MC15TuneV1_ProbNNpi > 0.4)
  && (*Lambda_cplus_PT > 2000.)
  && (CorrectedXiMass > 1310. && CorrectedXiMass < 1330.)
);

bool AdditionalCutsPion = (
  (TMath::Log10(*PromptK_IPCHI2_OWNPV) > 0.7)
&& (*PromptK_MC15TuneV1_ProbNNk > 0.4)
&& (*Lambda_cplus_PT > 2000.)
&& (CorrectedXiMass > 1310. && CorrectedXiMass < 1330.)
);

bool AdditionalCuts = (
   (*Lambda_cplus_PT > 2000.)
&& (CorrectedXiMass > 1310. && CorrectedXiMass < 1330.)
);

   for (double i = 0; i < 30; i++){
     for (double j = 0; j < 30; j++){

       double x = 0.75 + (0.1 * i);
       double y = 0.41 + (0.02 * j);

       if(fomK[i][j] > 0.3) {
double xt = x;
double yt = y;
       if((TMath::Log10(*PromptK_IPCHI2_OWNPV) > (xt - 0.05)) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < (xt + 0.05)) && ((*PromptK_MC15TuneV1_ProbNNk) > (yt - 0.01)) && ((*PromptK_MC15TuneV1_ProbNNk) < (yt + 0.01)) && AdditionalCutsKaon)
         HistogramK3->Fill(CorrectedLambdaMass);}

         if(fomK[i][j] > 0.4) {
double xtt = x;
double ytt = y;
         if((TMath::Log10(*PromptK_IPCHI2_OWNPV) > (xtt - 0.05)) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < (xtt + 0.05)) && ((*PromptK_MC15TuneV1_ProbNNk) > (ytt - 0.01)) && ((*PromptK_MC15TuneV1_ProbNNk) < (ytt + 0.01)) && AdditionalCutsKaon)
           HistogramK4->Fill(CorrectedLambdaMass);}

                  if(fomK[i][j] > 0.5) {
        double xx = x;
        double yy = y;
                  if((TMath::Log10(*PromptK_IPCHI2_OWNPV) > (xx - 0.05)) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < (xx + 0.05)) && ((*PromptK_MC15TuneV1_ProbNNk) > (yy - 0.01)) && ((*PromptK_MC15TuneV1_ProbNNk) < (yy + 0.01)) && AdditionalCutsKaon)
                    HistogramK5->Fill(CorrectedLambdaMass);}

                    if(fomK[i][j] > 0.7) {
          double xxx = x;
          double yyy = y;
                    if((TMath::Log10(*PromptK_IPCHI2_OWNPV) > (xxx - 0.05)) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < (xxx + 0.05)) && ((*PromptK_MC15TuneV1_ProbNNk) > (yyy - 0.01)) && ((*PromptK_MC15TuneV1_ProbNNk) < (yyy + 0.01)) && AdditionalCutsKaon)
                      HistogramK7->Fill(CorrectedLambdaMass);}

                      if(fomK[i][j] > 0.9) {
            double xxxx = x;
            double yyyy = y;
                      if((TMath::Log10(*PromptK_IPCHI2_OWNPV) > (xxxx - 0.05)) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < (xxxx + 0.05)) && ((*PromptK_MC15TuneV1_ProbNNk) > (yyyy - 0.01)) && ((*PromptK_MC15TuneV1_ProbNNk) < (yyyy + 0.01)) && AdditionalCutsKaon)
                        HistogramK9->Fill(CorrectedLambdaMass);}
}}

  for (double k = 0; k < 30; k++){
    for (double l = 0; l < 30; l++){

      double w = 0.75 + (0.1 * k);
      double z = 0.41 + (0.02 * l);

      if(fomPi[k][l] > 0.3) {
double wt = w;
double zt = z;
      if((TMath::Log10(*PromptPi_IPCHI2_OWNPV) > (wt - 0.05)) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) < (wt + 0.05)) && ((*PromptPi_MC15TuneV1_ProbNNpi) > (zt - 0.01)) && ((*PromptPi_MC15TuneV1_ProbNNpi) < (zt + 0.01)) && AdditionalCutsPion)
        HistogramPi3->Fill(CorrectedLambdaMass);}

        if(fomPi[k][l] > 0.4) {
double wtt = w;
double ztt = z;
        if((TMath::Log10(*PromptPi_IPCHI2_OWNPV) > (wtt - 0.05)) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) < (wtt + 0.05)) && ((*PromptPi_MC15TuneV1_ProbNNpi) > (ztt - 0.01)) && ((*PromptPi_MC15TuneV1_ProbNNpi) < (ztt + 0.01)) && AdditionalCutsPion)
          HistogramPi4->Fill(CorrectedLambdaMass);}

            if(fomPi[k][l] > 0.5) {
  double ww = w;
  double zz = z;
            if((TMath::Log10(*PromptPi_IPCHI2_OWNPV) > (ww - 0.05)) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) < (ww + 0.05)) && ((*PromptPi_MC15TuneV1_ProbNNpi) > (zz - 0.01)) && ((*PromptPi_MC15TuneV1_ProbNNpi) < (zz + 0.01)) && AdditionalCutsPion)
              HistogramPi5->Fill(CorrectedLambdaMass);}

              if(fomPi[k][l] > 0.7) {
    double www = w;
    double zzz = z;
              if((TMath::Log10(*PromptPi_IPCHI2_OWNPV) > (www - 0.05)) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) < (www + 0.05)) && ((*PromptPi_MC15TuneV1_ProbNNpi) > (zzz - 0.01)) && ((*PromptPi_MC15TuneV1_ProbNNpi) < (zzz + 0.01)) && AdditionalCutsPion)
                HistogramPi7->Fill(CorrectedLambdaMass);}

                if(fomPi[k][l] > 0.9) {
      double wwww = w;
      double zzzz = z;
                if((TMath::Log10(*PromptPi_IPCHI2_OWNPV) > (wwww - 0.05)) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) < (wwww + 0.05)) && ((*PromptPi_MC15TuneV1_ProbNNpi) > (zzzz - 0.01)) && ((*PromptPi_MC15TuneV1_ProbNNpi) < (zzzz + 0.01)) && AdditionalCutsPion)
                  HistogramPi9->Fill(CorrectedLambdaMass);}
    }}

    for (double m = 0; m < 15; m++){
      for (double n = 0; n < 15; n++){
        for (double p = 0; p < 15; p++){
          for (double q = 0; q < 15; q++){

          double xf = 1 + (0.1 * m);
          double yf = 0.42 + (0.04 * n);
          double wf = 1 + (0.1 * p);
          double zf = 0.42 + (0.04 * q);

        if(fomKPi[m][n][p][q] > 0.25) {
          double xff = xf;
          double yff = yf;
          double wff = wf;
          double zff = zf;

            if((TMath::Log10(*PromptK_IPCHI2_OWNPV) > (xff - 0.05)) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < (xff + 0.05)) && ((*PromptK_MC15TuneV1_ProbNNk) > (yff - 0.02)) && ((*PromptK_MC15TuneV1_ProbNNk) < (yff + 0.02)) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) > (wff - 0.05)) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) < (wff + 0.05)) && ((*PromptPi_MC15TuneV1_ProbNNpi) > (zff - 0.02)) && ((*PromptPi_MC15TuneV1_ProbNNpi) < (zff + 0.02)) && AdditionalCuts)
              FourDimensional->Fill(CorrectedLambdaMass);}

              if(fomKPi[m][n][p][q] > 0.1) {
                double xfff = xf;
                double yfff = yf;
                double wfff = wf;
                double zfff = zf;

                  if((TMath::Log10(*PromptK_IPCHI2_OWNPV) > (xfff - 0.05)) && (TMath::Log10(*PromptK_IPCHI2_OWNPV) < (xfff + 0.05)) && ((*PromptK_MC15TuneV1_ProbNNk) > (yfff - 0.02)) && ((*PromptK_MC15TuneV1_ProbNNk) < (yfff + 0.02)) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) > (wfff - 0.05)) && (TMath::Log10(*PromptPi_IPCHI2_OWNPV) < (wfff + 0.05)) && ((*PromptPi_MC15TuneV1_ProbNNpi) > (zfff - 0.02)) && ((*PromptPi_MC15TuneV1_ProbNNpi) < (zfff + 0.02)) && AdditionalCuts)
                    FourDimensional2->Fill(CorrectedLambdaMass);}
        }}}}

   return kTRUE;

}

void OneDMVAnalysis::SlaveTerminate()
{
}

void OneDMVAnalysis::Terminate()
{

  for (double i = 0; i < 30; i++){
    for (double j = 0; j < 30; j++){

      double x = 0.75 + (0.1 * i);
      double y = 0.41 + (0.02 * j);

             FOMKaon->Fill(fomK[i][j]);
             FigureK->Fill(x, y, fomK[i][j]);
             SignalKPlot->Fill(x, y, fomKSignal[i][j]);
             BackgroundKPlot->Fill(x, y, fomKBackground[i][j]);
}}

  for (double k = 0; k < 30; k++){
    for (double l = 0; l < 30; l++){

      double w = 0.75 + (0.1 * k);
      double z = 0.41 + (0.02 * l);

            FOMPion->Fill(fomPi[k][l]);
            FigurePi->Fill(w, z, fomPi[k][l]);
            SignalPiPlot->Fill(w, z, fomPiSignal[k][l]);
            BackgroundPiPlot->Fill(w, z, fomPiBackground[k][l]);
          }}

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

  FigureK->Draw("COLZ");
   c1->Write("Kaon Color Plot");

   SignalKPlot->Draw("COLZ");
    c1->Write("Kaon Color Plot - Signal");

    BackgroundKPlot->Draw("COLZ");
     c1->Write("Kaon Color Plot - Background");

  FigurePi->Draw("COLZ");
   c1->Write("Pion Color Plot");

   SignalPiPlot->Draw("COLZ");
    c1->Write("Pion Color Plot - Signal");

    BackgroundPiPlot->Draw("COLZ");
     c1->Write("Pion Color Plot - Background");

   HistogramK3->Fit("myLambdaFit");
   HistogramK3->SetMinimum(0);
   c1->Write("Kaon 0.3");

   HistogramK4->Fit("myLambdaFit");
   HistogramK4->SetMinimum(0);
   c1->Write("Kaon 0.4");

   HistogramK5->Fit("myLambdaFit");
   HistogramK5->SetMinimum(0);
   c1->Write("Kaon 0.5");

   HistogramK7->Fit("myLambdaFit");
   HistogramK7->SetMinimum(0);
   c1->Write("Kaon 0.7");

   HistogramK9->Fit("myLambdaFit");
   HistogramK9->SetMinimum(0);
   c1->Write("Kaon 0.9");

   HistogramPi3->Fit("myLambdaFit");
   HistogramPi3->SetMinimum(0);
   c1->Write("Pion 0.3");

   HistogramPi4->Fit("myLambdaFit");
   HistogramPi4->SetMinimum(0);
   c1->Write("Pion 0.4");

   HistogramPi5->Fit("myLambdaFit");
   HistogramPi5->SetMinimum(0);
   c1->Write("Pion 0.5");

   HistogramPi7->Fit("myLambdaFit");
   HistogramPi7->SetMinimum(0);
   c1->Write("Pion 0.7");

   HistogramPi9->Fit("myLambdaFit");
   HistogramPi9->SetMinimum(0);
   c1->Write("Pion 0.9");

   FourDimensional->Fit("myLambdaFit");
   FourDimensional->SetMinimum(0);
   c1->Write("FourDimensional 0.25");

   FourDimensional2->Fit("myLambdaFit");
   FourDimensional2->SetMinimum(0);
   c1->Write("FourDimensional 0.1");

   FOMKaon->Draw();
   c1->Write("Kaon FOMs");

   FOMPion->Draw();
   c1->Write("Pion FOMs");

   FOMKPi->Draw();
   c1->Write("Kaon/Pion FOMs");

  File->Close();

}
