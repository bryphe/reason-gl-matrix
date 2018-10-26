let pi = 4.0 *. atan(1.0);

type t =
| Degrees(float)
| Radians(float)

let radians_of_float = (x: float) => Radians(x);
let degrees_of_float = (x: float) => Degrees(x);

let to_radians = (angle: t) => {
    switch(angle) {
    | Degrees(x) => x *. pi /. 180.
    | Radians(x) => x
    };
};

let to_degrees = (angle: t) => {
    switch (angle) {
    | Degrees(x) => x;
    | Radians(x) => x *. 180. /. pi
    };
};
