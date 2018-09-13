open Reglm

let () =
    let m = Regml.mat4_create () in
    let _ = Regml.mat4_debug_print m in
    print_endline ("done!");
