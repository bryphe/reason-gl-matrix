open Reglm;
open TestFramework;

module Angle = Reglm.Angle;
let pi = Angle.pi;

/*MAT4*/
let assertMat4 = (expect, expected, actual) =>
  for (i in 0 to 15) {
    let expectedValue = expected[i];
    let actualValue = Mat4.get(actual, i);
    expect.float(expectedValue).toBeCloseTo(actualValue);
  };

let assertMats4 = (expect, expected, actual) =>
  for (i in 0 to 15) {
    let expectedValue = Mat4.get(expected, i);
    let actualValue = Mat4.get(actual, i);
    expect.float(expectedValue).toBeCloseTo(actualValue);
  };

let assertVec3 = (expect, expected, actual) => {
  let expectedX = Vec3.get_x(expected);
  let expectedY = Vec3.get_y(expected);
  let expectedZ = Vec3.get_z(expected);

  let actualX = Vec3.get_x(actual);
  let actualY = Vec3.get_y(actual);
  let actualZ = Vec3.get_z(actual);

  expect.float(expectedX).toBeCloseTo(actualX);
  expect.float(expectedY).toBeCloseTo(actualY);
  expect.float(expectedZ).toBeCloseTo(actualZ);
};

describe("Mat4", ({test, _}) => {
  /* simple test for identity matrix */
  test("identity", ({expect, _}) => {
    let expectedMatrix = [|
      1.,
      0.,
      0.,
      0.,
      0.,
      1.,
      0.,
      0.,
      0.,
      0.,
      1.0,
      0.,
      0.,
      0.,
      0.,
      1.0,
    |];

    assertMat4(expect, expectedMatrix, Mat4.create());
  });

  test("multiply", ({expect, _}) => {
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
    expect.float(m03).toBeCloseTo(6.);
    expect.float(m13).toBeCloseTo(8.);
    expect.float(m14).toBeCloseTo(10.);
    expect.float(m15).toBeCloseTo(1.);
  });

  test("rotate", ({expect, _}) => {
    let m = Mat4.create();
    let rad = Angle.from_radians(pi *. 0.5);
    let axis = Vec3.create(1., 0., 0.);

    Mat4.rotate(m, rad, axis);

    let expectedResult = [|
      1.0,
      0.,
      0.,
      0.,
      0.,
      Angle.cos(rad),
      Angle.sin(rad),
      0.,
      0.,
      (-1.) *. Angle.sin(rad),
      Angle.cos(rad),
      0.,
      0.,
      0.,
      0.,
      1.,
    |];

    assertMat4(expect, expectedResult, m);
  });

  test("createFromTranslationAndScale", ({expect, _}) => {
    let m = Mat4.createFromTranslationAndScale(2.0, 3.0, 4.0, 5.0, 6.0, 7.0);

    let scaleVec = Vec3.create(2.0, 3.0, 4.0);
    let scaleM = Mat4.create();
    Mat4.fromScaling(scaleM, scaleVec);

    let translateVec = Vec3.create(5., 6., 7.);
    let translateM = Mat4.create();
    Mat4.fromTranslation(translateM, translateVec);
    let expectedM = Mat4.create();
    Mat4.multiply(expectedM, translateM, scaleM);

    assertMats4(expect, expectedM, m);
    prerr_endline(Mat4.toString(m));
  });

  /* transformVec3 */
  test("transformVec3", ({expect, _}) => {
    let m = Mat4.create();
    Mat4.fromRotation(m, Angle.from_radians(pi *. 0.5), Vec3.forward());
    let v = Vec3.up();
    Mat4.transformVec3(v, v, m);

    print_endline("X: " ++ string_of_float(Vec3.get_x(v)));
    print_endline("Y: " ++ string_of_float(Vec3.get_y(v)));
    print_endline("Z: " ++ string_of_float(Vec3.get_z(v)));

    let expected = Vec3.left();
    assertVec3(expect, expected, v);
  });

  /* lookAt */
  test("lookAt", ({expect, _}) => {
    let vEye = Vec3.create(0., 0., 1.);
    let vCenter = Vec3.create(0., 0., -1.);
    let vUp = Vec3.create(0., 1., 0.);

    let mResult = Mat4.create();
    Mat4.lookAt(mResult, vEye, vCenter, vUp);

    let expectedMatrix = [|
      1.,
      0.,
      0.,
      0.,
      0.,
      1.,
      0.,
      0.,
      0.,
      0.,
      1.0,
      0.,
      0.,
      0.,
      (-1.0),
      1.0,
    |];

    assertMat4(expect, expectedMatrix, mResult);
  });

  /* perspective */
  /* Test case from: https://github.com/toji/gl-matrix/blob/master/spec/gl-matrix/mat4-spec.js */
  test("perspective", ({expect, _}) => {
    let mResult = Mat4.create();
    Mat4.perspective(mResult, 45. *. pi /. 180., 640. /. 480., 0.1, 200.);

    let expectedMatrix = [|
      1.81066,
      0.,
      0.,
      0.,
      0.,
      2.414213,
      0.,
      0.,
      0.,
      0.,
      (-1.001),
      (-1.),
      0.,
      0.,
      (-0.2001),
      0.,
    |];

    assertMat4(expect, expectedMatrix, mResult);
  });

  /* ortho */
  /* Test case from: https://github.com/toji/gl-matrix/blob/master/spec/gl-matrix/mat4-spec.js */
  test("ortho", ({expect, _}) => {
    let mResult = Mat4.create();
    Mat4.ortho(mResult, -1., 1., -1., 1., -1., 1.);

    let expectedMatrix = [|
      1.,
      0.,
      0.,
      0.,
      0.,
      1.,
      0.,
      0.,
      0.,
      0.,
      (-1.),
      0.,
      0.,
      0.,
      0.,
      1.,
    |];

    assertMat4(expect, expectedMatrix, mResult);
  });
});
