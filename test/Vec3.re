open Reglm;

open Rejest;

open Helpers;

test("vec3", () => {
  test("zero()", () => {
    let v = Vec3.zero();
    let x = Vec3.get_x(v);
    let y = Vec3.get_y(v);
    let z = Vec3.get_z(v);
    assertFloatsEqual(x, 0.0);
    assertFloatsEqual(y, 0.0);
    assertFloatsEqual(z, 0.0);
  });

  test("create()", () => {
    let v = Vec3.create(10., 11., 12.);
    let x = Vec3.get_x(v);
    let y = Vec3.get_y(v);
    let z = Vec3.get_z(v);
    assertFloatsEqual(x, 10.0);
    assertFloatsEqual(y, 11.0);
    assertFloatsEqual(z, 12.0);
  });
});
