open Reglm

(* simple test for identity matrix *)
let () =
    let m = Regml.mat4_create () in
    let m00 = (Regml.mat4_get m 0) in
    let m11 = (Regml.mat4_get m 5) in
    let m22 = (Regml.mat4_get m 10) in
    let m33 = (Regml.mat4_get m 15) in
    assert (m00 = 1.);
    assert (m11 = 1.);
    assert (m22 = 0.);
    assert (m33 = 1.);
