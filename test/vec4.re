open Reglm;
open Rejest;

open Helpers;

test("Vec4", () => {
  test("zero()", () => {
    let v = Vec4.zero();

    let x = Vec4.get_x(v);
    let y = Vec4.get_y(v);
    let z = Vec4.get_z(v);
    let w = Vec4.get_w(v);

    assertFloatsEqual(x, 0.);
    assertFloatsEqual(y, 0.);
    assertFloatsEqual(z, 0.);
    assertFloatsEqual(w, 0.);
  });

  test("create()", () => {
    let v = Vec4.create(1., 2., 3., 4.);
    let x = Vec4.get_x(v);
    let y = Vec4.get_y(v);
    let z = Vec4.get_z(v);
    let w = Vec4.get_w(v);

    assertFloatsEqual(x, 1.);
    assertFloatsEqual(y, 2.);
    assertFloatsEqual(z, 3.);
    assertFloatsEqual(w, 4.);
  });
});
