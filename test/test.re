open Reglm;

/*MAT4*/

/* simple test for identity matrix */
let () = {
  let m = Mat4.create();
  let m00 = Mat4.get(m, 0);
  let m11 = Mat4.get(m, 5);
  let m22 = Mat4.get(m, 10);
  let m33 = Mat4.get(m, 15);
  assert(m00 == 1.);
  assert(m11 == 1.);
  assert(m22 == 1.);
  assert(m33 == 1.);
};

/*VEC3*/
let () = {
  let v = Vec3.create();
  let x = Vec3.get_x(v);
  let y = Vec3.get_y(v);
  let z = Vec3.get_z(v);
  assert(x == 0.0);
  assert(y == 0.0);
  assert(z == 0.0);
};

/*set / get test*/
let () = {
  let v = Vec3.create();
  let _ = Vec3.set(v, 10., 11., 12.);
  let x = Vec3.get_x(v);
  let y = Vec3.get_y(v);
  let z = Vec3.get_z(v);
  assert(x == 10.0);
  assert(y == 11.0);
  assert(z == 12.0);
};
