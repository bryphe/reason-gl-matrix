type vec3
external create: unit -> vec3 = "caml_vec3_create"
external set: vec3 -> float -> float -> float -> unit = "caml_vec3_set"
external get_x: vec3 -> float = "caml_vec3_get_x"
external get_y: vec3 -> float = "caml_vec3_get_y"
external get_z: vec3 -> float = "caml_vec3_get_z"

external debug_print: vec3 -> float = "caml_vec3_debug_print"
