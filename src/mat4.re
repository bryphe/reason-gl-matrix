type t;

external create: unit => t = "caml_mat4_create";
external get: (t, int) => float = "caml_mat4_get";

external multiply: (t, t, t) => unit = "caml_mat4_multiply";

external fromTranslation: (t, Vec3.t) => unit = "caml_mat4_fromTranslation";
external fromScaling: (t, Vec3.t) => unit = "caml_mat4_fromScaling";
