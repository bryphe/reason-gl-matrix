open Reglm;
open Rejest;

test("Vec4", () => {
  test("zero()", () => {
    let v = Vec4.zero();

    let x = Vec4.get_x(v);
    let y = Vec4.get_y(v);
    let z = Vec4.get_z(v);
    let w = Vec4.get_w(v);

    expect(x).toEqual(0.);
    expect(y).toEqual(0.);
    expect(z).toEqual(0.);
    expect(w).toEqual(0.);
  });

  test("create()", () => {
    let v = Vec4.create(1., 2., 3., 4.);
    let x = Vec4.get_x(v);
    let y = Vec4.get_y(v);
    let z = Vec4.get_z(v);
    let w = Vec4.get_w(v);

    expect(x).toEqual(1.);
    expect(y).toEqual(2.);
    expect(z).toEqual(3.);
    expect(w).toEqual(4.);
  });
});
