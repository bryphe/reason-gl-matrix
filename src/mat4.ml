type mat4

external create: unit -> mat4 = "caml_mat4_create"
external get: mat4 -> int -> float = "caml_mat4_get"

external debug_print: mat4 -> float = "caml_mat4_debug_print"
