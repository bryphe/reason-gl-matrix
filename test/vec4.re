open Reglm;

let () = {
    let v = Vec4.zero();

    let x = Vec4.get_x(v);
    let y = Vec4.get_y(v);
    let z = Vec4.get_z(v);
    let w = Vec4.get_w(v);

    assert(x == 0.);
    assert(y == 0.);
    assert(z == 0.);
    assert(w == 0.);
};

let () = {
    let v = Vec4.create(1., 2., 3., 4.);
    let x = Vec4.get_x(v);
    let y = Vec4.get_y(v);
    let z = Vec4.get_z(v);
    let w = Vec4.get_w(v);

    assert(x == 1.);
    assert(y == 2.);
    assert(z == 3.);
    assert(w == 4.);
};
