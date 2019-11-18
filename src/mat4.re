type t;

type radians = float;

external create: unit => t = "caml_mat4_create";
external get: (t, int) => float = "caml_mat4_get";

[@noalloc] external identity: t => unit = "caml_mat4_identity";

[@noalloc] external multiply: (t, t, t) => unit = "caml_mat4_multiply";

[@noalloc] external _rotate: (t, radians, Vec3.t) => unit = "caml_mat4_rotate";

let rotate = (mat: t, ang: Angle.t, vec: Vec3.t) => {
  let a = Angle.to_radians(ang);
  _rotate(mat, a, vec);
};

[@noalloc]
external transformVec3: (Vec3.t, Vec3.t, t) => unit =
  "caml_mat4_transform_vec3";

[@noalloc]
external fromTranslation: (t, Vec3.t) => unit = "caml_mat4_fromTranslation";
[@noalloc] external fromScaling: (t, Vec3.t) => unit = "caml_mat4_fromScaling";

[@noalloc]
external lookAt: (t, Vec3.t, Vec3.t, Vec3.t) => unit = "caml_mat4_lookat";

[@noalloc]
external ortho: (t, float, float, float, float, float, float) => unit =
  "caml_mat4_ortho_bytecode" "caml_mat4_ortho_native";
[@noalloc]
external perspective: (t, radians, float, float, float) => unit =
  "caml_mat4_perspective";

external createFromTranslationAndScale:
  (
    [@unboxed] float,
    [@unboxed] float,
    [@unboxed] float,
    [@unboxed] float,
    [@unboxed] float,
    [@unboxed] float
  ) =>
  t =
  "caml_mat4_createFromTranslationAndScale_byte"
  "caml_mat4_createFromTranslationAndScale";

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

let toString = mat => {
  let str = ref("");
  for (i in 0 to 15) {
    let v = get(mat, i);
    str :=
      str^
      ++ "\nIndex: "
      ++ string_of_int(i)
      ++ " Value: "
      ++ string_of_float(v);
  };
  str^;
};
