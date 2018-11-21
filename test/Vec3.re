open Reglm;

open Rejest;

test("vec3", () => {
  test("zero()", () => {
    let v = Vec3.zero();
    let x = Vec3.get_x(v);
    let y = Vec3.get_y(v);
    let z = Vec3.get_z(v);
    assert(x == 0.0);
    assert(y == 0.0);
    assert(z == 0.0);
  });

  test("create()", () => {
    let v = Vec3.create(10., 11., 12.);
    let x = Vec3.get_x(v);
    let y = Vec3.get_y(v);
    let z = Vec3.get_z(v);
    assert(x == 10.0);
    assert(y == 11.0);
    assert(z == 12.0);
  });
});
