type t;
external create_internal: unit => t = "caml_vec4_create";

let zero = () => create_internal();

[@noalloc] external set: (t, float, float, float, float) => unit = "caml_vec4_set";

/* We can reuse the vec3 operations for x,y,z! */
external get_x: t => float = "caml_vec3_get_x";
external get_y: t => float = "caml_vec3_get_y";
external get_z: t => float = "caml_vec3_get_z";

external get_w: t => float = "caml_vec4_get_w";

let create = (x, y, z, w) => {
    let vec = create_internal();
    set(vec, x, y, z, w);
    vec
};
