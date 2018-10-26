type t;

type radians = float;

let create: unit => t;
let get: (t, int) => float;

let multiply: (t, t, t) => unit;

let rotate: (t, radians, Vec3.t) => unit;

let fromTranslation: (t, Vec3.t) => unit;
let fromScaling: (t, Vec3.t) => unit;

/* let fromRotation: (t, Angle.t, Vec3.t) => unit; */
/* let fromXRotation: (t, Angle.t) => unit; */
/* let fromYRotation: (t, Angle.t) => unit; */
/* let fromZRotation: (t, Angle.t) => unit; */

let lookAt: (t, Vec3.t, Vec3.t, Vec3.t) => unit;

let ortho: (t, float, float, float, float, float, float) => unit;
let perspective: (t, radians, float, float, float) => unit;

