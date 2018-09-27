open Reglm;

/*MAT4*/


let assertFloatsEqual = (expected, actual) => {
    let equal = abs_float(expected -. actual) < min_float;
    assert(equal);
};

let assertMat4 = (expected, actual) => {
    for (i in 0 to 15) {
        let expectedValue = expected[i];
        let actualValue = Mat4.get(actual, i);
        assertFloatsEqual(expectedValue, actualValue);
    };
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
    let vTranslation = Vec3.create();
    Vec3.set(vTranslation, 2., 2., 2.);
    let mTranslation = Mat4.create();
    Mat4.fromTranslation(mTranslation, vTranslation);

    let vScale = Vec3.create();
    Vec3.set(vScale, 3., 4., 5.);
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

/* lookAt */
let () = {
    let vEye = Vec3.create();
    let vCenter = Vec3.create();
    let vUp = Vec3.create();

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
