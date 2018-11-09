open Reglm;

module Angle = Reglm.Angle;

/*MAT4*/
let assertMat4 = (expected, actual) => {
    for (i in 0 to 15) {
        let expectedValue = expected[i];
        let actualValue = Mat4.get(actual, i);
        Helpers.assertFloatsEqual(expectedValue, actualValue);
    };
};

let assertVec3 = (expected, actual) => {
    let expectedX = Vec3.get_x(expected);
    let expectedY = Vec3.get_y(expected);
    let expectedZ = Vec3.get_z(expected);

    let actualX = Vec3.get_x(actual);
    let actualY = Vec3.get_y(actual);
    let actualZ = Vec3.get_z(actual);

    Helpers.assertFloatsEqual(expectedX, actualX);
    Helpers.assertFloatsEqual(expectedY, actualY);
    Helpers.assertFloatsEqual(expectedZ, actualZ);
};

/* simple test for identity matrix */
let () = {
    let expectedMatrix = [|
    1., 0., 0., 0.,
    0., 1., 0., 0.,
    0., 0., 1.0, 0.,
    0., 0., 0., 1.0
    |];

    assertMat4(expectedMatrix, Mat4.create());
};

/* multiply */
let () = {
    let vTranslation = Vec3.create(2., 2., 2.);
    let mTranslation = Mat4.create();
    Mat4.fromTranslation(mTranslation, vTranslation);

    let vScale = Vec3.create(3., 4., 5.);
    let mScale = Mat4.create();
    Mat4.fromScaling(mScale, vScale);

    let mResult = Mat4.create();
    Mat4.multiply(mResult, mScale, mTranslation);

    let m03 = Mat4.get(mResult, 12);
    let m13 = Mat4.get(mResult, 13);
    let m14 = Mat4.get(mResult, 14);
    let m15 = Mat4.get(mResult, 15);
    assert(m03 == 6.);
    assert(m13 == 8.);
    assert(m14 == 10.);
    assert(m15 == 1.);
};

let pi = acos(-1.);

/* rotate */
let () = {
    let m = Mat4.create();
    let rad = Angle.from_radians(pi *. 0.5);
    let axis = Vec3.create(1., 0., 0.);

    Mat4.rotate(m, rad, axis);

    let expectedResult = [|
    1.0, 0., 0., 0.,
    0., Angle.cos(rad), Angle.sin(rad), 0.,
    0., -1. *. Angle.sin(rad), Angle.cos(rad), 0.,
    0., 0., 0., 1.
    |];

    assertMat4(expectedResult, m);
};

/* transformVec3 */
let () = {
    let m = Mat4.create();
    Mat4.fromRotation(m, Angle.from_radians(pi *. 0.5), Vec3.forward());
    let v = Vec3.up();
    Mat4.transformVec3(v, v, m);

    print_endline ("X: " ++ string_of_float(Vec3.get_x(v)));
    print_endline ("Y: " ++ string_of_float(Vec3.get_y(v)));
    print_endline ("Z: " ++ string_of_float(Vec3.get_z(v)));

    let expected = Vec3.left();
    assertVec3(expected, v);
};

/* lookAt */
let () = {
    let vEye = Vec3.zero();
    let vCenter = Vec3.zero();
    let vUp = Vec3.zero();

    Vec3.set(vEye, 0., 0., 1.);
    Vec3.set(vCenter, 0., 0., -1.);
    Vec3.set(vUp, 0., 1., 0.);

    let mResult = Mat4.create();
    Mat4.lookAt(mResult, vEye, vCenter, vUp);

    let expectedMatrix = [|
    1., 0., 0., 0.,
    0., 1., 0., 0.,
    0., 0., 1.0, 0.,
    0., 0., -1.0, 1.0
    |];

    assertMat4(expectedMatrix, mResult);
};

/* perspective */
/* Test case from: https://github.com/toji/gl-matrix/blob/master/spec/gl-matrix/mat4-spec.js */
let () = {
    let mResult = Mat4.create();
    Mat4.perspective(mResult, 45. *. pi /. 180., 640. /. 480., 0.1, 200.);

    let expectedMatrix = [|
    1.81066, 0., 0., 0.,
    0., 2.414213, 0., 0.,
    0., 0., -1.001, -1.,
    0., 0., -0.2001, 0.
    |];

    assertMat4(expectedMatrix, mResult);
};

/* ortho */
/* Test case from: https://github.com/toji/gl-matrix/blob/master/spec/gl-matrix/mat4-spec.js */
let () = {
    let mResult = Mat4.create();
    Mat4.ortho(mResult, -1., 1., -1., 1., -1., 1.);

    let expectedMatrix = [|
        1., 0., 0., 0.,
        0., 1., 0., 0.,
        0., 0., -1., 0.,
        0., 0., 0., 1.
    |];

    assertMat4(expectedMatrix, mResult);
};

/*VEC3*/
let () = {
  let v = Vec3.zero();
  let x = Vec3.get_x(v);
  let y = Vec3.get_y(v);
  let z = Vec3.get_z(v);
  assert(x == 0.0);
  assert(y == 0.0);
  assert(z == 0.0);
};

/*set / get test*/
let () = {
  let v = Vec3.create(10., 11., 12.);
  let x = Vec3.get_x(v);
  let y = Vec3.get_y(v);
  let z = Vec3.get_z(v);
  assert(x == 10.0);
  assert(y == 11.0);
  assert(z == 12.0);
};
