open Reglm;

let () = {
  let v = Vec2.zero();

  let x = Vec2.get_x(v);
  let y = Vec2.get_y(v);

  assert(x == 0.);
  assert(y == 0.);
};

let () = {
  let v = Vec2.create(1., 2.);
  let x = Vec2.get_x(v);
  let y = Vec2.get_y(v);

  assert(x == 1.);
  assert(y == 2.);
};
