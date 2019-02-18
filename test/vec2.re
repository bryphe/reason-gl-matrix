open Reglm;

let () = {
  let v = Vec2.zero();

  let x = Vec2.get_x(v);
  let y = Vec2.get_y(v);

  Helpers.assertFloatsEqual(0., x);
  Helpers.assertFloatsEqual(0., y);
};

let () = {
  let v = Vec2.create(1., 2.);
  let x = Vec2.get_x(v);
  let y = Vec2.get_y(v);

  Helpers.assertFloatsEqual(1., x);
  Helpers.assertFloatsEqual(2., y);
};
