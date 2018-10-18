type t;
external create_internal: unit => t = "caml_vec2_create";

let zero = () => create_internal();

external set: (t, float, float) => unit = "caml_vec2_set";

/* We can reuse the vec3 operations for x,y,z! */
external get_x: t => float = "caml_vec3_get_x";
external get_y: t => float = "caml_vec3_get_y";

let create = (x, y) => {
    let vec = create_internal();
    set(vec, x, y);
    vec
};
