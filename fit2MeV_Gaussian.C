#pragma once

#include "TMath.h"

// For ROOT, "main" function must have same name as file

Double_t fit2MeV_Gaussian(Double_t *v, Double_t *par) {

    //  create a fitting function for a linear background plus a Gaussian signal
    //  the nominal units are MeV with a 1 MeV bin width
    
    Double_t arg = 0;
    if (par[2] != 0)
        arg = (v[0] - par[1])/par[2];

    //  create a Gaussian with width par[2] and mean par[1]
    Double_t fitval = par[0]*TMath::Exp(-0.5*arg*arg);

    //  re-normalize to make par[0] the integral of the Gaussian, assuming 1 MeV bins
    fitval = (fitval*2.00)/(TMath::Sqrt(TMath::TwoPi())*par[2]);

    //  add a linear background
    fitval = fitval + par[3] + v[0]*par[4];

    //  we're done
    return fitval;
}
