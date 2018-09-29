open Reglm;

let () = {
    let q = Quat.create(0., 1., 2., 3.);

    let x = Quat.get_x(q);
    let y = Quat.get_y(q);
    let z = Quat.get_z(q);
    let w = Quat.get_w(q);

    assert(x == 0.);
    assert(y == 1.);
    assert(z == 2.);
    assert(w == 3.);
};
