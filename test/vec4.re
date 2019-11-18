open Reglm;
open TestFramework;

describe("Vec4", ({test, _}) => {
  test("zero()", ({expect, _}) => {
    let v = Vec4.zero();

    let x = Vec4.get_x(v);
    let y = Vec4.get_y(v);
    let z = Vec4.get_z(v);
    let w = Vec4.get_w(v);

    expect.float(x).toBeCloseTo(0.);
    expect.float(y).toBeCloseTo(0.);
    expect.float(z).toBeCloseTo(0.);
    expect.float(w).toBeCloseTo(0.);
  });

  test("create()", ({expect, _}) => {
    let v = Vec4.create(1., 2., 3., 4.);

    let x = Vec4.get_x(v);
    let y = Vec4.get_y(v);
    let z = Vec4.get_z(v);
    let w = Vec4.get_w(v);

    expect.float(x).toBeCloseTo(1.);
    expect.float(y).toBeCloseTo(2.);
    expect.float(z).toBeCloseTo(3.);
    expect.float(w).toBeCloseTo(4.);
  });
});
