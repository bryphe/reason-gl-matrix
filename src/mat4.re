type t;

type radians = float;

external create: unit => t = "caml_mat4_create";
external get: (t, int) => float = "caml_mat4_get";

external multiply: (t, t, t) => unit = "caml_mat4_multiply";

external rotate: (t, radians, Vec3.t) => unit = "caml_mat4_rotate";

external fromTranslation: (t, Vec3.t) => unit = "caml_mat4_fromTranslation";
external fromScaling: (t, Vec3.t) => unit = "caml_mat4_fromScaling";

external lookAt: (t, Vec3.t, Vec3.t, Vec3.t) => unit = "caml_mat4_lookat";

external ortho: (t, float, float, float, float, float, float) => unit = "caml_mat4_ortho_bytecode" "caml_mat4_ortho_native";
external perspective: (t, radians, float, float, float) => unit = "caml_mat4_perspective";

