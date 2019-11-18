let pi = 4.0 *. atan(1.0);

type t =
  | Degrees(float)
  | Radians(float);

let from_radians = (x: float) => Radians(x);
let from_degrees = (x: float) => Degrees(x);

let to_radians = (angle: t) => {
  switch (angle) {
  | Degrees(x) => x *. pi /. 180.
  | Radians(x) => x
  };
};

let to_degrees = (angle: t) => {
  switch (angle) {
  | Degrees(x) => x
  | Radians(x) => x *. 180. /. pi
  };
};

let cos = (angle: t) => {
  cos(to_radians(angle));
};

let sin = (angle: t) => {
  sin(to_radians(angle));
};
