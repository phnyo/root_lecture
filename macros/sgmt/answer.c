TH2D * read_data(TString filename="data/sim_shower_events.root", TString filename2="data/sim_shower_events_gamma.root") {

  auto file = TFile::Open(filename);
  auto file2 = TFile::Open(filename2);
  auto tree = dynamic_cast<TTree*>(file->Get("shower"));
  auto tree2 = dynamic_cast<TTree*>(file2->Get("shower"));

  float zenith, azimuth;
  int num_particle, num_muon;

  tree->SetBranchAddress("zenith", &zenith);
  tree->SetBranchAddress("azimuth", &azimuth);
  tree->SetBranchAddress("num_particle", &num_particle);
  tree->SetBranchAddress("num_muon", &num_muon);

  tree2->SetBranchAddress("zenith", &zenith);
  tree2->SetBranchAddress("azimuth", &azimuth);
  tree2->SetBranchAddress("num_particle", &num_particle);
  tree2->SetBranchAddress("num_muon", &num_muon);

  long long entries = tree->GetEntries();

  const int nbin = 100;
  const int muon_val_min = 0;
  const int muon_val_max = 200;
  const int ptcl_val_min = 0;
  const int ptcl_val_max = 1000;
  
  auto hist = new TH2D("hist", "hist", nbin, muon_val_min, muon_val_max, nbin, ptcl_val_min, ptcl_val_max);
  hist->SetTitle(";;");

  for (int i = 0; i < entries; i++) {
    tree->GetEntry(i);
    hist->Fill(num_muon, num_particle);
  }

  entries = tree2->GetEntries();
  for (int i = 0; i < entries; i++) {
    tree2->GetEntry(i);
    hist->Fill(num_muon, num_particle);
  }

  return hist;
}

TH2D * read_zenith_azimuth(TString filename="data/sim_shower_events.root", TString filename2="data/sim_shower_events_gamma.root") {

  auto file = TFile::Open(filename);
  auto file2 = TFile::Open(filename2);
  auto tree = dynamic_cast<TTree*>(file->Get("shower"));
  auto tree2 = dynamic_cast<TTree*>(file2->Get("shower"));

  float zenith, azimuth;
  int num_particle, num_muon;

  tree->SetBranchAddress("zenith", &zenith);
  tree->SetBranchAddress("azimuth", &azimuth);
  tree->SetBranchAddress("num_particle", &num_particle);
  tree->SetBranchAddress("num_muon", &num_muon);

  tree2->SetBranchAddress("zenith", &zenith);
  tree2->SetBranchAddress("azimuth", &azimuth);
  tree2->SetBranchAddress("num_particle", &num_particle);
  tree2->SetBranchAddress("num_muon", &num_muon);

  long long entries = tree->GetEntries();

  const int nbin = 50;
  const int azim_val_min = 0;
  const double azim_val_max = 2. * M_PI;
  const int zenith_val_min = 0;
  const double zenith_val_max = M_PI / 2.0;
  
  auto hist = new TH2D("hist", "hist", nbin, azim_val_min, azim_val_max, nbin, zenith_val_min, zenith_val_max);
  hist->SetTitle(";;");

  for (int i = 0; i < entries; i++) {
    tree->GetEntry(i);
    if (num_muon < 10) {
      hist->Fill(azimuth, zenith);
    }
  }

  entries = tree2->GetEntries();
  for (int i = 0; i < entries; i++) {
    tree2->GetEntry(i);
    if (num_muon < 10) {
      hist->Fill(azimuth, zenith);
    }
  }
  
  double ave = 0;
  double d_max = 0;

  /*for (int i = 0; i < nbin; i++) {
    for (int j = 0; j < nbin; j++) {
      d_max = max(d_max, hist->GetBinContent(i, j));
      ave += hist->GetBinContent(i, j);
    }
  }
  ave /= nbin * nbin;

  cout << "significance" << d_max / sqrt(d_max + ave) << "\n";*/
    
  return hist;
}

void answer() {

  auto hist2d = read_data("data/sim_shower_events.root", "data/sim_shower_events_gamma.root");
  //hist2d->Draw("COLZ");

  auto cuthist2d = read_zenith_azimuth("data/sim_shower_events.root", "data/sim_shower_events_gamma.root");
  cuthist2d->Draw("COLZ");
}
