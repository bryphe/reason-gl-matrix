open Reglm;

open Rejest;

test("Quat", () =>
  test("create", () => {
    let q = Quat.create(0., 1., 2., 3.);

    let x = Quat.get_x(q);
    let y = Quat.get_y(q);
    let z = Quat.get_z(q);
    let w = Quat.get_w(q);

    expect(x).toEqual(0.);
    expect(y).toEqual(1.);
    expect(z).toEqual(2.);
    expect(w).toEqual(3.);
  })
);
