#define OneDProjection_cxx
#include "OneDProjection.h"
#include <TH2.h>
#include <TStyle.h>
#include <TFile.h>

TCanvas *c1 = new TCanvas("Background Subtraction","Histograms",1000,500);
TFile * File = nullptr;

TH1 *IPCHI2Signal = nullptr;
TH1 *IPCHI2bkgd = nullptr;

TH1 *ProbSignal = nullptr;
TH1 *Probbkgd = nullptr;

TH1 * IPCHI2SignalEstimate = nullptr;
TH1 * ProbSignalEstimate = nullptr;

double UB1 = 1.;
double LB1 = 0.4;
const int Bin1 = 12;

double UB2 = 3.5;
double LB2 = 0.7;
const int Bin2 = 28;

void OneDProjection::Begin(TTree * /*tree*/)
{
   TString option = GetOption();
}

void OneDProjection::SlaveBegin(TTree * /*tree*/)
{
   TString option = GetOption();

      File = new TFile("1DProjectionPion.root", "RECREATE");
     gFile = File;

   TH1::SetDefaultSumw2(kTRUE);

   ProbSignal = new TH1D("Probability", "Signal Region", Bin1, LB1, UB1);
   Probbkgd = new TH1D("Probability", "Background Region", Bin1, LB1, UB1);
   ProbSignalEstimate = new TH1D("Probability", "Signal Estimation", Bin1, LB1, UB1);

   IPCHI2Signal = new TH1D("IPCHI2", "Signal Region", Bin2, LB2, UB2);
   IPCHI2bkgd = new TH1D("IPCHI2", "Background Region", Bin2, LB2, UB2);
   IPCHI2SignalEstimate = new TH1D("IPCHI2", "Signal Estimation", Bin2, LB2, UB2);

   ProbSignal->SetLineColor(kBlue);
   Probbkgd->SetLineColor(kRed);
   ProbSignalEstimate->SetLineColor(kGreen+3);
   IPCHI2Signal->SetLineColor(kBlue);
   IPCHI2bkgd->SetLineColor(kRed);
   IPCHI2SignalEstimate->SetLineColor(kGreen+3);
}

Bool_t OneDProjection::Process(Long64_t entry)
{
  fReader.SetEntry(entry);
  GetEntry(entry);

     //Corrected Xi Mass
     double CorrectedXiMass = ((*Xi_MM) - (*Lambda_MM) + 1115.683);

     //Corrected Lambda Mass
     double CorrectedLambdaMass = ((*Lambda_cplus_MM) - (*Xi_MM) + (1321.71));

     bool MassCuts = (
        (*Lambda_cplus_MM > 2185. && *Lambda_cplus_MM < 2385.)
       && (CorrectedXiMass > 1310. && CorrectedXiMass < 1330.)
  );

bool PreliminaryCuts = (
  (*Lambda_cplus_PT > 2000.)
&&  (TMath::Log10(*PromptK_IPCHI2_OWNPV) > 0.7)
&&	(TMath::Log10(*PromptPi_IPCHI2_OWNPV) > 0.7)
&&	(*PromptK_MC15TuneV1_ProbNNk > 0.4)
&&	(*PromptPi_MC15TuneV1_ProbNNpi > 0.4)
);

 bool SignalRegion = CorrectedLambdaMass > 2274. && CorrectedLambdaMass < 2300.;
 bool BackgroundRegion = (CorrectedLambdaMass > 2190. && CorrectedLambdaMass < 2203.) || (CorrectedLambdaMass > 2367. && CorrectedLambdaMass < 2380.);

 if (SignalRegion && PreliminaryCuts && MassCuts)
     IPCHI2Signal->Fill(TMath::Log10(*PromptPi_IPCHI2_OWNPV));

if (BackgroundRegion && PreliminaryCuts && MassCuts)
    IPCHI2bkgd->Fill(TMath::Log10(*PromptPi_IPCHI2_OWNPV));

if (SignalRegion && PreliminaryCuts && MassCuts)
        ProbSignal->Fill(*PromptPi_MC15TuneV1_ProbNNpi);

if (BackgroundRegion && PreliminaryCuts && MassCuts)
       Probbkgd->Fill(*PromptPi_MC15TuneV1_ProbNNpi);

ProbSignalEstimate->Add(ProbSignal,Probbkgd,1.0,-1.0);
IPCHI2SignalEstimate->Add(IPCHI2Signal,IPCHI2bkgd,1.0,-1.0);

   return kTRUE;
 }

void OneDProjection::SlaveTerminate()
{
}

void OneDProjection::Terminate()
{
  TF1 *ProbSignalFit = new TF1("f1","[0] + exp([1] + [2]*x)", 0.4, 1.);
  ProbSignalFit->SetParLimits(2, 0.,30.);

  TF1 *IPCHI2BackgroundFit = new TF1("f2","[0] + exp([1] + [2]*x)", 0.7, 3.5);
  IPCHI2BackgroundFit->SetParLimits(2, -5.,0.);

  TF1 *IPCHI2SignalFit = new TF1("f3","[0]*exp([1]*x + [2]*x*x)", 0.7, 3.5);

  IPCHI2SignalEstimate->SetMaximum(1200);
  IPCHI2SignalEstimate->SetMinimum(0);
  ProbSignalEstimate->SetMaximum(3000);

  IPCHI2SignalEstimate->Fit("f3");
  IPCHI2SignalEstimate->GetFunction("f3")->SetLineColor(kGreen+3);
  IPCHI2bkgd->Fit("f2");
  IPCHI2bkgd->GetFunction("f2")->SetLineColor(kRed);
  ProbSignalEstimate->Fit("f1");
  ProbSignalEstimate->GetFunction("f1")->SetLineColor(kGreen+3);
  Probbkgd->Fit("f1");
  Probbkgd->GetFunction("f1")->SetLineColor(kRed);

gStyle->SetOptTitle(0);
TPaveText *t1 = new TPaveText(0.3, 0.91, 0.7, 1.0, "brNDC");
t1->AddText("Signal and Background Estimation for PromptPi_IPCHI2_OWNPV");
TPaveText *t2 = new TPaveText(0.3, 0.91, 0.7, 1.0, "brNDC");
t2->AddText("Signal and Background Estimation for PromptPi_MC15TuneV1_ProbNNpi");

  IPCHI2SignalEstimate->Draw();
  IPCHI2Signal->Draw("SAME");
  IPCHI2bkgd->Draw("SAME");
  t1->Draw("SAME");
  IPCHI2SignalEstimate->GetYaxis()->SetTitle("Events per 1 mm");
  IPCHI2SignalEstimate->GetXaxis()->SetTitle("IPCHI2");
  gPad->BuildLegend(0.78,0.75,0.98,0.95);
  c1->Write("IPCHI2 Estimations");

  c1->Clear();
  ProbSignalEstimate->Draw();
  ProbSignal->Draw("SAME");
  Probbkgd->Draw("SAME");
  t2->Draw("SAME");
  ProbSignalEstimate->GetYaxis()->SetTitle("Events per 1 mm");
  ProbSignalEstimate->GetXaxis()->SetTitle("Probability");
  gPad->BuildLegend(0.78,0.75,0.98,0.95);
  c1->Write("Prob Estimations");
}
