module Angle = Reglm.Angle;

open TestFramework;

describe("Angle", ({test, _}) => {
  test("Degree -> radians", ({expect, _}) => {
    let degree = Angle.from_degrees(1.0);
    let radians = Angle.to_radians(degree);

    expect.float(radians).toBeCloseTo(0.0174532925);
  });

  test("Radians -> degrees", ({expect, _}) => {
    let radians = Angle.from_radians(0.0174532925);
    let degrees = Angle.to_degrees(radians);

    expect.float(degrees).toBeCloseTo(1.);
  });
});
