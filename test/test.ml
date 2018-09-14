open Reglm

(* simple test for identity matrix *)
let () =
    let m = Mat4.mat4_create () in
    let m00 = (Mat4.mat4_get m 0) in
    let m11 = (Mat4.mat4_get m 5) in
    let m22 = (Mat4.mat4_get m 10) in
    let m33 = (Mat4.mat4_get m 15) in
    assert (m00 = 1.);
    assert (m11 = 1.);
    assert (m22 = 1.);
    assert (m33 = 1.);
