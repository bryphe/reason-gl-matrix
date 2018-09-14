external print_hello: unit -> unit = "caml_print_hello"

type mat4
external mat4_create: unit -> mat4 = "caml_mat4_create"
external mat4_debug_print: mat4 -> float = "caml_mat4_debug_print"
external mat4_get: mat4 -> int -> float = "caml_mat4_get"
