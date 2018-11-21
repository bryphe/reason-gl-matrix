module Angle = Reglm.Angle;

open Rejest;

test("Angle", () => {
  test("Degree -> radians", () => {
    let degree = Angle.from_degrees(1.0);
    let radians = Angle.to_radians(degree);

    Helpers.assertFloatsEqual(radians, 0.0174532925);
  });

  test("Radians -> degrees", () => {
    let radians = Angle.from_radians(0.0174532925);
    let degrees = Angle.to_degrees(radians);

    Helpers.assertFloatsEqual(degrees, 1.);
  });
});
