open Reglm;

let () = {
    let degree = Angle.degrees_of_float(1.0);
    let radians = Angle.to_radians(degree);

    assert(radians == 0.01745);
};

let () = {
    let radians = Angle.radians_of_float(0.01745);
    let degrees = Angle.to_degrees(radians);

    assert(degrees == 1.);
};
