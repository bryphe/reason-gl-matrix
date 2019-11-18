open Reglm;
open TestFramework;

describe("Vec2", ({test, _}) => {
  test("zero()", ({expect, _}) => {
    let v = Vec2.zero();

    let x = Vec2.get_x(v);
    let y = Vec2.get_y(v);

    expect.float(x).toBeCloseTo(0.);
    expect.float(y).toBeCloseTo(0.);
  });

  test("create()", ({expect, _}) => {
    let v = Vec2.create(1., 2.);

    let x = Vec2.get_x(v);
    let y = Vec2.get_y(v);

    expect.float(x).toBeCloseTo(1.);
    expect.float(y).toBeCloseTo(2.);
  });
});
