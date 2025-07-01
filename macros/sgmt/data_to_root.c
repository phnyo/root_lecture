void data_to_root()
{
    // 入力ファイル名
    const char* infile = "data/sim_shower_events.root";
    const char* outfile = "sim_shower_events_gamma.root";

    // 入力ROOTファイル 
    TFile* file_in = TFile::Open(infile);
    auto in_tree = dynamic_cast<TTree*>(file_in->Get("shower"));

    // 出力ROOTファイル
    TFile* file_out = new TFile(outfile, "RECREATE");
    TTree* tree = new TTree("shower", "Simulated Shower Events");

    // 変数定義
    float zenith, azimuth;
    int num_particle, num_muon;

    in_tree->SetBranchAddress("zenith", &zenith);
    in_tree->SetBranchAddress("azimuth", &azimuth);
    in_tree->SetBranchAddress("num_particle", &num_particle);
    in_tree->SetBranchAddress("num_muon", &num_muon);
    
    tree->Branch("zenith", &zenith, "zenith/F");
    tree->Branch("azimuth", &azimuth, "azimuth/F");
    tree->Branch("num_particle", &num_particle, "num_particle/I");
    tree->Branch("num_muon", &num_muon, "num_muon/I");


    // ファイルを開く
    long long entries = in_tree->GetEntries();
    
    for (int i = 0; i < entries; i++) {
        in_tree->GetEntry(i);
        if (num_muon < 20) {
          tree->Fill();
        }
    }

    tree->Write();
    file_out->Close();
}
