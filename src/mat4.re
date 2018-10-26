type t;

type radians = float;

external create: unit => t = "caml_mat4_create";
external get: (t, int) => float = "caml_mat4_get";

[@noalloc] external identity: t => unit = "caml_mat4_identity";

external multiply: (t, t, t) => unit = "caml_mat4_multiply";

external _rotate: (t, radians, Vec3.t) => unit = "caml_mat4_rotate";

let rotate = (mat: t, ang: Angle.t, vec: Vec3.t) => {
    let a = Angle.to_radians(ang);
    _rotate(mat, a, vec);
};

[@noalloc] external transformVec3: (Vec3.t, Vec3.t, t) => unit = "caml_mat4_transform_vec3";

external fromTranslation: (t, Vec3.t) => unit = "caml_mat4_fromTranslation";
external fromScaling: (t, Vec3.t) => unit = "caml_mat4_fromScaling";

external lookAt: (t, Vec3.t, Vec3.t, Vec3.t) => unit = "caml_mat4_lookat";

external ortho: (t, float, float, float, float, float, float) => unit = "caml_mat4_ortho_bytecode" "caml_mat4_ortho_native";
external perspective: (t, radians, float, float, float) => unit = "caml_mat4_perspective";

let fromRotation = (mat: t, ang: Angle.t, vec: Vec3.t) => {
    identity(mat);
    rotate(mat, ang, vec);
};

let _right = Vec3.right();
let _up = Vec3.up();
let _forward = Vec3.forward();

let rotateX = (mat: t, ang: Angle.t) => {
    rotate(mat, ang, _right);
};

let rotateY = (mat: t, ang: Angle.t) => {
    rotate(mat, ang, _up);
};

let rotateZ = (mat: t, ang: Angle.t) => {
    rotate(mat, ang, _forward);
};
