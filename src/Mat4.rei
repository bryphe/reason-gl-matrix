type t;

type radians = float;

let create: unit => t;
let get: (t, int) => float;
let identity: t => unit;

let multiply: (t, t, t) => unit;

let fromTranslation: (t, Vec3.t) => unit;
let fromScaling: (t, Vec3.t) => unit;
let fromRotation: (t, Angle.t, Vec3.t) => unit;

let rotate: (t, Angle.t, Vec3.t) => unit;
let rotateX: (t, Angle.t) => unit;
let rotateY: (t, Angle.t) => unit;
let rotateZ: (t, Angle.t) => unit;

let lookAt: (t, Vec3.t, Vec3.t, Vec3.t) => unit;

let ortho: (t, float, float, float, float, float, float) => unit;
let perspective: (t, radians, float, float, float) => unit;

let transformVec3: (Vec3.t, Vec3.t, t) => unit;
