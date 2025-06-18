// ------------------------- //
// fit_all.C
// Fit 3 peaks and draw
// a graph for calibration
// ------------------------- //

TH1D* make_hist(TString filename = "data1"){

    const int nbins = 8192;
    const double bin_min = 0., bin_max = 8192.;
    TH1D* hist = new TH1D(filename, filename , nbins, bin_min-0.5, bin_max-0.5);

    const TString data_dir = "../data/";
    double BufferValue;
    ifstream ifs(data_dir + filename + ".txt");
    while(ifs >> BufferValue){
        hist->Fill(BufferValue);
    }

    hist->Rebin(16);
    hist->SetTitle(";ADC value;Counts/16 ADCs");
    return hist;
}

void fit_all(){

    auto C1 = new TCanvas();
    auto hist1 = make_hist("data1"); // Cs-137
    auto hist2 = make_hist("data2"); // Na-22
    hist1->SetLineColor(kBlack);
    hist1->Draw();
    hist2->SetLineColor(kBlue);
    hist2->Draw("same");

    auto f1 = new TF1("f_cs137", "gaus(0)", 2700, 4000);
    auto f2 = new TF1("f_na22_l", "gaus(0)", 2100, 2500);
    auto f3 = new TF1("f_na22_h", "gaus(0)", 5200, 8000);
    hist1->Fit(f1, "R0", "");
    hist2->Fit(f2, "R0", "");
    hist2->Fit(f3, "R0", "");
    f1->Draw("same");
    f2->Draw("same");
    f3->Draw("same");

    auto C2 = new TCanvas();
    auto graph = new TGraphErrors();
    graph->SetPoint(0, 662, f1->GetParameter(1));
    graph->SetPointError(0, 0., f1->GetParError(1));
    graph->SetPoint(1, 511, f2->GetParameter(1));
    graph->SetPointError(1, 0., f2->GetParError(1));
    graph->SetPoint(2, 1275, f3->GetParameter(1));
    graph->SetPointError(2, 0., f3->GetParError(1));
    graph->Draw("APE");

    auto f_lin = new TF1("f_lin", "pol1");
    graph->Fit(f_lin);

}
