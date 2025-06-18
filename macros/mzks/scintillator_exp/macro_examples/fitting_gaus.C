// ----------------------- //
// fitting_gaus.C -- macro
// Author: K. Mizukoshi
// Date  : Jun. 18 2025
// ----------------------- //

TH1D* make_hist(TString filename = "data1"){

    //gROOT->SetStyle("ATLAS");
	const int MCACh = 8192;
	const double HistMin = 0.;
	const double HistMax = 8192.;

	TH1D* hist = new TH1D(filename, filename , MCACh, HistMin-0.5, HistMax-0.5);

    const TString data_dir = "../data/";
	double BufferValue;
	ifstream ifs(data_dir + filename + ".txt");
	while(ifs >> BufferValue){
		hist->Fill(BufferValue);
	}

    hist->Rebin(16);
	hist->SetTitle(";ADC channel;Counts/16ch");
	//hist->Draw();
	return hist;
}

TF1* fitting_gaus(){

    TH1D* hist2 = make_hist("data2");
    hist2->Draw();

    const double range_min = 5000.;
    const double range_max = 8000.;
    auto func = new TF1("func", "gaus(0)", range_min, range_max);
    // Set initial parameter values
    func->SetParameter(0, 100);
    func->SetParameter(1, 6000);
    func->SetParameter(2, 200);

    hist2->Fit("func", "", "", range_min, range_max);

    return func;
}
