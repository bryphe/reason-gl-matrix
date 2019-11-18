type t;

external create:
  ([@unboxed] float, [@unboxed] float, [@unboxed] float, [@unboxed] float) => t =
  "caml_quat_create_byte" "caml_quat_create";

let zero = () => {
  create(0., 0., 0., 0.);
};

let identity = () => {
  create(0., 0., 0., 1.);
};

external get_x: t => float = "caml_quat_get_x";
external get_y: t => float = "caml_quat_get_y";
external get_z: t => float = "caml_quat_get_z";
external get_w: t => float = "caml_quat_get_w";
