type t;

external create: ([@unboxed] float, [@unboxed] float, [@unboxed] float) => t =
  "caml_vec3_create_byte" "caml_vec3_create";
external get_x: t => float = "caml_vec3_get_x";
external get_y: t => float = "caml_vec3_get_y";
external get_z: t => float = "caml_vec3_get_z";

external debug_print: t => float = "caml_vec3_debug_print";

let zero = () => create(0., 0., 0.);
let back = () => create(0., 0., -1.);
let down = () => create(0., -1., 0.);
let forward = () => create(0., 0., 1.0);
let left = () => create(-1., 0., 0.);
let right = () => create(1., 0., 0.);
let up = () => create(0., 1., 0.);
