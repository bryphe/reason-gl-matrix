open Reglm;
open TestFramework;

describe("Vec3", ({test, _}) => {
  test("zero()", ({expect, _}) => {
    let v = Vec3.zero();

    let x = Vec3.get_x(v);
    let y = Vec3.get_y(v);
    let z = Vec3.get_z(v);

    expect.float(x).toBeCloseTo(0.0);
    expect.float(y).toBeCloseTo(0.0);
    expect.float(z).toBeCloseTo(0.0);
  });

  test("create()", ({expect, _}) => {
    let v = Vec3.create(10., 11., 12.);

    let x = Vec3.get_x(v);
    let y = Vec3.get_y(v);
    let z = Vec3.get_z(v);

    expect.float(x).toBeCloseTo(10.0);
    expect.float(y).toBeCloseTo(11.0);
    expect.float(z).toBeCloseTo(12.0);
  });
});
