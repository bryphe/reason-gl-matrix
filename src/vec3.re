type t;
external create_internal: unit => t = "caml_vec3_create";

[@noalloc] external set: (t, float, float, float) => unit = "caml_vec3_set";
external get_x: t => float = "caml_vec3_get_x";
external get_y: t => float = "caml_vec3_get_y";
external get_z: t => float = "caml_vec3_get_z";

external debug_print: t => float = "caml_vec3_debug_print";

let create = (x, y, z) => {
    let vec = create_internal();
    set(vec, x, y, z);
    vec
};

let zero = () => create_internal();
let back = () => create(0., 0., -1.);
let down = () => create(0., -1., 0.);
let forward = () => create(0., 0., 1.0);
let left = () => create(-1., 0., 0.);
let right = () => create(1., 0., 0.);
let up = () => create(0., 1., 0.);
