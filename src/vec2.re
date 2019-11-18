type t;
external create: ([@unboxed] float, [@unboxed] float) => t =
  "caml_vec2_create_byte" "caml_vec2_create";

let zero = () => create(0., 0.);

/* We can reuse the vec3 operations for x,y,z! */
external get_x: t => float = "caml_vec3_get_x";
external get_y: t => float = "caml_vec3_get_y";
