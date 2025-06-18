// ---------------------------- //
// draw_graph.C
// initial example to draw
// TGraph
// ---------------------------- //

int draw_graph(){
    gROOT->SetStyle("ATLAS");

    // Case 1
    int n1 = 4;
    double x1[] = {1,2,3,4};
    double y1[] = {1,4,9,16};
    TGraph* graph1 = new TGraph(n1, x1, y1);

    // Case 2
    std::vector<double> x2 = {1,2,3,4};
    std::vector<double> y2 = {16,9,4,1};
    TGraph* graph2 = new TGraph(x2.size(), x2.data(), y2.data());

    // Case 3
    TGraph* graph3 = new TGraph();
    for(int i=0; i<4; ++i){
        graph3->AddPoint(i, i*2);
    }

    graph1->Draw("AP");
    graph2->SetMarkerColor(kRed);
    graph2->Draw("P");
    graph3->SetMarkerColor(kBlue);
    graph3->Draw("P");

    return 0;
}
