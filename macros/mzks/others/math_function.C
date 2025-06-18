// ------------------------------ //
// others/math_function.C
// to explain a usage of TF1
// ------------------------------ //


int math_function(){

    const double range_min = 0.;
    const double range_max = 10.;

    auto func1 = new TF1("func1", // function name
                         "2*x-1", // function format
                        range_min, range_max);

    func1->Draw();


    return 0;
}
