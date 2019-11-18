open Reglm;

open TestFramework;

describe("Quat", ({test, _}) =>
  test("create", ({expect, _}) => {
    let q = Quat.create(0., 1., 2., 3.);

    let x = Quat.get_x(q);
    let y = Quat.get_y(q);
    let z = Quat.get_z(q);
    let w = Quat.get_w(q);

    expect.float(x).toBeCloseTo(0.);
    expect.float(y).toBeCloseTo(1.);
    expect.float(z).toBeCloseTo(2.);
    expect.float(w).toBeCloseTo(3.);
  })
);
